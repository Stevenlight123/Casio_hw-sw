#include "clock.h"

static int msCounter = 0;
static int seconds = 0;
static int minutes = 0;
static int hour = 0;
static int day = 1;
static int month = 1;
static int year = 2026;
static int weekday = 0;
static int sample = 0;
static char *daysOfWeek[] = {"Thu", "Fri", "Sat", "Sun", "Mon", "Tue", "Wed"};
static const int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int Clock_DaysInMonth(void)
{
    bool leapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    if (month == 2 && leapYear)
    {
        return 29;
    }
    return daysInMonth[month - 1];
}

static void Clock_NextDay(void)
{
    weekday = (weekday + 1) % 7;
    day++;
    if (day > Clock_DaysInMonth())
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

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
                    Clock_NextDay();
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
    return daysOfWeek[weekday];
}

int Clock_GetDayOfMonth(void)
{
    return day;
}

int Clock_GetMonth(void)
{
    return month;
}

int Clock_GetYear(void)
{
    return year;
}

int Clock_AllNb(void)
{

    sample = (hour * 10000) + (minutes * 100) + seconds;

    return sample;
}