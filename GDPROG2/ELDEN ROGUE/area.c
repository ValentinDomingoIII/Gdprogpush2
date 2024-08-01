#include "area.h"
#include "combat.h"
#include "round_table.h"
#include "character_creation.h"
#include "color.h"
#include "string.h"

#include "structures.h"
#include "definitions.h"

// NULL TILE = -1
// EMPTY TILE = 0
// PLAYER TILE = [SELECTED TILE] + 1
// SPAWN TILE = 2
// BOSS TILE = 4
// DOOR TILE = 6
// FAST TRAVEL = 8 Starting Area | 10 Boss Area
// CREDITS TILE = 12

void runArea(Area* pArea, Array sCoordinate, Player* pPlayer, int* pShard, int* pMaxHealth)
{
     char cInput; 

     do{
     
     // areaScreen(sArea->strAreaName);
     printFloor(pArea, sCoordinate);
     printf("\n[RUNES]: %d\t[INPUT]: ", pPlayer->runes);
     scanf(" %c", &cInput);
     printf("\n");
     processInput(cInput, pArea, sCoordinate, pPlayer, pShard, pMaxHealth); 

     } while(pArea->nFlag2 != 1);

}

void areaScreen(char* strAreaName)
{
     printf("╔═");
     for(int i = 0; i < strlen(strAreaName); i++)
          printf("═");
     printf("═╗");
     printf("\n");
     printf("║ ");
     printf("%s", strAreaName);
     printf(" ║");
     printf("\n");
     printf("╚═");
     for(int i = 0; i < strlen(strAreaName); i++)
          printf("═");
     printf("═╝");
     printf("\n");
}

void printFloor(Area* pArea, Array sCoordinate) 
{

     for (int i = sCoordinate.nRowOffset; i < sCoordinate.nRowSize + sCoordinate.nRowOffset; i++){
          // tabRepeat(50);
          
          for (int j = 0; j < sCoordinate.nColumnSize; j++){
               
               if(pArea->aBigArray[i][j] == 0){
                    grayText();
                    printf("┌───┐");
                    resetText();
               }
               else if(pArea->aBigArray[i][j] % 2 == 1){
                    pinkText();
                    printf("╔═══╗");
                    resetText();
               }
                    else if(pArea->aBigArray[i][j] == 2){
                         blueText();
                         printf("┌───┐");
                         resetText();
                    }
                         else if(pArea->aBigArray[i][j] == 4){
                              redText();
                              printf("┌───┐");
                              resetText();
                         }
                              else if(pArea->aBigArray[i][j] == 6 || pArea->aBigArray[i][j] >= 50){
                                   yellowText();
                                   printf("┌───┐");
                                   resetText();
                              }
                                   else if(pArea->aBigArray[i][j] == 8 || pArea->aBigArray[i][j] == 10){
                                        greenText();
                                        printf("┌───┐");
                                        resetText();
                                   }
                                        else if(pArea->aBigArray[i][j] == -1){
                                             printf("     ");
                                        }
                                             else if(pArea->aBigArray[i][j] == 12){
                                                  purpleText();
                                                  printf("┌───┐");
                                                  resetText();
                                             }

          }

          printf("\n");
          // tabRepeat(50);

          for (int j = 0; j < sCoordinate.nColumnSize; j++){
               
               if(pArea->aBigArray[i][j] == 0){
                    grayText();
                    printf("│   │");
                    resetText();
               }
               else if(pArea->aBigArray[i][j] % 2 == 1){
                    pinkText();
                    printf("║   ║");
                    resetText();
               }
                    else if(pArea->aBigArray[i][j] == 2){
                         blueText();
                         printf("│   │");
                         resetText();
                    }
                         else if(pArea->aBigArray[i][j] == 4){
                                   redText();
                                   printf("│   │");
                                   resetText();
                         }
                              else if(pArea->aBigArray[i][j] == 6 || pArea->aBigArray[i][j] >= 50){
                                   yellowText();
                                   printf("│   │");
                                   resetText();
                              }
                                   else if(pArea->aBigArray[i][j] == 8 || pArea->aBigArray[i][j] == 10){
                                        greenText();
                                        printf("│   │");
                                        resetText();
                                   }
                                        else if(pArea->aBigArray[i][j] == -1){
                                             printf("     ");
                                        }
                                             else if(pArea->aBigArray[i][j] == 12){
                                                  purpleText();
                                                  printf("│   │");
                                                  resetText();
                                             }
          }

          printf("\n");
          // tabRepeat(50);

          for (int j = 0; j < sCoordinate.nColumnSize; j++){
               
               if(pArea->aBigArray[i][j] == 0){
                    grayText();
                    printf("└───┘");
                    resetText();
               }
               else if(pArea->aBigArray[i][j] % 2 == 1){
                    pinkText();
                    printf("╚═══╝");
                    resetText();
               }
                    else if(pArea->aBigArray[i][j] == 2){
                         blueText();
                         printf("└───┘");
                         resetText();
                    }
                         else if(pArea->aBigArray[i][j] == 4){
                                   redText();
                                   printf("└───┘");
                                   resetText();
                         }
                              else if(pArea->aBigArray[i][j] == 6 || pArea->aBigArray[i][j] >= 50){
                                   yellowText();
                                   printf("└───┘");
                                   resetText();
                              }
                                   else if(pArea->aBigArray[i][j] == 8 || pArea->aBigArray[i][j] == 10){
                                        greenText();
                                        printf("└───┘");
                                        resetText();
                                   }
                                        else if(pArea->aBigArray[i][j] == -1){
                                             printf("     ");
                                        }
                                            else if(pArea->aBigArray[i][j] == 12){
                                                  purpleText();
                                                  printf("└───┘");
                                                  resetText();
                                             } 
          }

          printf("\n");
          
     }

}

void processInput(char cInput, Area* pArea, Array sCoordinate, Player* pPlayer, int* pShard, int* pMaxHealth) 
{
     int nRandom;
     char cDoorInput;
     srand(time(NULL));

     for(int i = sCoordinate.nRowOffset; i < sCoordinate.nRowSize + sCoordinate.nRowOffset; i++){
          for(int j = 0; j < sCoordinate.nColumnSize; j++){
               if(pArea->aBigArray[i][j] % 2 == 1){
                    switch(cInput){
                         case 'W':
                         case 'w': 
                              if(i == sCoordinate.nRowOffset)
                                   break;
                              else if(pArea->aBigArray[i-1][j] == -1)
                                   break;
                                   else{
                                        pArea->aBigArray[i][j]--;
                                        i--;
                                        pArea->aBigArray[i][j]++;
                                   }
                              break;

                         case 'D':
                         case 'd':
                              if(j == sCoordinate.nColumnSize-1)
                                   break;
                              else if(pArea->aBigArray[i][j+1] == -1)
                                   break;
                                   else{
                                        pArea->aBigArray[i][j] -= 1;
                                        j++;
                                        pArea->aBigArray[i][j] += 1;
                                   }
                              break;
                         case 'A':
                         case 'a':
                              if(j == 0)
                                   break;
                              else if(pArea->aBigArray[i][j-1] == -1)
                                   break;
                                   else{
                                        pArea->aBigArray[i][j] -= 1;
                                        j--;
                                        pArea->aBigArray[i][j] += 1;
                                   }
                              break;
                         case 'S':
                         case 's':
                              if(i == (sCoordinate.nRowSize + sCoordinate.nRowOffset)-1)
                                   break;
                              else if(pArea->aBigArray[i+1][j] == -1)
                                   break;
                                   else{
                                        pArea->aBigArray[i][j] -= 1;
                                        i++;
                                        pArea->aBigArray[i][j] += 1;
                                   }
                              break;
                         case 'E': 
                         case 'e':
                              if(pArea->aBigArray[i][j] == 1) // normal tile
                                   break;
                              else if(pArea->aBigArray[i][j] == 3){ //spawn tile
                                   nRandom = (rand() % 4) + 1;
                                        if(pArea->nAreaIndex != 6){
                                             if(nRandom == 1){
                                                  nRandom = rand() % (150 - 50) + 50; 
                                                  nRandom *= pArea->nAreaIndex;
                                                  pPlayer->runes = pPlayer->runes + nRandom;
                                                  printf("You obtained [%d] Runes!\n", nRandom);
                                             } 
                                             else
                                                  runCombat(pPlayer, pArea, pMaxHealth, 0, pShard);
                                        }
                                        else{
                                             nRandom = pArea->nAreaIndex * (rand() % (150 - 50) + 50); 
                                             printf("You obtained [%d] Runes!\n", nRandom);
                                        }
                                   pArea->aBigArray[i][j] = 1;
                              }
                                   else if(pArea->aBigArray[i][j] == 5){
                                        if(pArea->nAreaIndex == 6){
                                             runCombat(pPlayer, pArea, pMaxHealth, 1, pShard);
                                             runCombat(pPlayer, pArea, pMaxHealth, 2, pShard);
                                        }
                                        runCombat(pPlayer, pArea, pMaxHealth, 1, pShard);
                                        pArea->aBigArray[i][j] = 1;
                    
                                   }
                                   else if(pArea->aBigArray[i][j] == 9 || pArea->aBigArray[i][j] == 11){ 
                                             if(pArea->aBigArray[i][j] == 11 && *pShard != 1)
                                                  printf("Fast Travel Unavailable! You must have this area's shard.\n");
                                             else{
                                                  do {
                                                       printf("Return to Roundtable Hold?\n\n");
                                                       printf("[1] YES\n");
                                                       printf("[2] NO\n\n");
                                                       printf("[INPUT]: ");
                                                       scanf(" %c", &cDoorInput);
                                                  } while (cDoorInput != '1' && cDoorInput != '2');
                                                  if(cDoorInput == '1'){
                                                       pArea->nFlag = 1;
                                                       pArea->nFlag2 = 1;
                                                  }
                                             }
                                   }
                                        else if(pArea->aBigArray[i][j] >= 50){
                                             pArea->aBigArray[i][j] -= 1;
                                             pPlayer->sLocation.nCurrentRow = i;
                                             pPlayer->sLocation.nCurrentColumn = j;
                                             pArea->nFlag2 = 1;
                                        }
                                             
                    }
               }
          }
     }

}

void floorPass(Player* pPlayer, Area* pArea, int* pShard)
{
     int nValue;
     int nMaxHealth = 100 * ((pPlayer->stats.health + pPlayer->equippedWeapon->nHp) / 2);

     switch(pArea->nFloorChoice){
          case 1:
               nValue = 50;
               break;
          case 2:
               if(pArea->nAreaIndex == 1)
                    nValue = 54;
               else if(pArea->nAreaIndex == 2)
                    nValue = 58;
                    else if(pArea->nAreaIndex == 3 || pArea->nAreaIndex == 4)
                         nValue = 62;
                         else if(pArea->nAreaIndex == 5)
                              nValue = 76;
               break;
     }
     
     for(int i = 0; pArea->nFlag != 1; i++){
          pArea->nFlag2 = 0; 

          switch(nValue){
               case 50: //floor 1
                    if(i != 0)
                         findDoor(pPlayer, pArea, pArea->a1, nValue);
                    runArea(pArea, pArea->a1, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 50;
                    break;
               case 52: //floor 2
                    findDoor(pPlayer, pArea, pArea->a2, nValue);
                    runArea(pArea, pArea->a2, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 52;
                    break;
               case 54: //floor 3
                    if(i != 0)
                         findDoor(pPlayer, pArea, pArea->a3, nValue);
                    runArea(pArea, pArea->a3, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 54;
                    break;
               case 56: //floor 4
                    findDoor(pPlayer, pArea, pArea->a4, nValue);
                    runArea(pArea, pArea->a4, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 56;
                    break;
               case 58: //floor 5
                    if(i != 0)
                         findDoor(pPlayer, pArea, pArea->a5, nValue);
                    runArea(pArea, pArea->a5, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 58;
                    break;
               case 60: //floor 6
                    findDoor(pPlayer, pArea, pArea->a6, nValue);
                    runArea(pArea, pArea->a6, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 60;
                    break;
               case 62: //floor 7
                    if(i != 0)
                         findDoor(pPlayer, pArea, pArea->a7, nValue);
                    runArea(pArea, pArea->a7, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 62;
                    break;
               case 64: //floor 8
                    findDoor(pPlayer, pArea, pArea->a8, nValue);
                    runArea(pArea, pArea->a8, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 64;
                    break;
               case 66: //floor 9
                    findDoor(pPlayer, pArea, pArea->a9, nValue);
                    runArea(pArea, pArea->a9, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 66;
                    break;
               case 68: //floor 10
                    findDoor(pPlayer, pArea, pArea->a10, nValue);
                    runArea(pArea, pArea->a10, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 68;
                    break;
               case 70: //floor 11
                    findDoor(pPlayer, pArea, pArea->a11, nValue);
                    runArea(pArea, pArea->a11, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 70;
                    break;
               case 72: //floor 12
                    findDoor(pPlayer, pArea, pArea->a12, nValue);
                    runArea(pArea, pArea->a12, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 72;
                    break;
               case 74: //floor 13
                    findDoor(pPlayer, pArea, pArea->a13, nValue);
                    runArea(pArea, pArea->a13, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 74;
                    break;
               case 76: //floor 14
                    if(i != 0)
                         findDoor(pPlayer, pArea, pArea->a14, nValue);
                    runArea(pArea, pArea->a14, pPlayer, pShard, &nMaxHealth);
                    nValue = pArea->aBigArray[pPlayer->sLocation.nCurrentRow][pPlayer->sLocation.nCurrentColumn];
                    pPlayer->sLocation.nPreviousFloor = 76;
                    break;
          }
               
     }
}

void findDoor(Player* pPlayer, Area* pArea, Array sCoordinate, int nValue)
{
     for(int i = sCoordinate.nRowOffset; i < sCoordinate.nRowSize + sCoordinate.nRowOffset; i++){
          for(int j = 0; j < sCoordinate.nColumnSize; j++){
               if(pArea->aBigArray[i][j] == pPlayer->sLocation.nPreviousFloor){
                    pArea->aBigArray[i][j] += 1;
               }
          }
     }
}

void initializeArea(int nRow, int nColumn, int nRowOffset, Area* pArea, int* pTemp)
{
    int k = 0;

    for(int i = nRowOffset; i < nRow + nRowOffset; i++, k++){
        for(int j = 0; j < nColumn; j++){
            pArea->aBigArray[i][j] = *((pTemp + k * nColumn) + j);
        }
    }

}

void areaSelect(char cAreaIndex, char cFastTravelTile, Player* pPlayer)
{
     Area sArea;
     sArea.nFlag = 0;

     switch(cAreaIndex){
        case '1':
            sArea.nAreaIndex = 1;
            sArea.nFloorCount = 3;

            int nSFirst[7][3] = STORMVEIL_F1;
            initializeArea(7,3,0,&sArea,(int *)nSFirst);
            sArea.a1.nRowSize = 7;
            sArea.a1.nColumnSize = 3;
            sArea.a1.nRowOffset = 0;

            int nSSecond[7][7] = STORMVEIL_F2;
            initializeArea(7,7,7,&sArea,(int *)nSSecond);
            sArea.a2.nRowSize = 7;
            sArea.a2.nColumnSize = 7;
            sArea.a2.nRowOffset = 7;

            int nSThird[7][5] = STORMVEIL_F3;
            initializeArea(7,5,14,&sArea,(int *)nSThird);
            sArea.a3.nRowSize = 7;
            sArea.a3.nColumnSize = 5;
            sArea.a3.nRowOffset = 14;

            strcpy(sArea.strEnemy1, "Godrick Soldier");
            strcpy(sArea.strEnemy2, "Godrick Archer");
            strcpy(sArea.strEnemy3, "Godrick Knight");

            if(cFastTravelTile == '1'){
               sArea.aBigArray[6][1] = 9; 
               sArea.nFloorChoice = 1;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nStormveil);
            }
            else{
               sArea.aBigArray[14][2] = 11;
               sArea.nFloorChoice = 2;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nStormveil);
            }

            break;

        case '2':
            sArea.nAreaIndex = 2;
            sArea.nFloorCount = 5;

            int nRFirst[5][5] = RAYA_LUCARIA_F1;
            initializeArea(5,5,0,&sArea,(int *)nRFirst);
            sArea.a1.nRowSize = 5;
            sArea.a1.nColumnSize = 5;
            sArea.a1.nRowOffset = 0;

            int nRSecond[7][3] = RAYA_LUCARIA_F2;
            initializeArea(7,3,5,&sArea,(int *)nRSecond);
            sArea.a2.nRowSize = 7;
            sArea.a2.nColumnSize = 3;
            sArea.a2.nRowOffset = 5;

            int nRThird[7][5] = RAYA_LUCARIA_F3;
            initializeArea(7,5,12,&sArea,(int *)nRThird);
            sArea.a3.nRowSize = 7;
            sArea.a3.nColumnSize = 5;
            sArea.a3.nRowOffset = 12;

            int nRFourth[5][6] = RAYA_LUCARIA_F4;
            initializeArea(5,6,19,&sArea,(int *)nRFourth);
            sArea.a4.nRowSize = 5;
            sArea.a4.nColumnSize = 6;
            sArea.a4.nRowOffset = 19;

            int nRFifth[8][7] = RAYA_LUCARIA_F5;
            initializeArea(8,7,24,&sArea,(int *)nRFifth);
            sArea.a5.nRowSize = 8;
            sArea.a5.nColumnSize = 7;
            sArea.a5.nRowOffset = 24;

            strcpy(sArea.strEnemy1, "Living Jar");
            strcpy(sArea.strEnemy2, "Glintstone Sorcerer");
            strcpy(sArea.strEnemy3, "Battlemage");

            if(cFastTravelTile == '1'){
               sArea.aBigArray[0][2] = 9;
               sArea.nFloorChoice = 1;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nRaya);
            }
            else{
               sArea.aBigArray[24][3] = 11;
               sArea.nFloorChoice = 2;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nRaya);
            }

            break;
          
        case '3':
            sArea.nAreaIndex = 3;
            sArea.nFloorCount = 7;

            int nRMFirst[3][5] = REDMANE_F1;
            initializeArea(3,5,0,&sArea,(int *)nRMFirst);
            sArea.a1.nRowSize = 3;
            sArea.a1.nColumnSize = 5;
            sArea.a1.nRowOffset = 0;

            int nRMSecond[3][7] = REDMANE_F2;
            initializeArea(3,7,3,&sArea,(int *)nRMSecond);
            sArea.a2.nRowSize = 3;
            sArea.a2.nColumnSize = 7;
            sArea.a2.nRowOffset = 3;

            int nRMThird[5][5] = REDMANE_F3;
            initializeArea(5,5,6,&sArea,(int *)nRMThird);
            sArea.a3.nRowSize = 5;
            sArea.a3.nColumnSize = 5;
            sArea.a3.nRowOffset = 6;

            int nRMFourth[5][7] = REDMANE_F4;
            initializeArea(5,7,11,&sArea,(int *)nRMFourth);
            sArea.a4.nRowSize = 5;
            sArea.a4.nColumnSize = 7;
            sArea.a4.nRowOffset = 11;

            int nRMFifth[3][5] = REDMANE_F5;
            initializeArea(3,5,16,&sArea,(int *)nRMFifth);
            sArea.a5.nRowSize = 3;
            sArea.a5.nColumnSize = 5;
            sArea.a5.nRowOffset = 16;

            int nRMSixth[9][4] = REDMANE_F6;
            initializeArea(9,4,19,&sArea,(int *)nRMSixth);
            sArea.a6.nRowSize = 9;
            sArea.a6.nColumnSize = 4;
            sArea.a6.nRowOffset = 19;

            int nRMSeventh[5][7] = REDMANE_F7;
            initializeArea(5,7,28,&sArea,(int *)nRMSeventh);
            sArea.a7.nRowSize = 5;
            sArea.a7.nColumnSize = 7;
            sArea.a7.nRowOffset = 28;

            strcpy(sArea.strEnemy1, "Radahn Soldier");
            strcpy(sArea.strEnemy2, "Radahn Archer");
            strcpy(sArea.strEnemy3, "Radahn Knight");

            if(cFastTravelTile == '1'){
               sArea.aBigArray[1][0] = 9;
               sArea.nFloorChoice = 1;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nRedmane);
            }
            else{
               sArea.aBigArray[30][6] = 11;
               sArea.nFloorChoice = 2;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nRedmane);
            }
          
            break;
          
        case '4':
            sArea.nAreaIndex = 4;
            sArea.nFloorCount = 7;

            int nVFirst[5][5] = VOLCANO_F1;
            initializeArea(5,5,0,&sArea,(int *)nVFirst);
            sArea.a1.nRowSize = 5;
            sArea.a1.nColumnSize = 5;
            sArea.a1.nRowOffset = 0;

            int nVSecond[7][7] = VOLCANO_F2;
            initializeArea(7,7,5,&sArea,(int *)nVSecond);
            sArea.a2.nRowSize = 7;
            sArea.a2.nColumnSize = 7;
            sArea.a2.nRowOffset = 5;

            int nVThird[5][5] = VOLCANO_F3;
            initializeArea(5,5,12,&sArea,(int *)nVThird);
            sArea.a3.nRowSize = 5;
            sArea.a3.nColumnSize = 5;
            sArea.a3.nRowOffset = 12;

            int nVFourth[5][7] = VOLCANO_F4;
            initializeArea(5,7,17,&sArea,(int *)nVFourth);
            sArea.a4.nRowSize = 5;
            sArea.a4.nColumnSize = 7;
            sArea.a4.nRowOffset = 17;

            int nVFifth[4][3] = VOLCANO_F5;
            initializeArea(4,3,22,&sArea,(int *)nVFifth);
            sArea.a5.nRowSize = 4;
            sArea.a5.nColumnSize = 3;
            sArea.a5.nRowOffset = 22;

            int nVSixth[8][3] = VOLCANO_F6;
            initializeArea(8,3,26,&sArea,(int *)nVSixth);
            sArea.a6.nRowSize = 8;
            sArea.a6.nColumnSize = 3;
            sArea.a6.nRowOffset = 26;

            int nVSeventh[7][5] = VOLCANO_F7;
            initializeArea(7,5,34,&sArea,(int *)nVSeventh);
            sArea.a7.nRowSize = 7;
            sArea.a7.nColumnSize = 5;
            sArea.a7.nRowOffset = 34;

            strcpy(sArea.strEnemy1, "Man-Serpent");
            strcpy(sArea.strEnemy2, "Mage-Serpent");
            strcpy(sArea.strEnemy3, "Abductor Virgin");

            if(cFastTravelTile == '1'){
               sArea.aBigArray[4][2] = 9;
               sArea.nFloorChoice = 1;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nVolcano);
            }
            else{
               sArea.aBigArray[34][2] = 11;
               sArea.nFloorChoice = 2;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nVolcano);
            }

            break;
        
        case '5':
            sArea.nAreaIndex = 5;
            sArea.nFloorCount = 14;

            int nLFirst[4][3] = LEYNDELL_F1;
            initializeArea(4,3,0,&sArea,(int *)nLFirst);
            sArea.a1.nRowSize = 4;
            sArea.a1.nColumnSize = 3;
            sArea.a1.nRowOffset = 0;

            int nLSecond[7][3] = LEYNDELL_F2;
            initializeArea(7,3,4,&sArea,(int *)nLSecond);
            sArea.a2.nRowSize = 7;
            sArea.a2.nColumnSize = 3;
            sArea.a2.nRowOffset = 4;

            int nLThird[5][5] = LEYNDELL_F3;
            initializeArea(5,5,11,&sArea,(int *)nLThird);
            sArea.a3.nRowSize = 5;
            sArea.a3.nColumnSize = 5;
            sArea.a3.nRowOffset = 11;

            int nLFourth[3][5] = LEYNDELL_F4;
            initializeArea(3,5,16,&sArea,(int *)nLFourth);
            sArea.a4.nRowSize = 3;
            sArea.a4.nColumnSize = 5;
            sArea.a4.nRowOffset = 16;

            int nLFifth[3][3] = LEYNDELL_F5;
            initializeArea(3,3,19,&sArea,(int *)nLFifth);
            sArea.a5.nRowSize = 3;
            sArea.a5.nColumnSize = 3;
            sArea.a5.nRowOffset = 19;

            int nLSixth[4][15] = LEYNDELL_F6;
            initializeArea(4,15,22,&sArea,(int *)nLSixth);
            sArea.a6.nRowSize = 4;
            sArea.a6.nColumnSize = 15;
            sArea.a6.nRowOffset = 22;

            int nLSeventh[7][3] = LEYNDELL_F7;
            initializeArea(7,3,26,&sArea,(int *)nLSeventh);
            sArea.a7.nRowSize = 7;
            sArea.a7.nColumnSize = 3;
            sArea.a7.nRowOffset = 26;

            int nLEighth[7][3] = LEYNDELL_F8;
            initializeArea(7,3,33,&sArea,(int *)nLEighth);
            sArea.a8.nRowSize = 7;
            sArea.a8.nColumnSize = 3;
            sArea.a8.nRowOffset = 33;

            int nLNinth[7][3] = LEYNDELL_F9; 
            initializeArea(7,3,40,&sArea,(int *)nLNinth);
            sArea.a9.nRowSize = 7;
            sArea.a9.nColumnSize = 3;
            sArea.a9.nRowOffset = 40;

            int nLTenth[4][15] = LEYNDELL_F10;
            initializeArea(4,15,47,&sArea,(int *)nLTenth);
            sArea.a10.nRowSize = 4;
            sArea.a10.nColumnSize = 15;
            sArea.a10.nRowOffset = 47;

            int nLEleventh[13][13] = LEYNDELL_F11;
            initializeArea(13,13,51,&sArea,(int *)nLEleventh);
            sArea.a11.nRowSize = 13;
            sArea.a11.nColumnSize = 13;
            sArea.a11.nRowOffset = 51;

            int nLTwelfth[3][3] = LEYNDELL_F12;
            initializeArea(3,3,64,&sArea,(int *)nLTwelfth);
            sArea.a12.nRowSize = 3;
            sArea.a12.nColumnSize = 3;
            sArea.a12.nRowOffset = 64;

            int nLThirteenth[3][3] = LEYNDELL_F13;
            initializeArea(3,3,67,&sArea,(int *)nLThirteenth);
            sArea.a13.nRowSize = 3;
            sArea.a13.nColumnSize = 3;
            sArea.a13.nRowOffset = 67;

            int nLFourteenth[7][5] = LEYNDELL_F14;
            initializeArea(7,5,70,&sArea,(int *)nLFourteenth);
            sArea.a14.nRowSize = 7;
            sArea.a14.nColumnSize = 5;
            sArea.a14.nRowOffset = 70;

            strcpy(sArea.strEnemy1, "Leyndell Soldier");
            strcpy(sArea.strEnemy2, "Leyndell Archer");
            strcpy(sArea.strEnemy3, "Leyndell Knight");

            if(cFastTravelTile == '1'){
               sArea.aBigArray[3][1] = 9;
               sArea.nFloorChoice = 1;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nLeyndell);
            }
            else{
               sArea.aBigArray[76][2] = 11;
               sArea.nFloorChoice = 2;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nLeyndell);
            }

            break;

          case '6':
            sArea.nAreaIndex = 6;
            sArea.nFloorCount = 3;

            int nEFirst[9][3] = ELDEN_F1;
            initializeArea(9,3,0,&sArea,(int *)nEFirst);
            sArea.a1.nRowSize = 9;
            sArea.a1.nColumnSize = 3;
            sArea.a1.nRowOffset = 0;

            int nESecond[7][7] = ELDEN_F2;
            initializeArea(7,7,9,&sArea,(int *)nESecond);
            sArea.a2.nRowSize = 7;
            sArea.a2.nColumnSize = 7;
            sArea.a2.nRowOffset = 9;

            int nEThird[9][3] = ELDEN_F3;
            initializeArea(9,3,16,&sArea,(int *)nEThird);
            sArea.a3.nRowSize = 9;
            sArea.a3.nColumnSize = 3;
            sArea.a3.nRowOffset = 16;

            if(cFastTravelTile == '1'){
               sArea.aBigArray[8][1] = 9;
               sArea.nFloorChoice = 1;
               floorPass(pPlayer, &sArea, &pPlayer->nShards.nElden);
            }
          
            break;

    }

}

void runCredits()
{

}