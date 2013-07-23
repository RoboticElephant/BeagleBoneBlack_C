//
//  ReadingADC.c
//
//  Created by Joshua Blakely on 7/2/13.
//  Copyright (c) 2013 Joshua Blakely. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <time.h>

#include "JB_ADC.h"
#include "Hdr.h"

#define REQFILE     "/home/root/sensorReadings.txt"

int main(void)
{

    FILE *fp;
    int cycles = 0;
    float pinValue = 0;
    char tempV[40];
    time_t rawtime;
    
    printf("\n\nStarting to Run ReadingADC.\n");
    printf("This will read the photoresistor\n");
    printf("and record its value and the time\n");
    printf("every 10 minutes for 24 hours.\n");
    printf("It will record all these values to:\n");
    printf("%s\n\n", REQFILE);
    
    if (enableADC() == CE_GOOD)
    {
        printf("ADC has been successfully enabled\n");
        
        while (cycles < 145)
        {
            time(&rawtime);
            
            if (readADCPIN(P9_40, &pinValue) != CE_GOOD)
            {
                printf("problem reading ADC value\n");
            }
            if (readADCPIN(P9_40, &pinValue) != CE_GOOD)
            {
                printf("problem reading ADC value\n");
            }
            
            if ((fp = fopen(REQFILE, "ab")) == NULL)
            {
                printf("Cannot open file");
            }
            
            sprintf(tempV, "%f, %s\n", pinValue, ctime(&rawtime));
            fwrite(tempV, sizeof(tempV[0]), sizeof(tempV)/sizeof(tempV[0]), fp);
            
            fclose(fp);
            
            printf("Reading %i has been saved\n", cycles);
            
            if (cycles != 144)
            {
                // This will sleep for 10 minutes
                sleep(600);
            }
            cycles++;
        }
    } else
    {
        printf("There was a problem enabling the cape\n");
    }
    
    // This is commented out because I am having problem with the
    // disable locking up the SLOTS
//    if (disableADC() != CE_GOOD)
//    {
//        printf("Problem with disabling the ADC Cape\n");
//        
//    } else
//    {
//        printf("ADC Cape has been disabled\n");
//    }
    
    return 0;
}

