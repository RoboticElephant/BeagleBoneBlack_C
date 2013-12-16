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
#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <linux/i2c-dev.h>
//#include <sys/ioctl.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>

#include "JB_Communication.h"
#include "Hdr.h"

//int initI2C(int busSelect, unsigned char address, int *file);

/****************************************************************************/
//
// EEPROM I2C
//
/****************************************************************************/
int initI2CEEPROM(int busSelect, unsigned char address, char *typeEEPROM)
{
	if(busSelect != 1 && busSelect != 0)
	{
		printf("Incorrect BUS selected\n");
		return CE_INCORRECT_SELECTION;
	}
	char str[60];
	sprintf(str, "echo %s 0x%x > /sys/bus/i2c/devices/i2c-%i/new_device", typeEEPROM, address, busSelect);
	system(str);
	return CE_GOOD;
}

int writeI2CEEPROM(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength)
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

int readI2CEEPROM(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength)
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

/***********************************************************************************************/
//
// I2C Main
//
/***********************************************************************************************/
/*
int initI2C(int busSelect, unsigned char address, int *file)
{
    char filename[12];

    sprintf(filename, "/dev/i2c-%i", busSelect);
    if ((*file = open(filename, O_RDWR)) < 0) 
	{
        printf("Failed to open the bus.");
		return CE_FAIL_EXPORT;
    }

    if (ioctl(*file, I2C_SLAVE, address) < 0) 
	{
        printf("Failed to acquire bus access and/or talk to slave.\n");
		close(*file);
        return CE_FAIL_ACCESS;
    }
	
	return CE_GOOD;
}

int MasterI2CWrite(int busSelect, unsigned char address, unsigned int location, unsigned char *saveString, int strLength)
{
	int file, errorValue;
	errorValue = initI2C(busSelect, address, &file);
	if(errorValue != CE_GOOD)
	{
		return errorValue;
	}

	int temp;
	char buf[strLength + 1];
	for(temp = 0; temp < strLength; temp++)
	{
		buf[temp] = *saveString++;	
	}

    if (pwrite(file, buf, strLength, location) != strLength) 
	{
        printf("Failed to write to the i2c bus.\n");
		close(file);
		return CE_FAIL_WRITE;
    }
	return CE_GOOD;
}

int MasterI2CRead(int busSelect, unsigned char address, unsigned int location, unsigned char *saveString, int strLength)
{
	int file, errorValue;
	errorValue = initI2C(busSelect, address, &file);
	if(errorValue != CE_GOOD)
	{
		return errorValue;
	}

    char buf[strLength + 1];
    // Using I2C Read
    if (pread(file, buf, strLength, location) != strLength) 
	{
        printf("Failed to read from the i2c bus.\n");
		close(file);
		return CE_FAIL_READ;
    }

	int temp;
	for(temp = 0; temp < strLength; temp++)
	{
		*saveString++ = buf[temp];	
	}
	return CE_GOOD;
}
*/
