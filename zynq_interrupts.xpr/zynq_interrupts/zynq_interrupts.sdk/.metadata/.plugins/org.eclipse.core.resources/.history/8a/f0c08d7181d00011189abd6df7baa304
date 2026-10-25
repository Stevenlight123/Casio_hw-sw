#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "clock.h"
#include "print.h"
#include "stopwatch.h"

#define ROW 7
#define COL 5

enum numbers
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    COLON,
    SPACE,
};

char init_chars[12] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, COLON, SPACE};

typedef struct _AsciiDigit
{
    char *line[ROW];
} AsciiDigit;

AsciiDigit bigChars[12];
AsciiDigit smallChars[12];

void printAsciiDigit()
{
    bool isMillis = false;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < (sizeof(init_chars) / sizeof(init_chars[0])) * 2; j++)
        {
            AsciiDigit *c = j < (sizeof(init_chars) / sizeof(init_chars[0])) ? &bigChars[j] : &smallChars[j % (sizeof(init_chars) / sizeof(init_chars[0]))];
            c->line[i] = (char *)malloc(COL + 1);
            if (c->line[i] == NULL)
            {
                printf("Memory allocation failed\n");
                return;
            }
        }
    }

    for (int i = 0; i < (sizeof(init_chars) / sizeof(init_chars[0])) * 2; i++)
    {
        if (i == sizeof(init_chars) / sizeof(init_chars[0]))
        {
            isMillis = true;
        }

        enum numbers digit = init_chars[i % (sizeof(init_chars) / sizeof(init_chars[0]))];
        AsciiDigit *c = !isMillis ? &bigChars[digit] : &smallChars[digit];

        if (!isMillis)
        {
            switch (digit)
            {
            case ZERO:
                strcpy(c->line[0], " OOO ");
                strcpy(c->line[1], "O   O");
                strcpy(c->line[2], "O   O");
                strcpy(c->line[3], "O   O");
                strcpy(c->line[4], "O   O");
                strcpy(c->line[5], "O   O");
                strcpy(c->line[6], " OOO ");
                break;
            case ONE:
                strcpy(c->line[0], "  O  ");
                strcpy(c->line[1], " OO  ");
                strcpy(c->line[2], "  O  ");
                strcpy(c->line[3], "  O  ");
                strcpy(c->line[4], "  O  ");
                strcpy(c->line[5], "  O  ");
                strcpy(c->line[6], "OOOOO");
                break;
            case TWO:
                strcpy(c->line[0], "OOOOO");
                strcpy(c->line[1], "    O");
                strcpy(c->line[2], "    O");
                strcpy(c->line[3], "   O ");
                strcpy(c->line[4], " O   ");
                strcpy(c->line[5], "O    ");
                strcpy(c->line[6], "OOOOO");
                break;
            case THREE:
                strcpy(c->line[0], "OOOOO");
                strcpy(c->line[1], "    O");
                strcpy(c->line[2], "    O");
                strcpy(c->line[3], "  OO ");
                strcpy(c->line[4], "    O");
                strcpy(c->line[5], "    O");
                strcpy(c->line[6], "OOOOO");
                break;
            case FOUR:
                strcpy(c->line[0], "O   O");
                strcpy(c->line[1], "O   O");
                strcpy(c->line[2], "O   O");
                strcpy(c->line[3], "OOOOO");
                strcpy(c->line[4], "    O");
                strcpy(c->line[5], "    O");
                strcpy(c->line[6], "    O");
                break;
            case FIVE:
                strcpy(c->line[0], "OOOOO");
                strcpy(c->line[1], "O    ");
                strcpy(c->line[2], "O    ");
                strcpy(c->line[3], "OOOO ");
                strcpy(c->line[4], "    O");
                strcpy(c->line[5], "    O");
                strcpy(c->line[6], "OOOOO");
                break;
            case SIX:
                strcpy(c->line[0], " OOO ");
                strcpy(c->line[1], "O    ");
                strcpy(c->line[2], "O    ");
                strcpy(c->line[3], "OOOO ");
                strcpy(c->line[4], "O   O");
                strcpy(c->line[5], "O   O");
                strcpy(c->line[6], " OOO ");
                break;
            case SEVEN:
                strcpy(c->line[0], "OOOOO");
                strcpy(c->line[1], "    O");
                strcpy(c->line[2], "   O ");
                strcpy(c->line[3], "  O  ");
                strcpy(c->line[4], " O   ");
                strcpy(c->line[5], " O   ");
                strcpy(c->line[6], " O   ");
                break;
            case EIGHT:
                strcpy(c->line[0], " OOO ");
                strcpy(c->line[1], "O   O");
                strcpy(c->line[2], "O   O");
                strcpy(c->line[3], " OOO ");
                strcpy(c->line[4], "O   O");
                strcpy(c->line[5], "O   O");
                strcpy(c->line[6], " OOO ");
                break;
            case NINE:
                strcpy(c->line[0], " OOO ");
                strcpy(c->line[1], "O   O");
                strcpy(c->line[2], "O   O");
                strcpy(c->line[3], " OOOO");
                strcpy(c->line[4], "    O");
                strcpy(c->line[5], "    O");
                strcpy(c->line[6], " OOO ");
                break;
            case COLON:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], " O O ");
                strcpy(c->line[2], " O O ");
                strcpy(c->line[3], "     ");
                strcpy(c->line[4], " O O ");
                strcpy(c->line[5], " O O ");
                strcpy(c->line[6], "     ");
                break;
            case SPACE:
                strcpy(c->line[0], "  ");
                strcpy(c->line[1], "  ");
                strcpy(c->line[2], "  ");
                strcpy(c->line[3], "  ");
                strcpy(c->line[4], "  ");
                strcpy(c->line[5], "  ");
                strcpy(c->line[6], "  ");
                break;
            default:
                printf("Invalid digit\n");
                return;
            }
        }
        else
        {
            switch (digit)
            {
            case ZERO:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], " OOO ");
                strcpy(c->line[3], "O   O");
                strcpy(c->line[4], "O   O");
                strcpy(c->line[5], "O   O");
                strcpy(c->line[6], " OOO ");
                break;
            case ONE:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], "  O  ");
                strcpy(c->line[3], " OO  ");
                strcpy(c->line[4], "  O  ");
                strcpy(c->line[5], "  O  ");
                strcpy(c->line[6], " OOO ");
                break;
            case TWO:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], " OOO ");
                strcpy(c->line[3], "    O");
                strcpy(c->line[4], " OOO ");
                strcpy(c->line[5], "O    ");
                strcpy(c->line[6], " OOO ");
                break;
            case THREE:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], " OOO ");
                strcpy(c->line[3], "    O");
                strcpy(c->line[4], "  OO ");
                strcpy(c->line[5], "    O");
                strcpy(c->line[6], " OOO ");
                break;
            case FOUR:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], "O   O");
                strcpy(c->line[3], "O   O");
                strcpy(c->line[4], " OOO ");
                strcpy(c->line[5], "    O");
                strcpy(c->line[6], "    O");
                break;
            case FIVE:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], " OOO ");
                strcpy(c->line[3], "O    ");
                strcpy(c->line[4], " OOO ");
                strcpy(c->line[5], "    O");
                strcpy(c->line[6], " OOO ");
                break;
            case SIX:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], " OOO ");
                strcpy(c->line[3], "O    ");
                strcpy(c->line[4], " OOO ");
                strcpy(c->line[5], "O   O");
                strcpy(c->line[6], " OOO ");
                break;
            case SEVEN:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], " OOO ");
                strcpy(c->line[3], "    O");
                strcpy(c->line[4], "   O ");
                strcpy(c->line[5], "  O  ");
                strcpy(c->line[6], "  O  ");
                break;
            case EIGHT:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], " OOO ");
                strcpy(c->line[3], "O   O");
                strcpy(c->line[4], " OOO ");
                strcpy(c->line[5], "O   O");
                strcpy(c->line[6], " OOO ");
                break;
            case NINE:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], " OOO ");
                strcpy(c->line[3], "O   O");
                strcpy(c->line[4], " OOO ");
                strcpy(c->line[5], "    O");
                strcpy(c->line[6], " OOO ");
                break;
            case COLON:
                strcpy(c->line[0], "     ");
                strcpy(c->line[1], "     ");
                strcpy(c->line[2], " O O ");
                strcpy(c->line[3], " O O ");
                strcpy(c->line[4], "     ");
                strcpy(c->line[5], " O O ");
                strcpy(c->line[6], " O O ");
                break;
            default:
                break;
            }
        }
    }
}

void print_digit(char digits[])
{
    if (strlen(digits) < 2)
    {
        printf("Minimum 2 chars needed. You only put %ld char(s)\n", strlen(digits));
        return;
    }
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < strlen(digits) - 2; j++)
        {
            if (strlen(digits) == 6 && j == 0)
            {
                printf("%s ", bigChars[0].line[i]);
                printf("%s ", bigChars[digits[j] - '0'].line[i]);
            }
            else
                printf("%s ", bigChars[digits[j] - '0'].line[i]);
        }
        for (int k = strlen(digits) - 2; k < strlen(digits); k++)
        {
            printf("%s ", smallChars[digits[k] - '0'].line[i]);
        }
        printf("\n");
    }
    printf("\r\n");
    return;
}

void Print_Cleanup(void)
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            free(bigChars[i].line[j]);
            free(smallChars[i].line[j]);
        }
    }
}

void Print_Init(void)
{
    printAsciiDigit();
}

void Print_Clock(void)
{
    char digits[8];

    sprintf(digits, "%02d:%02d%02d", Clock_GetHour(), Clock_GetMinutes(), Clock_GetSeconds());
    print_digit(digits);
}

void Print_Stopwatch(void)
{
    char digits[8];

    sprintf(digits, "%02d:%02d%02d", SW_GetMinutes(), SW_GetSeconds(), SW_GetMs());
    print_digit(digits);
}