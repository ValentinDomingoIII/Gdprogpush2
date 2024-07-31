#include "combat.h"

void runCombat(Player* pPlayer, Area* pArea, int* pMaxHealth)
{
    char cContinue;
    int nRandom, nPlayerMove, nReward, nDodge;
    Enemy sEnemy;

    srand(time(NULL));
    nRandom = (rand() % 3) + 1;
    initializeEnemy(&sEnemy, pArea, nRandom);
    nReward = sEnemy.nHealth * 2;

    printf("\n\n");
    printf("[Weapon Stat]: %d\n", pPlayer->inventory->nStr);

    printf("You have encountered [%s]\n", sEnemy.strEnemyName);
    printf("\n[ENEMY HEALTH]: %d", sEnemy.nHealth);
    printf("\n[PHYS RES]: %.2f\n[SORC DEF]: %.2f\n[INCANT DEF]: %.2f",sEnemy.fPhysDef, sEnemy.fSorcDef, sEnemy.fIncantDef);
    printf("\n");

    for(int nTurn = 0; sEnemy.nHealth != 0 && *pMaxHealth != 0; nTurn++){
        if(nTurn % 2 == 0)
            playerTurn(&nDodge, &nPlayerMove, pMaxHealth, &sEnemy, pArea, pPlayer); 
        else 
            enemyTurn(nDodge, &nPlayerMove, pMaxHealth, sEnemy);
        
        if(sEnemy.nHealth == 0){
            greenText();
            printf("\n[ENEMY FELLED]\n");
            resetText();
            printf("\n[RUNES EARNED]: %d\n", nReward);
            pPlayer->runes += nReward;
            printf("\n[PRESS ANY KEY TO CONTINUE]");
            scanf(" %c", &cContinue);

        }
        else if(*pMaxHealth == 0){
            redText();
            printf("\n[YOU DIED]\n");
            resetText();
            printf("\n[PRESS ANY KEY TO CONTINUE]");
            scanf(" %c", &cContinue);
            pPlayer->runes = 0;
            pArea->nFlag = 1;
        }
    }
}

void playerTurn(int* pDodge, int* pPlayerMove, int* pMaxHealth, Enemy* pEnemy, Area* pArea, Player* pPlayer)
{
    char cInput;
    int nTemp, nRandom;
    *pDodge = 0;

    srand(time(NULL));

    pEnemy->nDamage = (rand() % (pEnemy->nAttackUpper - pEnemy->nAttackLower) + pEnemy->nAttackLower) * pArea->nAreaIndex;

    do {

        printf("\nPlayer Turn\n");
        printf("[%s]: %d\n", pPlayer->name, *pMaxHealth);
        printf("[POTIONS]: %d\n", pPlayer->nPotions);
        printf("[%s]: %d", pEnemy->strEnemyName, pEnemy->nHealth);
        printf("\n[INCOMING ENEMY DAMAGE]: %d", pEnemy->nDamage);

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

            *pPlayerMove = processAttack(cInput, pPlayer, pEnemy);
            pEnemy->nHealth -= *pPlayerMove;

            if(pEnemy->nHealth < 0)
                pEnemy->nHealth = 0;

            printf("\nYou dealt [%d] damage!\n", *pPlayerMove);
        }

        else if(cInput == '2'){

            nTemp = pPlayer->stats.endurance + pPlayer->equippedWeapon->nEnd;
            nTemp = (20 + (nTemp / 2));
            nRandom = (rand() % 100) + 1;
            if(nRandom <= nTemp)
                *pDodge = 1;
            else
                *pDodge = 2;
            
            // printf("nRandom: [%d]\nnTemp: [%d]", nRandom, nTemp);
            printf("\n[%s] DODGED!\n", pPlayer->name);
            
        }

            else if(cInput == '3'){

                if(pPlayer->nPotions == 0){
                    printf("\nNo potions left!\n");
                    break;
                }
                else{

                pPlayer->nPotions--;
                //equation for potion

                }

            }

    } while(cInput == '0' || cInput == '3');
}

void enemyTurn(int nDodge, int* pPlayerMove, int* pMaxHealth, Enemy sEnemy)
{
    if(nDodge == 1)
        printf("\n[%s] MISSED!\n", sEnemy.strEnemyName);
    else if(nDodge == 2){
        printf("DODGE FAILED\n\n[%s] DEALT\n[DAMAGE]: %d\n", sEnemy.strEnemyName, sEnemy.nDamage);
        *pMaxHealth -= sEnemy.nDamage; 
    }
        else if(nDodge == 0){
            printf("\n[%s] DEALT\n[DAMAGE]: %d\n", sEnemy.strEnemyName, sEnemy.nDamage);
            *pMaxHealth -= sEnemy.nDamage; 
        }
    
    if(*pMaxHealth < 0)
            *pMaxHealth = 0;
    
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
        default:
            return 0;
            break;
    }
}


