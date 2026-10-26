#include <stdbool.h>
#include "alarm.h"
#include "clock.h"

static int alarmHour = 0;
static int alarmMinutes = 0;
static int alarmSetting = 0;
static bool alarmEnabled = false;
static bool alarmTriggered = false;
static volatile bool alarmRinging = false;

// alarmSetting: 0 = hour, 1 = minutes, 2 = on/off
void Alarm_Advance(void)
{
    alarmSetting = (alarmSetting + 1) % 3;
}

void Alarm_ResetToZero(void)
{
    alarmHour = 0;
    alarmMinutes = 0;
    alarmSetting = 0;
}

void Alarm_AppendOne(void)
{
    if (alarmSetting == 0)
    {
        alarmHour = (alarmHour + 1) % 24;
    }
    else if (alarmSetting == 1)
    {
        alarmMinutes = (alarmMinutes + 1) % 60;
    }
    else
    {
        alarmEnabled = !alarmEnabled;
    }
}

int Alarm_GetHour(void)
{
    return alarmHour;
}

int Alarm_GetMinutes(void)
{
    return alarmMinutes;
}

int Alarm_GetSetting(void)
{
    return alarmSetting;
}

bool Alarm_Check(void)
{
    return alarmEnabled && alarmHour == Clock_GetHour() && alarmMinutes == Clock_GetMinutes();
}

bool Alarm_GetEnabled(void)
{
    return alarmEnabled;
}

// Called after each Clock_Update. Rings once when the alarm minute starts,
// and stops by itself when the minute is over.
void Alarm_Update(void)
{
    if (Alarm_Check())
    {
        if (!alarmTriggered)
        {
            alarmTriggered = true;
            alarmRinging = true;
        }
    }
    else
    {
        alarmTriggered = false;
        alarmRinging = false;
    }
}

void Alarm_Stop(void)
{
    alarmRinging = false;
}

bool Alarm_IsRinging(void)
{
    return alarmRinging;
}
