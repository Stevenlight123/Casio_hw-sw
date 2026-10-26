#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>

void Clock_Init(void);
void Clock_Update(void);
int Clock_GetSeconds(void);
int Clock_GetMinutes(void);
int Clock_GetHour(void);
int Clock_AllNb(void);
int Clock_SetSeconds(void);
int Clock_SetMinutes(void);
int Clock_SetHour(void);
char *Clock_GetDay(void);
int Clock_GetDayOfMonth(void);
int Clock_GetMonth(void);
int Clock_GetYear(void);

#endif