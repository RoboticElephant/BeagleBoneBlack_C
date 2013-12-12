//
//  TestLaser.c
//  
//
//  Created by Joshua Blakely on 12//2013.
//
// Purpose:
//  The purpose of this file is to test the usage of a lazer beam
//
//

#include <stdio.h>
#include <unistd.h>

#include "JB_GPIO.h"
#include "JBUtility.h"
#include "Hdr.h"

#define LASER_1 26

int main (void)
{
    int value = 0;
    int temp;
    printf("HelloBoneWorld\n");
    
    value = gpioExDirection(LASER_1, gpioOut);
	printf("value: %i", value);
    DelayUS(20);
    if (value == CE_GOOD) 
    {
		for(temp = 0; temp < 10; temp++)
		{
			gpioDigOutput(LASER_1, HIGH);
			printf("value: %i", value);
			DelayUS(50);
			gpioDigOutput(LASER_1, LOW);
			printf("value: %i", value);
			DelayUS(50);
		}
    } // Close of Else for pwmEnabled
    
    closeGPIO(LASER_1);
    
    return 0;
}
