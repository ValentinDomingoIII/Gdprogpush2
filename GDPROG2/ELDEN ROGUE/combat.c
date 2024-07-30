#include "stddef.h"

#include "combat.h"
#include "color.h"

#include "structures.h"
#include "definitions.h"

void runCombat(Player* pPlayer, Area* pArea, int* pMaxHealth)
{
    int nFlag = 0;
    int nRandom;
    Enemy sEnemy;

    srand(time(NULL));
    nRandom = (rand() % 3) + 1;
    initializeEnemy(&sEnemy, pArea, nRandom);

    printf("[HEALTH]: %d", *pMaxHealth);
    printf("\n\n");
    printf("[Weapon Stat]: %d\n", pPlayer->inventory->nStr);

    printf("You have encountered [%s]\n", sEnemy.strEnemyName);
    printf("\n[ENEMY HEALTH]: %d", sEnemy.nHealth);
    printf("\n[PHYS RES]: %.2f\n[SORC DEF]: %.2f\n[INCANT DEF]: %.2f",sEnemy.fPhysDef, sEnemy.fSorcDef, sEnemy.fIncantDef);
    printf("\n");

    for(int nTurn = 0; nFlag != 1; nTurn++){
        if(nTurn % 2 == 0)
            playerTurn(&nFlag, &sEnemy, pArea, pPlayer); 
        else 
            printf("\nEnemy Turn\n");
    }
}

void playerTurn(int* nFlag, Enemy* pEnemy, Area* pArea, Player* pPlayer)
{
    char cInput;
    int nPlayerMove;

    srand(time(NULL));

    pEnemy->nDamage = (rand() % (pEnemy->nAttackUpper - pEnemy->nAttackLower) + pEnemy->nAttackLower) * pArea->nAreaIndex;
    printf("\nPlayer Turn\n");
    printf("\n[INCOMING ENEMY DAMAGE]: %d", pEnemy->nDamage);

    do {
        do {

            printf("\n[1]: ATTACK\n");
            printf("[2]: DODGE\n");
            printf("[3]: POTION\n");
            printf("\n[INPUT]: ");

            scanf(" %c", &cInput);

        } while(cInput != '1' && cInput != '2' && cInput != '3');

        if(cInput == '1'){
            do {
                printf("\n[1]: PHYSICAL\n");
                printf("[2]: SORCERY\n");
                printf("[3]: INCANTATION\n");
                printf("[0]: BACK\n");
                printf("\n[INPUT]: ");

                scanf(" %c", &cInput);
            } while(cInput != '0' && cInput != '1' && cInput != '2' && cInput != '3');

            nPlayerMove = processAttack(cInput, pPlayer, pEnemy);
            pEnemy->nHealth -= nPlayerMove;
            printf("\nYou dealt [%d] damage!\n", nPlayerMove);
        }

    } while(cInput == '0' || cInput == '3');
}

void initializeEnemy(Enemy* pEnemy, Area* pArea, int nRandom)
{
    // int nStat;
    srand(time(NULL));

    switch(nRandom){ //attack is randomized within the range every turn //might make it in another function
        case 1:
            pEnemy->nHealth = (rand() % (30 - 20) + 20) * pArea->nAreaIndex; //rand() % (upper bound - lower bound) + lower bound
            pEnemy->fPhysDef = 0.20;
            pEnemy->fSorcDef = 0.15;
            pEnemy->fIncantDef = 0.10;
            pEnemy->nAttackUpper = 80;
            pEnemy->nAttackLower = 70;
            strcpy(pEnemy->strEnemyName, pArea->strEnemy1);
            break;
        case 2:
            pEnemy->nHealth = (rand() % (35 - 25) + 25) * pArea->nAreaIndex;
            pEnemy->fPhysDef = 0.50;
            pEnemy->fSorcDef = 0.15;
            pEnemy->fIncantDef = 0.20;
            pEnemy->nAttackUpper = 120;
            pEnemy->nAttackLower = 110;
            strcpy(pEnemy->strEnemyName, pArea->strEnemy2);
            break;
        case 3:
            pEnemy->nHealth = (rand() % (80 - 70) + 70) * pArea->nAreaIndex;
            pEnemy->fPhysDef = 0.25;
            pEnemy->fSorcDef = 0.25;
            pEnemy->fIncantDef = 0.20;
            pEnemy->nAttackUpper = 130;
            pEnemy->nAttackLower = 120;
            strcpy(pEnemy->strEnemyName, pArea->strEnemy3);
            break;
    }
}

int processAttack(char cInput, Player* pPlayer, Enemy* pEnemy)
{
    switch(cInput){
        case '1':
            return (pPlayer->stats.strength + pPlayer->inventory->nStr) * (1 - pEnemy->fPhysDef);
            break;
        case '2':
            return (pPlayer->stats.intelligence + pPlayer->inventory->nInt) * (1 - pEnemy->fSorcDef);
            break;
        case '3':
            return (pPlayer->stats.faith + pPlayer->inventory->nFth) * (1 - pEnemy->fIncantDef);
            break;
    }
}


