
#include "stopwatch.h";

unsigned long totalseconds = 0;
static int msCounter = 0;
static int seconds = 0;
static int minutes = 0;
static int hour = 0;

void SW_Init(void){
    msCounter = 0;
    seconds = 0;
    minutes = 0;
    hour = 0;
}

void SW_Update(void){
    msCounter += 10;
    if(msCounter >= 1000){
        msCounter -= 1000;
        totalseconds++; 
    
    seconds = totalseconds % 60;
    minutes = (totalseconds / 60) % 60; 
    hour = ((totalseconds / 60)/60) % 24;
    }
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

int SW_GetHour(void){
    return hour;
}