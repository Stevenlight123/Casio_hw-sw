#include "clock.h"

static int msCounter = 0;
static int seconds = 0;
static int minutes = 0;
static int hour = 0;
static int sample = 0; 

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

int Clock_SetSeconds(void){
    seconds = (seconds + 1) % 60;
    return seconds;
}

int Clock_SetMinutes(void){
    minutes = (minutes + 1) % 60;
    return minutes;
}

int Clock_SetHour(void){
    hour = (hour + 1) % 24;
    return hour;
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

int Clock_AllNb(void){
    
    sample = (hour*10000)+(minutes*100)+seconds;

    return sample;
}