//
//  TestOpenCloseADC.c
//
//  Created by Joshua Blakely on 7/4/13.
//  Copyright (c) 2013 Joshua Blakely. All rights reserved.
//

#include <stdio.h>
//#include <unistd.h>
//#include <time.h>

#include "JB_ADC.h"
#include "Hdr.h"

int main(void)
{
    
    printf("\n\nStarting to Run TestOpenCloseADC.\n");
    printf("This will test the ADC by enabling\n");
    printf("and disabling the ADC cape\n");
    
    if (enableADC() == CE_GOOD)
    {
        printf("ADC has been successfully enabled\n");
        
    } else
    {
        printf("There was a problem enabling the cape\n");
    }
    
    if (disableADC() != CE_GOOD)
    {
        printf("Problem with disabling the ADC Cape\n");
        
    } else
    {
        printf("ADC Cape has been disabled\n");
    }
    
    return 0;
}

