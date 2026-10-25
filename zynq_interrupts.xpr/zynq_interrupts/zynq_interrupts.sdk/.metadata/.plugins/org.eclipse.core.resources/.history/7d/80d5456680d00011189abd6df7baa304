
#include "stopwatch.h"

static int totalseconds = 0;
static int msCounter = 0;
static int seconds = 0;
static int minutes = 0;

void SW_Init(void){
    totalseconds = 0;
    msCounter = 0;
    seconds = 0;
    minutes = 0;
}

void SW_Update(void){
    msCounter += 10;
    if(msCounter >= 1000){
        msCounter -= 1000;
        totalseconds++; 
    
    seconds = totalseconds % 60;
    minutes = (totalseconds / 60) % 60; 
    }
}

int SW_TotalTime(void){
    return (minutes*10000) + (seconds*100)+ msCounter;
}

int SW_GetMs(void){
    return msCounter;
}

int SW_GetSeconds(void){
    return seconds;
}

int SW_GetMinutes(void){
    return minutes;
}
