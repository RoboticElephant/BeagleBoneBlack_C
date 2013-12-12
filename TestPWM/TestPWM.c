//
//  TestPWM.c
//  
//
//  Created by Joshua Blakely on 5/25/13.
//
// Purpose:
//  The purpose of this file is to test the JB_GPIO.h file (Manipulation of
//  GPIO/PWM)
//
//

#include <stdio.h>
#include <unistd.h>

#include "JB_PWM.h"
#include "JBUtility.h"
#include "Hdr.h"

#define PWMLED P8_13

int main (void)
{
    int value = 0;
    int temp;
    printf("HelloBoneWorld\n");
    
    printf("trying PWM\n");
    
    pwmEnable();
    DelayUS(20);
    value = pwmPINSelEnable(PWMLED);
    DelayUS(20);
    if (value == CE_GOOD) {
        
        printf("enabled PWM\n");
        
        DelayUS(50);
        
        value = pwmPeriod(PWMLED, 20000000);
        if (value == CE_GOOD) {
            
            printf("period value set\n");
            
            for (temp = 0; temp < 101; temp += 10) {
                printf("for loop: %i\n",temp);
                value = pwmWriteDutyCycle(PWMLED, temp);
                if (value == CE_GOOD)
                {
                    printf("dutyCycle Set\n");
                    
                } else {
                    printf("DutyCycle failed with value %i\n", value);
                } // Close of Else for DutyCycle
                DelayMS(500);
            }
        
        } else {
            printf("Period failed with value: %i\n", value);
        } // Close of Else for pwmPeriod
        
    } else {
        printf("PWM Enabling Failed with value: %i\n", value);
        
    } // Close of Else for pwmEnabled
    
    return 0;
}
