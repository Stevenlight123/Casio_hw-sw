#ifndef ALARM_H
#define ALARM_H

#include <stdbool.h>

void Alarm_Advance(void);
void Alarm_ResetToZero(void);
void Alarm_AppendOne(void);
int Alarm_GetHour(void);
int Alarm_GetMinutes(void);
int Alarm_GetSetting(void);
bool Alarm_Check(void);
bool Alarm_GetEnabled(void);
void Alarm_Update(void);
void Alarm_Stop(void);
bool Alarm_IsRinging(void);

#endif
