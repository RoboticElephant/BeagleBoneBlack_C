//
//  TestPWM.c
//  
//
//  Created by Joshua Blakely on 5/25/13.
//
// Purpose:
//  The purpose of this file is to test the I2C. Before using
// 	the file you will need to enable the specific EEPROM address.
//	
//	echo 24c64 0x50 > /sys/bus/i2c/devices/i2c-1/new_device
//	change the 24c64 to your style of EEPROM
//	change the 0x50 to the address of the EEPROM you are trying
//		to access.	
//
//

#include <stdio.h>
#include "JB_Communication.h"
#include "Hdr.h"

int main (void)
{
    int value = 0;
    unsigned char str[] = "Hello Friends";
    unsigned char readStr[50];
    
	printf("HelloBoneWorld\n");
    printf("Initiate I2C EEPROM\n");
	value = initI2CEEPROM(1, 0x50, LC24C64);
	printf("Value of I2C intiate is %i\n", value);
    
	if(value == CE_GOOD)
	{
		printf("trying I2C\n"); 
		value = writeI2CEEPROM(1, 0x50, 5, str, sizeof(str));
		printf("Value of I2C is %i\n", value);
		value = readI2CEEPROM(1, 0x50, 7, readStr, 8);
		printf("value = %i and readStr = %s\n", value, readStr);
	}
	
    return 0;
}
