#ifndef CLOCK_H
#define CLOCK_H

void Clock_Init(void);
void Clock_Update(void);
int Clock_GetMs(void);
int Clock_GetSeconds(void);
int Clock_GetMinutes(void);
int Clock_GetHour(void);

#endif