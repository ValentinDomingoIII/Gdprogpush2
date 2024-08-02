#include "color.h"

void greenText()
{
    printf("\x1b[38;5;34m");
}

void greenTextBG()
{
    printf("\x1b[48;5;34m");
}

void resetText()
{
    printf("\x1b[0m");
}

void redText(int nValue)
{
    if(nValue == 1)
        printf("\x1b[38;5;9m");
    else
        printf("\x1b[48;5;9m");
}

void blueText()
{
    printf("\x1b[38;5;33m");
}

void yellowText()
{
    printf("\x1b[38;5;220m");
}

void yellowTextBG()
{
    printf("\x1b[48;5;220m");
}

void pinkText()
{
    printf("\x1b[38;5;13m");
}

void grayText()
{
    printf("\x1b[38;5;8m");
}

void grayTextBG()
{
    printf("\x1b[48;5;8m");
}

void purpleText()
{
    printf("\x1b[38;5;55m");
}

void whiteText()
{
    printf("\x1b[38;5;15m");    
}

void whiteTextBG()
{
    printf("\x1b[48;5;15m");
}

void line()
{
  printf("\n ════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════ \n");
}

void enemyFelled()
{
    greenText();
    printf("\n\t\t▀███▀▀▀███▀███▄   ▀███▀███▀▀▀███▀████▄     ▄███▀███▀   ▀██▀   ▀███▀▀▀██████▀▀▀███▀████▀   ▀████▀   ▀███▀▀▀███▀███▀▀▀██▄");
    printf("\n\t\t  ██    ▀█  ███▄    █   ██    ▀█  ████    ████   ███   ▄█       ██    ▀█ ██    ▀█  ██       ██       ██    ▀█  ██    ▀██▄");
    printf("\n\t\t  ██   █    █ ███   █   ██   █    █ ██   ▄█ ██    ███ ▄█        ██   █   ██   █    ██       ██       ██   █    ██     ▀██");
    printf("\n\t\t  ██████    █  ▀██▄ █   ██████    █  ██  █▀ ██     ████         ██▀▀██   ██████    ██       ██       ██████    ██      ██");
    printf("\n\t\t  ██   █  ▄ █   ▀██▄█   ██   █  ▄ █  ██▄█▀  ██      ██          ██   █   ██   █  ▄ ██     ▄ ██     ▄ ██   █  ▄ ██     ▄██");
    printf("\n\t\t  ██     ▄█ █     ███   ██     ▄█ █  ▀██▀   ██      ██          ██       ██     ▄█ ██    ▄█ ██    ▄█ ██     ▄█ ██    ▄██▀");
    printf("\n\t\t▄█████████████▄    ██ ▄█████████████▄ ▀▀  ▄████▄  ▄████▄      ▄████▄   ▄██████████████████████████████████████████████▀\n");
    resetText();
}

void greatEnemyFelled()
{
    greenText();
    printf("\n\t\t\t  ▄▄█▀▀▀█▄█▀███▀▀▀██▄ ▀███▀▀▀███      ██     ███▀▀██▀▀███   ▀███▀▀▀███▀███▄   ▀███▀███▀▀▀███▀████▄     ▄███▀███▀   ▀██▀");
    printf("\n\t\t\t▄██▀     ▀█  ██   ▀██▄  ██    ▀█     ▄██▄    █▀   ██   ▀█     ██    ▀█  ███▄    █   ██    ▀█  ████    ████   ███   ▄█");
    printf("\n\t\t\t██▀       ▀  ██   ▄██   ██   █      ▄█▀██▄        ██          ██   █    █ ███   █   ██   █    █ ██   ▄█ ██    ███ ▄█");
    printf("\n\t\t\t██           ███████    ██████     ▄█  ▀██        ██          ██████    █  ▀██▄ █   ██████    █  ██  █▀ ██     ████");
    printf("\n\t\t\t██▄    ▀████ ██  ██▄    ██   █  ▄  ████████       ██          ██   █  ▄ █   ▀██▄█   ██   █  ▄ █  ██▄█▀  ██      ██");
    printf("\n\t\t\t▀██▄     ██  ██   ▀██▄  ██     ▄█ █▀      ██      ██          ██     ▄█ █     ███   ██     ▄█ █  ▀██▀   ██      ██");
    printf("\n\t\t\t  ▀▀███████▄████▄ ▄███▄█████████████▄   ▄████▄  ▄████▄      ▄█████████████▄    ██ ▄█████████████▄ ▀▀  ▄████▄  ▄████▄\n\n");
    printf("\n\t\t\t\t\t\t▀███▀▀▀██████▀▀▀███▀████▀   ▀████▀   ▀███▀▀▀███▀███▀▀▀██▄");
    printf("\n\t\t\t\t\t\t  ██    ▀█ ██    ▀█  ██       ██       ██    ▀█  ██    ▀██▄");
    printf("\n\t\t\t\t\t\t  ██   █   ██   █    ██       ██       ██   █    ██     ▀██");
    printf("\n\t\t\t\t\t\t  ██▀▀██   ██████    ██       ██       ██████    ██      ██");
    printf("\n\t\t\t\t\t\t  ██   █   ██   █  ▄ ██     ▄ ██     ▄ ██   █  ▄ ██     ▄██");
    printf("\n\t\t\t\t\t\t  ██       ██     ▄█ ██    ▄█ ██    ▄█ ██     ▄█ ██    ▄██▀");
    printf("\n\t\t\t\t\t\t▄████▄   ▄██████████████████████████████████████████████▀\n\n");
    resetText();
}

void youDied()
{
    redText(1);
    printf("\n\t\t\t\t\t▀███▀   ▀██▀ ▄▄█▀▀██▄ ▀███▀   ▀███▀   ▀███▀▀▀██▄ ▀████▀███▀▀▀███▀███▀▀▀██▄");
    printf("\n\t\t\t\t\t  ███   ▄█ ▄██▀    ▀██▄██       █       ██    ▀██▄ ██   ██    ▀█  ██    ▀██▄");
    printf("\n\t\t\t\t\t   ███ ▄█  ██▀      ▀████       █       ██     ▀██ ██   ██   █    ██     ▀██");
    printf("\n\t\t\t\t\t    ████   ██        ████       █       ██      ██ ██   ██████    ██      ██");
    printf("\n\t\t\t\t\t     ██    ██▄      ▄████       █       ██     ▄██ ██   ██   █  ▄ ██     ▄██");
    printf("\n\t\t\t\t\t     ██    ▀██▄    ▄██▀██▄     ▄█       ██    ▄██▀ ██   ██     ▄█ ██    ▄██▀");
    printf("\n\t\t\t\t\t   ▄████▄    ▀▀████▀▀   ▀██████▀▀     ▄████████▀ ▄████▄██████████████████▀\n");
    resetText();
}

void credits()
{
    purpleText();
    printf("\n\t\t\t\t\t\t  ▄▄█▀▀▀█▄████▀▀▀██▄ ▀███▀▀▀███▀███▀▀▀██▄ ▀████▀██▀▀██▀▀███▄█▀▀▀█▄█");
    printf("\n\t\t\t\t\t\t▄██▀     ▀█ ██   ▀██▄  ██    ▀█  ██    ▀██▄ ██ █▀   ██   ▀███    ▀█");
    printf("\n\t\t\t\t\t\t██▀       ▀ ██   ▄██   ██   █    ██     ▀██ ██      ██    ▀███▄");
    printf("\n\t\t\t\t\t\t██          ███████    ██████    ██      ██ ██      ██      ▀█████▄");
    printf("\n\t\t\t\t\t\t██▄         ██  ██▄    ██   █  ▄ ██     ▄██ ██      ██    ▄     ▀██");
    printf("\n\t\t\t\t\t\t▀██▄     ▄▀ ██   ▀██▄  ██     ▄█ ██    ▄██▀ ██      ██    ██     ██");
    printf("\n\t\t\t\t\t\t  ▀▀█████▀▄████▄ ▄███▄██████████████████▀ ▄████▄  ▄████▄  █▀█████▀ \n\n");
    resetText();
}

void displayHealthbar(int nMaxHealth, int nCurrentHealth)
{
    float fMilestone = nMaxHealth / 20.0f;
    float fCounter = 0.0f;

    yellowTextBG();
    printf(" ♥︎ ");
    resetText();
    
    for(int i = 0; i < 20; i++){
        if(fCounter < nCurrentHealth){
            fCounter += fMilestone;
            redText(1);
            printf("█");
            resetText();
        }

        else{
            grayText();
            printf("█");
            resetText();
        }
    }
}

void runesObtained(int nRandom) 
{
    char cInput;

    printf("\t\t\t\t\t\t\t╔═════╗\n");
    printf("\t\t\t\t\t\t\t║ ");
    blueText();
    printf("◊◊◊ ");
    resetText();
    printf("║\tYou obtained ");
    greenText();
    printf("[%d]", nRandom);
    resetText();
    printf(" runes!\n");
    printf("\t\t\t\t\t\t\t╚═════╝\n\n");
    printf("\t\t\t\t\t\t\t    [PRESS ANY KEY TO CONTINUE]");
    scanf(" %c", &cInput);
}

void enemySprite()
{
        printf("\t\t\t\t\t\t\t\t\t┌───────────┐\n");
        printf("\t\t\t\t\t\t\t\t\t│ \x1b[38;5;9m╔═══════╗\x1b[0m │\n");
        printf("\t\t\t\t\t\t\t\t\t│ \x1b[38;5;9m║\x1b[0m ▄███▄ \x1b[38;5;9m║\x1b[0m │\n");
        printf("\t\t\t\t\t\t\t\t\t│ \x1b[38;5;9m║\x1b[0m █\x1b[38;5;9m█\x1b[0m█\x1b[38;5;9m█\x1b[0m█ \x1b[38;5;9m║\x1b[0m │\n");
        printf("\t\t\t\t\t\t\t\t\t│ \x1b[38;5;9m║\x1b[0m █▀█▀█ \x1b[38;5;9m║\x1b[0m │\n");
        printf("\t\t\t\t\t\t\t\t\t│ \x1b[38;5;9m╚═══════╝\x1b[0m │\n");
        printf("\t\t\t\t\t\t\t\t\t└───────────┘");
}



/*

▄███▄ 
█ █ █ 
█▀█▀█ 
 
    printf("\t┌───────────┐\n");
    printf("\t│ \x1b[38;5;33m╔═══════╗\x1b[0m │\n");
    printf("\t│ \x1b[38;5;33m║\x1b[0m ▄███▄ \x1b[38;5;33m║\x1b[0m │\n");
    printf("\t│ \x1b[38;5;33m║\x1b[0m █\x1b[38;5;33m█\x1b[0m█\x1b[38;5;33m█\x1b[0m█ \x1b[38;5;33m║\x1b[0m │\n");
    printf("\t│ \x1b[38;5;33m║\x1b[0m  ▀▀▀ \x1b[38;5;33m║\x1b[0m │\n");
    printf("\t│ \x1b[38;5;33m╚═══════╝\x1b[0m │\n");
    printf("\t└───────────┘");

 ▄███▄
 █ █ █ 
  ▀▀▀

*/
