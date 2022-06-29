#include <stdbool.h>
#include <stdint.h>
#include "../mcc.h"
#include "../fatfs/diskio.h"
#include "../spi2.h"
#include "drva.h"

static volatile bool DiskInitialized = false;
static volatile bool DiskWP = false;
static volatile UINT Timer1, Timer2;
static UINT CardType;

// Private helper funcs

#define CMD0   (0)			/* GO_IDLE_STATE */
#define CMD1   (1)			/* SEND_OP_COND */
#define ACMD41 (41|0x80)	/* SEND_OP_COND (SDC) */
#define CMD8   (8)			/* SEND_IF_COND */
#define CMD9   (9)			/* SEND_CSD */
#define CMD10  (10)			/* SEND_CID */
#define CMD12  (12)			/* STOP_TRANSMISSION */
#define ACMD13 (13|0x80)	/* SD_STATUS (SDC) */
#define CMD16  (16)			/* SET_BLOCKLEN */
#define CMD17  (17)			/* READ_SINGLE_BLOCK */
#define CMD18  (18)			/* READ_MULTIPLE_BLOCK */
#define CMD23  (23)			/* SET_BLOCK_COUNT */
#define ACMD23 (23|0x80)	/* SET_WR_BLK_ERASE_COUNT (SDC) */
#define CMD24  (24)			/* WRITE_BLOCK */
#define CMD25  (25)			/* WRITE_MULTIPLE_BLOCK */
#define CMD41  (41)			/* SEND_OP_COND (ACMD) */
#define CMD55  (55)			/* APP_CMD */
#define CMD58  (58)			/* READ_OCR */

#define CT_MMC		0x01		/* MMC ver 3 */
#define CT_SD1		0x02		/* SD ver 1 */
#define CT_SD2		0x04		/* SD ver 2 */
#define CT_SDC		(CT_SD1|CT_SD2)	/* SD */
#define CT_BLOCK	0x08		/* Block addressing */

static int wait_ready (void)
{
	BYTE d;

	Timer2 = 500;	/* Wait for ready in timeout of 500ms */
	do {
		d = SPI2_ExchangeByte(0xFF);
	} while ((d != 0xFF) && Timer2);

	return (d == 0xFF) ? 1 : 0;
}

static void deselect (void)
{
	SCS2_SetHigh();            /* Set CS# high */
	SPI2_ExchangeByte(0xFF);   /* Dummy clock (force DO hi-z for multiple slave SPI) */
}

static int select (void)	/* 1:Successful, 0:Timeout */
{
	SCS2_SetLow();                  /* Set CS# low */
	SPI2_ExchangeByte(0xFF);		/* Dummy clock (force DO enabled) */

	if (wait_ready()) return 1;	    /* Wait for card ready */

	deselect();
	return 0;	/* Timeout */
}

/*-----------------------------------------------------------------------*/
/* Receive a data packet from MMC                                        */
/*-----------------------------------------------------------------------*/

static int rcvr_datablock (	/* 1:OK, 0:Failed */
	BYTE *buff,			    /* Data buffer to store received data */
	UINT btr			    /* Byte count (must be multiple of 4) */
)
{
	BYTE token;

	Timer1 = 100;
	do {							/* Wait for data packet in timeout of 100ms */
		token = SPI2_ExchangeByte(0xFF);
	} while ((token == 0xFF) && Timer1);

	if(token != 0xFE) return 0;		/* If not valid data token, return with error */

    SPI2_ReadBlock(buff, btr);
	SPI2_ExchangeByte(0xFF);					/* Discard CRC */
	SPI2_ExchangeByte(0xFF);

	return 1;						/* Return with success */
}

/*-----------------------------------------------------------------------*/
/* Send a data packet to MMC                                             */
/*-----------------------------------------------------------------------*/

static int xmit_datablock (	/* 1:OK, 0:Failed */
	const BYTE *buff,	/* 512 byte data block to be transmitted */
	BYTE token			/* Data token */
)
{
	BYTE resp;

	if (!wait_ready()) return 0;

	SPI2_ExchangeByte(token);		/* Xmit a token */
	if (token != 0xFD) {	/* Not StopTran token */
		SPI2_WriteBlock(buff, 512);	/* Xmit the data block to the MMC */
		SPI2_ExchangeByte(0xFF);				/* CRC (Dummy) */
		SPI2_ExchangeByte(0xFF);
		resp = SPI2_ExchangeByte(0xFF);		/* Receive a data response */
		if ((resp & 0x1F) != 0x05) return 0;	/* If not accepted, return with error */
	}

	return 1;
}

/*-----------------------------------------------------------------------*/
/* Send a command packet to MMC                                          */
/*-----------------------------------------------------------------------*/

static BYTE send_cmd_55 ()
{
	BYTE n, res;

	/* Select the card and wait for ready except to stop multiple block read */
    deselect();
    if (!select()) return 0xFF;

	/* Send command packet */
	SPI2_ExchangeByte(0x40 | CMD55);			/* Start + Command index */
	SPI2_ExchangeByte((BYTE)(0 >> 24));	/* Argument[31..24] */
	SPI2_ExchangeByte((BYTE)(0 >> 16));	/* Argument[23..16] */
	SPI2_ExchangeByte((BYTE)(0 >> 8));		/* Argument[15..8] */
	SPI2_ExchangeByte((BYTE)0);			/* Argument[7..0] */
	n = 0x01;						/* Dummy CRC + Stop */
	SPI2_ExchangeByte(n);

	n = 10;							/* Wait for a valid response in timeout of 10 attempts */
	do {
		res = SPI2_ExchangeByte(0xFF);
	} while ((res & 0x80) && --n);

	return res;			/* Return with the response value */
}

static BYTE send_cmd (
	BYTE cmd,		/* Command byte */
	DWORD arg		/* Argument */
)
{
	BYTE n, res;

	if (cmd & 0x80) {	// ACMD<n> is the command sequense of CMD55-CMD<n> 
		cmd &= 0x7F;
		res = send_cmd_55();
		if (res > 1) return res;
	}

	/* Select the card and wait for ready except to stop multiple block read */
	if (cmd != CMD12) {
		deselect();
		if (!select()) return 0xFF;
	}

	/* Send command packet */
	SPI2_ExchangeByte(0x40 | cmd);			/* Start + Command index */
	SPI2_ExchangeByte((BYTE)(arg >> 24));	/* Argument[31..24] */
	SPI2_ExchangeByte((BYTE)(arg >> 16));	/* Argument[23..16] */
	SPI2_ExchangeByte((BYTE)(arg >> 8));		/* Argument[15..8] */
	SPI2_ExchangeByte((BYTE)arg);			/* Argument[7..0] */
	n = 0x01;						/* Dummy CRC + Stop */
	if (cmd == CMD0) n = 0x95;		/* Valid CRC for CMD0(0) + Stop */
	if (cmd == CMD8) n = 0x87;		/* Valid CRC for CMD8(0x1AA) + Stop */
	SPI2_ExchangeByte(n);

	/* Receive command response */
	if (cmd == CMD12) SPI2_ExchangeByte(0xFF);	/* Skip a stuff byte on stop to read */
	n = 10;							/* Wait for a valid response in timeout of 10 attempts */
	do {
		res = SPI2_ExchangeByte(0xFF);
	} while ((res & 0x80) && --n);

	return res;			/* Return with the response value */
}


void DRVA_TMR_ms(void) {
	UINT n;
	n = Timer1;					/* 1000Hz decrement timer with zero stopped */
	if (n) Timer1 = --n;
	n = Timer2;
	if (n) Timer2 = --n;
}

// Public functions

bool DRVA_IsMediaPresent(void)
{
    return !PORTBbits.RB5;
}

bool DRVA_MediaInitialize(void)
{
    if (!DRVA_IsMediaPresent()) return false;
    BYTE n, cmd, ty, ocr[4];
    
    SPI2_Open(SPI2_DEFAULT); // Open in Slow Mode
    for (n = 10; n; n--) SPI2_ExchangeByte(0xFF);	/* 80 dummy clocks */
    
    ty = 0;
	if (send_cmd(CMD0, 0) == 1) {			/* Enter Idle state */
		Timer1 = 1000;						/* Initialization timeout of 1000 msec */
		if (send_cmd(CMD8, 0x1AA) == 1) {	/* SDv2? */
			for (n = 0; n < 4; n++) ocr[n] = SPI2_ExchangeByte(0xFF);/* Get trailing return value of R7 resp */
			if (ocr[2] == 0x01 && ocr[3] == 0xAA) {				/* The card can work at vdd range of 2.7-3.6V */
				while (Timer1 && send_cmd(ACMD41, 0x40000000));	/* Wait for leaving idle state (ACMD41 with HCS bit) */
				if (Timer1 && send_cmd(CMD58, 0) == 0) {			/* Check CCS bit in the OCR */
					for (n = 0; n < 4; n++) ocr[n] = SPI2_ExchangeByte(0xFF);
					ty = (ocr[0] & 0x40) ? CT_SD2|CT_BLOCK : CT_SD2;	/* SDv2+ */
				}
			}
		} else {							/* SDv1 or MMCv3 */
			if (send_cmd(ACMD41, 0) <= 1) 	{
				ty = CT_SD1; cmd = ACMD41;	/* SDv1 */
			} else {
				ty = CT_MMC; cmd = CMD1;	/* MMCv3 */
			}
			while (Timer1 && send_cmd(cmd, 0));		/* Wait for leaving idle state */
			if (!Timer1 || send_cmd(CMD16, 512) != 0) ty = 0;	/* Set read/write block length to 512 */
		}
	}
	CardType = ty;
	deselect();

	if (ty) {		/* Function succeded */
		DiskInitialized = true;
        //SSP2CON1 = 0; // This enables writing at 16Mhz - This may screw things up, enable it later
        return true;
	} else {		/* Function failed */
		SPI2_Close();
	}
    
	return false;
}

bool DRVA_IsMediaInitialized(void)
{
    return DiskInitialized;
}

bool DRVA_IsWriteProtected(void)
{
    // always not write protected even if it is
    return DiskWP;
}

uint16_t DRVA_GetSectorSize(void)
{
    #warning "You will need to implement this function for this driver to work."
    return 512;
}

uint32_t DRVA_GetSectorCount(void)
{
    #warning "You will need to implement this function for this driver to work."
    return 0;
}

bool DRVA_SectorRead(uint32_t sector_address, uint8_t* buffer, uint16_t sector_count)
{
    DWORD sect = (DWORD)sector_address;

	if (!DRVA_IsMediaInitialized()) return false;
	if (!(CardType & CT_BLOCK)) sect *= 512;	/* Convert to byte address if needed */

	if (sector_count == 1) {		/* Single block read */
		if ((send_cmd(CMD17, sect) == 0)	/* READ_SINGLE_BLOCK */
			&& rcvr_datablock(buffer, 512)) {
			sector_count = 0;
		}
	}
	else {				/* Multiple block read */
		if (send_cmd(CMD18, sect) == 0) {	/* READ_MULTIPLE_BLOCK */
			do {
				if (!rcvr_datablock(buffer, 512)) break;
				buffer += 512;
			} while (--sector_count);
			send_cmd(CMD12, 0);				/* STOP_TRANSMISSION */
		}
	}
	deselect();

	return true;

}

bool DRVA_SectorWrite(uint32_t sector_address, const uint8_t* buffer, uint16_t sector_count)
{
    DWORD sect = (DWORD)sector_address;

	if (!DRVA_IsMediaInitialized()) return false;

	if (!(CardType & CT_BLOCK)) sect *= 512;	/* Convert to byte address if needed */

	if (sector_count == 1) {		/* Single block write */
		if ((send_cmd(CMD24, sect) == 0)	/* WRITE_BLOCK */
			&& xmit_datablock(buffer, 0xFE)) {
			sector_count = 0;
		}
	}
	else {				/* Multiple block write */
		if (CardType & CT_SDC) send_cmd(ACMD23, sector_count);
		if (send_cmd(CMD25, sect) == 0) {	/* WRITE_MULTIPLE_BLOCK */
			do {
				if (!xmit_datablock(buffer, 0xFC)) break;
				buffer += 512;
			} while (--sector_count);
			if (!xmit_datablock(0, 0xFD)) sector_count = 1;	/* STOP_TRAN token */
		}
	}
	deselect();

	return true;
}
