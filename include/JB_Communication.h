/*****************************************************************************/
//
// JB_Communication.h
//
// Author: Josh Blakely
// Company: Robotic Elephant
// Revision: 0.0.2
// Date: 7/2/2013
//
// Purpose:
// This program is designed to control the GPIO using opening and closing of
// files through fopen(). The maninuplation of the files are for general GPIO
// and PWM.
//
/*****************************************************************************/
//
// Revision History:
//  0.0.1:  7/2/2013
//      - Initial Release with GPIO out only
//	0.0.2: 12/13/2013
//		- Added initializing EEPROM
//
/*****************************************************************************/

#ifndef _JB_Communication_h
#define _JB_Communication_h

// EEPROM types
#define LC24C64		"24c64"
#define LC24C256	"24c256"

int initI2CEEPROM(int busSelect, unsigned char address, unsigned char *eepromType);
// I2C functions
int writeI2C(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength);
int readI2C(int busSelect, unsigned char address, long int location, unsigned char *saveString, int strLength);

#endif
