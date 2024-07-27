#include "area.h"
#include "combat.h"
#include "RoundTable.h"
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

void runArea(Area* pArea, Array sCoordinate, Player* pPlayer)
{
     char cInput; // this might be in a struct in the main file //it is

     do{
     
     // areaScreen(sArea->strAreaName);
     printFloor(pArea, sCoordinate);
     printf("\n[RUNES]: %d\t[INPUT]: ", pPlayer->runes);
     scanf(" %c", &cInput);
     printf("\n");
     processInput(cInput, pArea, sCoordinate, pPlayer); 

     } while(cInput != '0');

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

void printFloor(Area* pArea, Array sCoordinate) // can be used for all
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
                              else if(pArea->aBigArray[i][j] == 6){
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
                              else if(pArea->aBigArray[i][j] == 6){
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
                              else if(pArea->aBigArray[i][j] == 6){
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
          }

          printf("\n");
          
     }

}

void processInput(char cInput, Area* pArea, Array sCoordinate, Player* pPlayer) // can be used for all
{
     int nRandom;
     srand(time(NULL));

     for(int i = sCoordinate.nRowOffset; i < sCoordinate.nRowSize + sCoordinate.nRowOffset; i++){
          for(int j = 0; j < sCoordinate.nColumnSize; j++){
               if(pArea->aBigArray[i][j] % 2 == 1){
                    switch(cInput){
                         case 'W':
                         case 'w': 
                              if(i == 0)
                                   break;
                              pArea->aBigArray[i][j]--;
                              i--;
                              pArea->aBigArray[i][j]++;
                              break;

                         case 'D':
                         case 'd':
                              if(j == sCoordinate.nColumnSize-1)
                                   break;
                              pArea->aBigArray[i][j] -= 1;
                              j++;
                              pArea->aBigArray[i][j] += 1;
                              break;
                         case 'A':
                         case 'a':
                              if(j == 0)
                                   break;
                              pArea->aBigArray[i][j] -= 1;
                              j--;
                              pArea->aBigArray[i][j] += 1;
                              break;
                         case 'S':
                         case 's':
                              if(i == sCoordinate.nRowSize-1)
                                   break;
                              pArea->aBigArray[i][j] -= 1;
                              i++;
                              pArea->aBigArray[i][j] += 1;
                              break;
                         case 'E': // make the door function // has to be linked lists 
                         case 'e':
                              if(pArea->aBigArray[i][j] == 1) // normal tile
                                   break;
                              else if(pArea->aBigArray[i][j] == 3){ //spawn tile
                                   nRandom = (rand() % 4) + 1;
                                   printf("[nRandom]: %d\n", nRandom);
                                   if(nRandom == 1){
                                        nRandom = rand() % (150 - 50) + 50;
                                        nRandom *= pArea->nAreaIndex;
                                        pPlayer->runes = pPlayer->runes + nRandom;
                                        printf("You obtained [%d] Runes!\n", nRandom);
                                   } 
                                   else
                                        runCombat(pPlayer);

                                   pArea->aBigArray[i][j] = 1;
                              }
                              

                    }
               }
          }
     }

}

void floorPass(Player* pPlayer, Area* pArea, int* pPlayerLocation)
{
     
     do{

          for (int i = 0; i < pArea->nFloorCount; i++){
               if(pPlayerLocation[i] == 1){
                    switch(i){
                         case 0:
                              runArea(pArea, pArea->a1, pPlayer);
                              break;
                         case 1:
                              runArea(pArea, pArea->a2, pPlayer);
                              break;
                         case 2:
                              runArea(pArea, pArea->a3, pPlayer);
                              break;
                         case 3: 
                              runArea(pArea, pArea->a4, pPlayer);
                              break;
                         case 4:
                              runArea(pArea, pArea->a5, pPlayer);
                              break;
                         case 5: 
                              runArea(pArea, pArea->a6, pPlayer);
                              break;

                    }
               }
          }

     } while(pArea->nFlag != 1);
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

            if(cFastTravelTile == '1'){
               sArea.aBigArray[6][1] = 9;
               int aPlayerLocation[3] = {1,0,0};
               floorPass(pPlayer, &sArea, aPlayerLocation);
            }
            else{
               sArea.aBigArray[14][2] = 11;
               int aPlayerLocation[3] = {0,0,1};
               floorPass(pPlayer, &sArea, aPlayerLocation);
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
            initializeArea(8,7,27,&sArea,(int *)nRFifth);
            sArea.a5.nRowSize = 8;
            sArea.a5.nColumnSize = 7;
            sArea.a5.nRowOffset = 27;

            if(cFastTravelTile == '1'){
               sArea.aBigArray[4][2] = 9;
               int aPlayerLocation[5] = {1,0,0,0,0};
               floorPass(pPlayer, &sArea, aPlayerLocation);
            }
            else{
               sArea.aBigArray[27][3] = 11;
               int aPlayerLocation[5] = {0,0,0,0,1};
               floorPass(pPlayer, &sArea, aPlayerLocation);
            }

            break;
          
        case '3':

          break;

    }

}