#include "combat.h"

void runCombat(Player* pPlayer, Area* pArea, int* pMaxHealth, int nFloorType, int* pShard)
{
    char cContinue;
    int nRandom, nPlayerMove, nReward, nDodge;
    int nTurn = 0;
    Enemy sEnemy;

    srand(time(NULL));

    if(nFloorType == 0){
        nRandom = (rand() % 3) + 1;
        initializeEnemy(&sEnemy, pArea, nRandom);
        nReward = sEnemy.nHealth * 2;
    }
    else if(nFloorType == 1){
        initializeBoss(&sEnemy, pArea);
        nReward = sEnemy.nHealth * 5;
    }
        else if(nFloorType == 2){
            pArea->nAreaIndex += 1;
            initializeBoss(&sEnemy, pArea);
            pArea->nAreaIndex -= 1;
            nReward = sEnemy.nHealth * 5;
        }

    printf("\n\n");

    printf("BATTLING [%s]\n", sEnemy.strEnemyName);
    printf("\n");

    /*
                                                                                                                             
▀███▀▀▀███▀███▄   ▀███▀███▀▀▀███▀████▄     ▄███▀███▀   ▀██▀   ▀███▀▀▀██████▀▀▀███▀████▀   ▀████▀   ▀███▀▀▀███▀███▀▀▀██▄  


  ██     ▄█ █     ███   ██     ▄█ █  ▀██▀   ██      ██          ██       ██     ▄█ ██    ▄█ ██    ▄█ ██     ▄█ ██    ▄██▀
▄█████████████▄    ██ ▄█████████████▄ ▀▀  ▄████▄  ▄████▄      ▄████▄   ▄██████████████████████████████████████████████▀  
                                                                                                                         
                                                                                                                         

    */

    while(sEnemy.nHealth != 0 && *pMaxHealth != 0){

        if(nTurn % 2 == 0)
            playerTurn(&nTurn, &nDodge, &nPlayerMove, pMaxHealth, nFloorType, &sEnemy, pArea, pPlayer); 
        else 
            enemyTurn(nDodge, &nPlayerMove, pMaxHealth, sEnemy);
        
        if(sEnemy.nHealth == 0){
            greenText();

            if(nFloorType == 0){
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
            else{
                printf("\n[GREAT ENEMY FELLED]\n");
                *pShard = 1;
            }

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
            pArea->nFlag2 = 1;
        }

        nTurn++;

    }
}

void playerTurn(int* pTurn, int* pDodge, int* pPlayerMove, int* pMaxHealth, int nFloorType, Enemy* pEnemy, Area* pArea, Player* pPlayer)
{
    char cInput;
    int nTemp, nRandom, nMaxHealthLower, nMaxHealthUpper;
    int nTempMaxHealth = 100 * ((pPlayer->stats.health + pPlayer->equippedWeapon->nHp) / 2);
    *pDodge = 0;

    srand(time(NULL));

    if(nFloorType == 0)
        pEnemy->nDamage = (rand() % (pEnemy->nAttackUpper - pEnemy->nAttackLower) + pEnemy->nAttackLower) * pArea->nAreaIndex;
    else
        pEnemy->nDamage = (rand() % (pEnemy->nAttackUpper - pEnemy->nAttackLower) + pEnemy->nAttackLower);

    do {

        printf("\nPlayer Turn\n");
        printf("[%s]: %d [", pPlayer->name, *pMaxHealth);
        displayHealthbar(nTempMaxHealth, *pMaxHealth);
        printf("]\n[POTIONS]: %d\n", pPlayer->nPotions);
        printf("[%s]: %d [", pEnemy->strEnemyName, pEnemy->nHealth);
        displayHealthbar(pEnemy->nMaxHealth, pEnemy->nHealth);
        printf("]\n[INCOMING ENEMY DAMAGE]: %d", pEnemy->nDamage);

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

            if(cInput != '0'){

                *pPlayerMove = processAttack(cInput, pPlayer, pEnemy);
                pEnemy->nHealth -= *pPlayerMove;

                if(pEnemy->nHealth < 0)
                    pEnemy->nHealth = 0;

                printf("\nYou dealt [%d] damage!\n", *pPlayerMove);

            }
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

                nTemp = 100 * ((pPlayer->stats.health + pPlayer->equippedWeapon->nHp) / 2);

                if(pPlayer->nPotions == 0){
                    printf("\nNo potions left!\n");
                    break;
                }
                else if(*pMaxHealth < nTemp){

                nMaxHealthLower = nTemp * 0.25;
                nMaxHealthUpper = nTemp * 0.50;
                nRandom = (rand() % (nMaxHealthUpper - nMaxHealthLower) + nMaxHealthLower);
                *pMaxHealth += nRandom;   

                printf("\n[%s] HEALED FOR %d\n", pPlayer->name, nRandom);

                if(*pMaxHealth > nTemp)
                    *pMaxHealth = nTemp;
                
                pPlayer->nPotions--;

                }
                    else
                        printf("\n[YOU ARE ALREADY AT MAXIMUM HEALTH]\n"); // 80 max 100 heal for 40 real heal 20

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

    switch(nRandom){ 
        case 1:
            pEnemy->nHealth = (rand() % (30 - 20) + 20) * pArea->nAreaIndex; //rand() % (upper bound - lower bound) + lower bound
            pEnemy->nMaxHealth = pEnemy->nHealth;
            pEnemy->fPhysDef = 0.20;
            pEnemy->fSorcDef = 0.15;
            pEnemy->fIncantDef = 0.10;
            pEnemy->nAttackUpper = 80;
            pEnemy->nAttackLower = 70;
            strcpy(pEnemy->strEnemyName, pArea->strEnemy1);
            break;
        case 2:
            pEnemy->nHealth = (rand() % (35 - 25) + 25) * pArea->nAreaIndex;
            pEnemy->nMaxHealth = pEnemy->nHealth;
            pEnemy->fPhysDef = 0.50;
            pEnemy->fSorcDef = 0.15;
            pEnemy->fIncantDef = 0.20;
            pEnemy->nAttackUpper = 120;
            pEnemy->nAttackLower = 110;
            strcpy(pEnemy->strEnemyName, pArea->strEnemy2);
            break;
        case 3:
            pEnemy->nHealth = (rand() % (80 - 70) + 70) * pArea->nAreaIndex;
            pEnemy->nMaxHealth = pEnemy->nHealth;
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
            return (pPlayer->stats.strength + pPlayer->equippedWeapon->nStr) * (1 - pEnemy->fPhysDef);
            break;
        case '2':
            return (pPlayer->stats.intelligence + pPlayer->equippedWeapon->nInt) * (1 - pEnemy->fSorcDef);
            break;
        case '3':
            return (pPlayer->stats.faith + pPlayer->equippedWeapon->nFth) * (1 - pEnemy->fIncantDef);
            break;
        default:
            return 0;
            break;
    }
}

void initializeBoss(Enemy* pEnemy, Area* pArea)
{
    switch(pArea->nAreaIndex){
        case 1: 
            pEnemy->nHealth = 200;
            pEnemy->nMaxHealth = pEnemy->nHealth;
            pEnemy->fPhysDef = 0.35;
            pEnemy->fSorcDef = 0.20;
            pEnemy->fIncantDef = 0.15;
            pEnemy->nAttackUpper = 300;
            pEnemy->nAttackLower = 150;
            strcpy(pEnemy->strEnemyName, "GODRICK THE GRAFTED");
            break;
        case 2:
            pEnemy->nHealth = 400;
            pEnemy->nMaxHealth = pEnemy->nHealth;
            pEnemy->fPhysDef = 0.15;
            pEnemy->fSorcDef = 0.35;
            pEnemy->fIncantDef = 0.25;
            pEnemy->nAttackUpper = 300;
            pEnemy->nAttackLower = 200;
            strcpy(pEnemy->strEnemyName, "RENNALA");
            break;
        case 3:
            pEnemy->nHealth = 600;
            pEnemy->nMaxHealth = pEnemy->nHealth;
            pEnemy->fPhysDef = 0.30;
            pEnemy->fSorcDef = 0.20;
            pEnemy->fIncantDef = 0.20;
            pEnemy->nAttackUpper = 400;
            pEnemy->nAttackLower = 200;
            strcpy(pEnemy->strEnemyName, "RADAHN");
            break;
        case 4:
            pEnemy->nHealth = 600;
            pEnemy->nMaxHealth = pEnemy->nHealth;
            pEnemy->fPhysDef = 0.15;
            pEnemy->fSorcDef = 0.25;
            pEnemy->fIncantDef = 0.30;
            pEnemy->nAttackUpper = 350;
            pEnemy->nAttackLower = 250;
            strcpy(pEnemy->strEnemyName, "RYKARD");
            break;
        case 5:
            pEnemy->nHealth = 800;
            pEnemy->nMaxHealth = pEnemy->nHealth;
            pEnemy->fPhysDef = 0.35;
            pEnemy->fSorcDef = 0.30;
            pEnemy->fIncantDef = 0.20;
            pEnemy->nAttackUpper = 500;
            pEnemy->nAttackLower = 250;
            strcpy(pEnemy->strEnemyName, "MORGOTT");
            break;
        case 6:
            pEnemy->nHealth = 1000;
            pEnemy->nMaxHealth = pEnemy->nHealth;
            pEnemy->fPhysDef = 0.35;
            pEnemy->fSorcDef = 0.25;
            pEnemy->fIncantDef = 0.40;
            pEnemy->nAttackUpper = 600;
            pEnemy->nAttackLower = 300;
            strcpy(pEnemy->strEnemyName, "RADAGON");
            break;
        case 7:
            pEnemy->nHealth = 1250;
            pEnemy->nMaxHealth = pEnemy->nHealth;
            pEnemy->fPhysDef = 0.25;
            pEnemy->fSorcDef = 0.50;
            pEnemy->fIncantDef = 0.40;
            pEnemy->nAttackUpper = 900;
            pEnemy->nAttackLower = 450;
            strcpy(pEnemy->strEnemyName, "ELDEN BEAST");
            break;
    }
}

void displayHealthbar(int nMaxHealth, int nCurrentHealth)
{
    float fMilestone = nMaxHealth / 20.0f;
    float fCounter = 0.0f;
    
    for(int i = 0; i < 20; i++){
        if(fCounter < nCurrentHealth){
            fCounter += fMilestone;
            redText();
            printf("█");
            resetText();
        }

        else{
            printf(" ");
        }
    }
}