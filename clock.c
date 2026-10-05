#include "clock.h"

static int msCounter = 0;
static int seconds = 0;
static int minutes = 0;
static int hour = 0;

void Clock_Init(void){
    msCounter = 0;
    seconds = 0;
    minutes = 0;
    hour = 0;
}

void Clock_Update(void){
    msCounter += 10;
    if(msCounter >= 1000){
        seconds ++;
        msCounter -= 1000;
        if(seconds >= 60){
            minutes++;
            seconds = 0;
            if(minutes >= 60){
                hour++;
                minutes = 0;
                if(hour >= 24){
                    hour = 0; 
                }
            }
        }
    } 
}

int Clock_GetSeconds(void){
    return seconds;
}

int Clock_GetMinutes(void){
    return minutes;
}

int Clock_GetHour(void){
    return hour;
}