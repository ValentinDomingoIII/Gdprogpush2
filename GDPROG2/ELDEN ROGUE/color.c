#include "color.h"

void greenText()
{
    printf("\x1b[38;5;34m");
}

void resetText()
{
    printf("\x1b[0m");
}

void redText()
{
    printf("\x1b[38;5;9m");
}

void blueText()
{
    printf("\x1b[38;5;33m");
}

void yellowText()
{
    printf("\x1b[38;5;220m");
}

void pinkText()
{
    printf("\x1b[38;5;13m");
}

void grayText()
{
    printf("\x1b[38;5;8m");
}
