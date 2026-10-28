// PC unit tests for the hardware-independent modules clock.c, alarm.c, stopwatch.c
#include <stdio.h>
#include <string.h>
#include "clock.h"
#include "alarm.h"
#include "stopwatch.h"

static int fails = 0;
#define CHECK(name, cond) do { int ok = (cond); printf("%-55s %s\n", name, ok ? "PASS" : "FAIL"); if (!ok) fails++; } while (0)

static void ticks(long n) { for (long i = 0; i < n; i++) Clock_Update(); }

int main(void)
{
    Clock_Init();
    ticks(100);
    CHECK("100 ticks = 00:00:01", Clock_GetSeconds() == 1 && Clock_GetMinutes() == 0);

    Clock_Init();
    ticks(24L * 3600 * 100 - 1);
    CHECK("1 tick before midnight = 23:59:59, Thu 01/01/2026",
          Clock_GetHour() == 23 && Clock_GetMinutes() == 59 && Clock_GetSeconds() == 59 &&
          Clock_GetDayOfMonth() == 1 && !strcmp(Clock_GetDay(), "Thu"));
    ticks(1);
    CHECK("23:59:59 -> 00:00:00 Fri 02/01/2026",
          Clock_GetHour() == 0 && Clock_GetMinutes() == 0 && Clock_GetSeconds() == 0 &&
          Clock_GetDayOfMonth() == 2 && Clock_GetMonth() == 1 && !strcmp(Clock_GetDay(), "Fri"));

    // advance day by day (state already at 02/01/2026)
    const long DAY = 24L * 3600 * 100;
    ticks(30 * DAY);
    CHECK("31/01/2026 -> 01/02/2026", Clock_GetDayOfMonth() == 1 && Clock_GetMonth() == 2);
    ticks(28 * DAY);
    CHECK("28/02/2026 -> 01/03/2026 (not leap year)", Clock_GetDayOfMonth() == 1 && Clock_GetMonth() == 3);

    while (!(Clock_GetYear() == 2027 && Clock_GetMonth() == 1 && Clock_GetDayOfMonth() == 1))
        ticks(DAY);
    CHECK("31/12/2026 -> 01/01/2027 is a Friday", !strcmp(Clock_GetDay(), "Fri"));

    while (!(Clock_GetYear() == 2028 && Clock_GetMonth() == 2 && Clock_GetDayOfMonth() == 28))
        ticks(DAY);
    ticks(DAY);
    CHECK("28/02/2028 -> 29/02/2028 (leap year)", Clock_GetDayOfMonth() == 29 && Clock_GetMonth() == 2);
    ticks(DAY);
    CHECK("29/02/2028 -> 01/03/2028", Clock_GetDayOfMonth() == 1 && Clock_GetMonth() == 3);

    // Setting wrap-around
    Clock_Init();
    for (int i = 0; i < 60; i++) Clock_SetSeconds();
    CHECK("Set seconds 60 times wraps 59 -> 0", Clock_GetSeconds() == 0);
    for (int i = 0; i < 59; i++) Clock_SetMinutes();
    CHECK("Set minutes 59 times = 59", Clock_GetMinutes() == 59);
    Clock_SetMinutes();
    CHECK("Set minutes once more wraps 59 -> 0", Clock_GetMinutes() == 0);
    for (int i = 0; i < 24; i++) Clock_SetHour();
    CHECK("Set hour 24 times wraps 23 -> 0", Clock_GetHour() == 0);

    // Alarm at 60x speed: alarm 00:01 ON
    Clock_Init();
    Alarm_ResetToZero();
    Alarm_Advance();          // -> minutes
    Alarm_AppendOne();        // 00:01
    Alarm_Advance();          // -> on/off
    Alarm_AppendOne();        // ON
    int rang = 0, ring_starts = 0, prev = 0;
    for (int tick = 0; tick < 200; tick++)       // 200 real ticks = 2 s real = 120 s watch time at 60x
    {
        for (int i = 0; i < 60; i++) { Clock_Update(); Alarm_Update(); }
        int r = Alarm_IsRinging();
        if (r && !prev) ring_starts++;
        if (r) rang = 1;
        prev = r;
    }
    CHECK("Alarm 00:01 rings at 60x speed", rang);
    CHECK("Alarm starts ringing exactly once", ring_starts == 1);
    CHECK("Alarm stopped by itself after the minute", !Alarm_IsRinging());

    // Alarm stopped by user does not restart within the same minute
    Clock_Init();
    ring_starts = 0; prev = 0;
    for (int tick = 0; tick < 12000; tick++)     // 2 min at 1x
    {
        Clock_Update(); Alarm_Update();
        int r = Alarm_IsRinging();
        if (r && !prev) { ring_starts++; Alarm_Stop(); r = 0; }
        prev = r;
    }
    CHECK("Alarm stopped by button does not ring again", ring_starts == 1);

    // Alarm OFF does not ring
    Alarm_AppendOne();        // toggle OFF
    Clock_Init();
    rang = 0;
    for (int tick = 0; tick < 12000; tick++) { Clock_Update(); Alarm_Update(); if (Alarm_IsRinging()) rang = 1; }
    CHECK("Alarm OFF does not ring", !rang);

    // Stopwatch
    SW_Init();
    for (int i = 0; i < 6123; i++) SW_Update();
    CHECK("Stopwatch 6123 ticks = 01:01.23",
          SW_GetMinutes() == 1 && SW_GetSeconds() == 1 && SW_GetMs() / 10 == 23);
    SW_Init();
    for (long i = 0; i < 360000 - 1; i++) SW_Update();
    CHECK("Stopwatch shows 59:59.99", SW_GetMinutes() == 59 && SW_GetSeconds() == 59 && SW_GetMs() / 10 == 99);
    SW_Update();
    CHECK("Stopwatch wraps 59:59.99 -> 00:00.00", SW_GetMinutes() == 0 && SW_GetSeconds() == 0 && SW_GetMs() == 0);

    printf("\n%d failure(s)\n", fails);
    return fails != 0;
}
