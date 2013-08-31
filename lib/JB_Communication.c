/*****************************************************************************/
//
// JB_Communication.c
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: SEE JB_Communication.h
// Date: XX/XX/XXXX
//
// Purpose:
// This program is designed to control the GPIO using opening and closing of
// files through fopen(). The maninuplation of the files are for general GPIO
// and PWM.
//
/*****************************************************************************/

#include <stdio.h>

#include "JB_Communication.h"
#include "Hdr.h"

int writeI2C(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength)
{
	FILE *fp;
	int count;
	char str[50];
	
	if(busSelect == 1 || busSelect == 0)
	{
		sprintf(str, "/sys/bus/i2c/devices/%i-00%x/eeprom", busSelect, address);

		if((fp = fopen(str, "rb+")) == NULL)
		{
			printf("Failed to open the new_device to export\n");
			return CE_FAIL_EXPORT;
		}

		fseek(fp, location, SEEK_SET);		// Seeks from the beginning of the file until the desired location.

		for(count = 0; count < strLength; count++)
		{
			fputc(*saveString++, fp);		// Writes a character to the I2C bus
		}
		fclose(fp);		// Closes the FIle pointer

		return CE_GOOD;
	}
	
	return CE_INCORRECT_SELECTION;
}

int readI2C(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength)
{
	FILE *fp;
	int count;
	char str[50];
	
	if(busSelect == 1 || busSelect == 0)
	{
		sprintf(str, "/sys/bus/i2c/devices/%i-00%x/eeprom", busSelect, address);
		
		if((fp = fopen(str, "rb+")) == NULL)
		{
			printf("Failed to open the new_device to export\n");
			return CE_FAIL_EXPORT;
		}
		
		fseek(fp, location, SEEK_SET);		// Seeks from the beginning of the file until the desired location.

		for(count = 0; count < strLength; count++)
		{
			*saveString++ = fgetc(fp);		// Writes a character to the I2C bus
		}
		fclose(fp);		// Closes the FIle pointer

		return CE_GOOD;
	}
	
	return CE_INCORRECT_SELECTION;
}
