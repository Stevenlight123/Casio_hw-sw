#include "clock.h"
#include <time.h>
#define MS_FIRST_JAN_2026 1767225600000
#define MS_IN_ONE_DAY 86400000

static int msCounter = 0;
static int seconds = 0;
static int minutes = 0;
static int hour = 0;
static int day = 0;
static int month = 1;
static int year = 2026;
static int sample = 0;
static char *daysOfWeek[] = {"Thu", "Fri", "Sat", "Sun", "Mon", "Tue", "Wed"};

void Clock_Init(void)
{
    msCounter = 0;
    seconds = 0;
    minutes = 0;
    hour = 0;
}

void Clock_Update(void)
{
    msCounter += 10;
    if (msCounter >= 1000)
    {
        seconds++;
        msCounter -= 1000;
        if (seconds >= 60)
        {
            minutes++;
            seconds = 0;
            if (minutes >= 60)
            {
                hour++;
                minutes = 0;
                if (hour >= 24)
                {
                    hour = 0;
                    day++;
                }
            }
        }
    }
}

int Clock_SetSeconds(void)
{
    seconds = (seconds + 1) % 60;
    return seconds;
}

int Clock_SetMinutes(void)
{
    minutes = (minutes + 1) % 60;
    return minutes;
}

int Clock_SetHour(void)
{
    hour = (hour + 1) % 24;
    return hour;
}

int Clock_GetSeconds(void)
{
    return seconds;
}

int Clock_GetMinutes(void)
{
    return minutes;
}

int Clock_GetHour(void)
{
    return hour;
}

char *Clock_GetDay(void)
{
    return daysOfWeek[day % 7];
}

time_t Clock_GetDate(void)
{
    time_t currentTime;
    return time(&currentTime);
}

int Clock_AllNb(void)
{

    sample = (hour * 10000) + (minutes * 100) + seconds;

    return sample;
}