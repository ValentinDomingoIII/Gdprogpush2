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
// CREDITS TILE = 12

void runArea(Area* pArea, Array sCoordinate, Player* pPlayer)
{
     char cInput; 

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
                         case 6: 
                              runArea(pArea, pArea->a7, pPlayer);
                              break;
                         case 7: 
                              runArea(pArea, pArea->a8, pPlayer);
                              break;
                         case 8: 
                              runArea(pArea, pArea->a9, pPlayer);
                              break;
                         case 9: 
                              runArea(pArea, pArea->a10, pPlayer);
                              break;
                         case 10: 
                              runArea(pArea, pArea->a11, pPlayer);
                              break;
                         case 11: 
                              runArea(pArea, pArea->a12, pPlayer);
                              break;
                         case 12: 
                              runArea(pArea, pArea->a13, pPlayer);
                              break;
                         case 13: 
                              runArea(pArea, pArea->a14, pPlayer);
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
            initializeArea(8,7,24,&sArea,(int *)nRFifth);
            sArea.a5.nRowSize = 8;
            sArea.a5.nColumnSize = 7;
            sArea.a5.nRowOffset = 24;

            if(cFastTravelTile == '1'){
               sArea.aBigArray[4][2] = 9;
               int aPlayerLocation[5] = {1,0,0,0,0};
               floorPass(pPlayer, &sArea, aPlayerLocation);
            }
            else{
               sArea.aBigArray[24][3] = 11;
               int aPlayerLocation[5] = {0,0,0,0,1};
               floorPass(pPlayer, &sArea, aPlayerLocation);
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

            if(cFastTravelTile == '1'){
               sArea.aBigArray[1][0] = 9;
               int aPlayerLocation[7] = {1,0,0,0,0,0,0};
               floorPass(pPlayer, &sArea, aPlayerLocation);
            }
            else{
               sArea.aBigArray[30][6] = 11;
               int aPlayerLocation[7] = {0,0,0,0,0,0,1};
               floorPass(pPlayer, &sArea, aPlayerLocation);
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

            if(cFastTravelTile == '1'){
               sArea.aBigArray[4][2] = 9;
               int aPlayerLocation[7] = {1,0,0,0,0,0,0};
               floorPass(pPlayer, &sArea, aPlayerLocation);
            }
            else{
               sArea.aBigArray[34][2] = 11;
               int aPlayerLocation[7] = {0,0,0,0,0,0,1};
               floorPass(pPlayer, &sArea, aPlayerLocation);
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

            int nLNinth[7][3] = LEYNDELL_F9; //breaks here
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

            if(cFastTravelTile == '1'){
               sArea.aBigArray[3][1] = 9;
               int aPlayerLocation[14] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0};
               floorPass(pPlayer, &sArea, aPlayerLocation);
            }
            else{
               sArea.aBigArray[76][2] = 11;
               int aPlayerLocation[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1};
               floorPass(pPlayer, &sArea, aPlayerLocation);
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
               int aPlayerLocation[3] = {1,0,0};
               floorPass(pPlayer, &sArea, aPlayerLocation);
            }
          //   else{
          //      sArea.aBigArray[14][2] = 11;
          //      int aPlayerLocation[3] = {0,0,1};
          //      floorPass(pPlayer, &sArea, aPlayerLocation);
          //   }
            break;

    }

}