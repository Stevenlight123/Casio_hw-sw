#ifndef CLOCK_H
#define CLOCK_H

void Clock_Init(void);
void Clock_Update(void);
int Clock_GetSeconds(void);
int Clock_GetMinutes(void);
int Clock_GetHour(void);
int Clock_AllNb(void);
int Clock_SetSeconds(void);
int Clock_SetMinutes(void);
int Clock_SetHour(void);
time_t Clock_GetDate(void);
int Clock_GetDay(void);

#endif