#include "combat.h"
#include "color.h"

#include "structures.h"
#include "definitions.h"

void runCombat(Player* pPlayer)
{
    int aPlayerOptions[3] = {1,0,0};
    int nTurn = 0;
    char cInput;

    for(int nFlag = 0; nFlag != 1; nTurn++){
        if(nTurn % 2 == 0){
            printf("\nPlayer Turn\n");
        }
        else 
            printf("\nEnemy Turn\n");

        printOption(aPlayerOptions); // printCombatScreen(); 
        scanf(" %c", &cInput);
        processOption(cInput, aPlayerOptions, 3, &nTurn);

        for(int i = 0; i < 3; i++){
            printf("%d ", aPlayerOptions[i]);
        }
        if(cInput == '0')
            nFlag = 1;
    }
}

void printCombatScreen(Player* pPlayer)
{

}

void printOption(int* pPlayerOptions)
{

    for(int i = 0; i < 3; i++){
        if(pPlayerOptions[i] == 1){
            printf("\x1b[38;5;34m");
            printf("╔══════════════╗");
            printf("\x1b[0m");
        }
        else if(pPlayerOptions[i] == 0)
            printf("┌──────────────┐");
    }

    printf("\n");

    for(int i = 0; i < 3; i++){
        if(pPlayerOptions[i] == 1){
            greenText();
            printf("║");
            assessOption(i);
            printf("║");
            resetText();
        }
        else if(pPlayerOptions[i] == 0){
            printf("│");
            assessOption(i);
            printf("│");
        }
    }

    printf("\n");

    for(int i = 0; i < 3; i++){
        if(pPlayerOptions[i] == 1){
            printf("\x1b[38;5;34m");
            printf("╚══════════════╝");
            printf("\x1b[0m");
        }
        else if(pPlayerOptions[i] == 0)
            printf("└──────────────┘");
    }

}

void assessOption(int nX)
{
    if(nX == 0)
        printf("    ATTACK    ");
    else if(nX == 1)
        printf("  DODGE ROLL  ");
    else if(nX == 2)
        printf(" DRINK POTION ");
}

void processOption(char cInput, int* pPlayerOptions, int nSize, int* nTurn)
{
    for(int i = 0; i < nSize; i++){
        if(pPlayerOptions[i] == 1){
            switch(cInput){
                case 'a':
                case 'A':
                    if(i == 0)
                        break;
                    else{
                        pPlayerOptions[i]--;
                        pPlayerOptions[i-1]++;
                        *nTurn -= 1;
                    }
                    break;
                case 'd':
                case 'D':
                    if(i == 2)
                        break;
                    else{
                        pPlayerOptions[i]--;
                        i++;
                        pPlayerOptions[i]++;
                        *nTurn -= 1;
                    }
                    break;
                case 'e':
                case 'E':


            }
        }
    }
}