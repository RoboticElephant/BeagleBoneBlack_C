//
//  TestLaser.c
//  
//
//  Created by Joshua Blakely on 12/7/2013.
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
#define LASER_2 47
#define LASER_3 46
#define LASER_4 27

int main(void)
{
    int value = 0;
    int temp;
    printf("HelloBoneWorld\n");

    value = gpioExDirection(LASER_1, gpioOut);
    value += gpioExDirection(LASER_2, gpioOut);
    value += gpioExDirection(LASER_3, gpioOut);
    value += gpioExDirection(LASER_4, gpioOut);
    printf("value: %i\n", value);
    DelayMS(20);
    if (value == CE_GOOD)
    {
        for (temp = 0; temp < 10; temp++)
        {
            gpioDigOutput(LASER_1, HIGH);
            DelayMS(50);
            gpioDigOutput(LASER_1, LOW);
            DelayMS(50);
            gpioDigOutput(LASER_2, HIGH);
            DelayMS(50);
            gpioDigOutput(LASER_2, LOW);
            DelayMS(50);
            gpioDigOutput(LASER_3, HIGH);
            DelayMS(50);
            gpioDigOutput(LASER_3, LOW);
            DelayMS(50);
            gpioDigOutput(LASER_4, HIGH);
            DelayMS(50);
            gpioDigOutput(LASER_4, LOW);
            DelayMS(50);
        }
    } // Close of Else for pwmEnabled

    closeGPIO(LASER_1);
    closeGPIO(LASER_2);
    closeGPIO(LASER_3);
    closeGPIO(LASER_4);

    return 0;
}
