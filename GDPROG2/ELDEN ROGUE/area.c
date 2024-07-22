#include "area.h"
#include "structures.h"
#include "definitions.h"

// NULL TILE = -1
// EMPTY TILE = 0
// PLAYER TILE = [SELECTED TILE] + 1
// SPAWN TILE = 2
// BOSS TILE = 4
// DOOR TILE = 6
// FAST TRAVEL = 8

void runStormveil(int* pFloor, int* pFlag, Stormveil* sArea, int nRow, int nColumn)
{
     // Stormveil sFloor; 
     char cInput;
     int nFloorCount = STORMVEIL_FLOOR_COUNT;
     int nRunes; // this might be in a struct in the main file

     do{

     printFloor((int *)pFloor, nRow, nColumn);
     printf("\n[RUNES]: %d\t[INPUT]: ", nRunes);
     scanf(" %c", &cInput);
     printf("\n");
     processInput(cInput, (int *)pFloor, nRow, nColumn, nFloorCount, sArea->aPlayerLocation, &nRunes); // could put FloorCount in the stormveil struct to save space


     // printf("[RUNES]: %d\n", nRunes);
     // for(int i = 0; i < nRow; i++){
     //      printf("\n");
     //      for(int j = 0; j < nColumn; j++){
     //           printf("%d ", *((pFloor + i * nColumn) + j));
     //      }
     // }
     // printf("\n");

     } while(cInput != '0');

}

// void initializeFloor(int* pTemp, int nSize, Stormveil* sFloor, int nRow, int nColumn) 
// {

//      int k = 0;
//      // sFloor->aSpawnFloor[0][1] = 4;
//      // printf("Inside the function: %d", sFloor->aSpawnFloor[0][1]);

//      for (int i = 0; i < nRow; i++) {
//           for (int j = 0; j < nColumn; j++, k++) {
//                sFloor->aSpawnFloor[i][j] = pTemp[k];
//           }
//      }
     
// }

void printFloor(int* pFloor, int nRow, int nColumn) // can be used for all
{

     for (int i = 0; i < nRow; i++){
          for (int j = 0; j < nColumn; j++){
               
               if(*((pFloor + i * nColumn) + j) == 0){
                    printf("\x1b[38;5;8m");
                    printf("┌───┐");
                    printf("\x1b[0m");
               }
               else if(*((pFloor + i * nColumn) + j) % 2 == 1){
                    printf("\x1b[38;5;13m");
                    printf("╔═══╗");
                    printf("\x1b[0m");
               }
                    else if(*((pFloor + i * nColumn) + j) == 2){
                         printf("\x1b[38;5;33m");
                         printf("┌───┐");
                         printf("\x1b[0m");
                    }
                         else if(*((pFloor + i * nColumn) + j) == 4){
                              printf("\x1b[38;5;9m");
                              printf("┌───┐");
                              printf("\x1b[0m");
                         }
                              else if(*((pFloor + i * nColumn) + j) == 6){
                                   printf("\x1b[38;5;220m");
                                   printf("┌───┐");
                                   printf("\x1b[0m");
                              }
                                   else if(*((pFloor + i * nColumn) + j) == 8){
                                        printf("\x1b[38;5;34m");
                                        printf("┌───┐");
                                        printf("\x1b[0m");
                                   }
          }

          printf("\n");

          for (int j = 0; j < nColumn; j++){
               
               if(*((pFloor + i * nColumn) + j) == 0){
                    printf("\x1b[38;5;8m");
                    printf("│   │");
                    printf("\x1b[0m");
               }
               else if(*((pFloor + i * nColumn) + j) % 2 == 1){
                    printf("\x1b[38;5;13m");
                    printf("║   ║");
                    printf("\x1b[0m");
               }
                    else if(*((pFloor + i * nColumn) + j) == 2){
                         printf("\x1b[38;5;33m");
                         printf("│   │");
                         printf("\x1b[0m");
                    }
                         else if(*((pFloor + i * nColumn) + j) == 4){
                                   printf("\x1b[38;5;9m");
                                   printf("│   │");
                                   printf("\x1b[0m");
                         }
                              else if(*((pFloor + i * nColumn) + j) == 6){
                                   printf("\x1b[38;5;220m");
                                   printf("│   │");
                                   printf("\x1b[0m");
                              }
                                   else if(*((pFloor + i * nColumn) + j) == 8){
                                        printf("\x1b[38;5;34m");
                                        printf("│   │");
                                        printf("\x1b[0m");
                                   }
          }

          printf("\n");

          for (int j = 0; j < nColumn; j++){
               
               if(*((pFloor + i * nColumn) + j) == 0){
                    printf("\x1b[38;5;8m");
                    printf("└───┘");
                    printf("\x1b[0m");
               }
               else if(*((pFloor + i * nColumn) + j) % 2 == 1){
                    printf("\x1b[38;5;13m");
                    printf("╚═══╝");
                    printf("\x1b[0m");
               }
                    else if(*((pFloor + i * nColumn) + j) == 2){
                         printf("\x1b[38;5;33m");
                         printf("└───┘");
                         printf("\x1b[0m");
                    }
                         else if(*((pFloor + i * nColumn) + j) == 4){
                                   printf("\x1b[38;5;9m");
                                   printf("└───┘");
                                   printf("\x1b[0m");
                         }
                              else if(*((pFloor + i * nColumn) + j) == 6){
                                   printf("\x1b[38;5;220m");
                                   printf("└───┘");
                                   printf("\x1b[0m");
                              }
                                   else if(*((pFloor + i * nColumn) + j) == 8){
                                        printf("\x1b[38;5;34m");
                                        printf("└───┘");
                                        printf("\x1b[0m");
                                   }
          }

          printf("\n");
          
     }

}

void processInput(char cInput, int* pFloor, int nRow, int nColumn, int nFloorCount, int* pPlayerLocation, int* pRunes) // can be used for all
{
     int nRandom;
     srand(time(NULL));

     for(int i = 0; i < nRow; i++){
          for(int j = 0; j < nColumn; j++){
               if(*((pFloor + i * nColumn) + j) % 2 == 1){
                    switch(cInput){
                         case 'W':
                         case 'w': 
                              if(i == 0)
                                   break;
                              *((pFloor + i * nColumn) + j) -= 1;
                              i--;
                              *((pFloor + i * nColumn) + j) += 1;
                              break;

                         case 'D':
                         case 'd':
                              if(j == nColumn-1)
                                   break;
                              *((pFloor + i * nColumn) + j) -= 1;
                              j++;
                              *((pFloor + i * nColumn) + j) += 1;
                              break;
                         case 'A':
                         case 'a':
                              if(j == 0)
                                   break;
                              *((pFloor + i * nColumn) + j) -= 1;
                              j--;
                              *((pFloor + i * nColumn) + j) += 1;
                              break;
                         case 'S':
                         case 's':
                              if(i == nRow-1)
                                   break;
                              *((pFloor + i * nColumn) + j) -= 1;
                              i++;
                              *((pFloor + i * nColumn) + j) += 1;
                              break;
                         case 'E': // make the door function // has to be linked lists 
                         case 'e':
                              if(*((pFloor + i * nColumn) + j) == 1)
                                   break;
                              else if(*((pFloor + i * nColumn) + j) == 3){
                                   nRandom = (rand() % 4) + 1;
                                   printf("[nRandom]: %d\n", nRandom);
                                   if(nRandom == 1){
                                        nRandom = rand() % (150 - 50) + 50;
                                        *pRunes = *pRunes + nRandom;
                                        printf("You obtained [%d] Runes!\n", nRandom);
                                   } 
                                   else
                                        printf("Enemy!\n");

                                   *((pFloor + i * nColumn) + j) = 1;
                              }
                              

                    }
               }
          }
     }

}

void initializeStormveil()
{
     Stormveil sArea = STORMVEIL_INITIALIZER;
     int nFlag = 0;
     
     do{

          for (int i = 0; i < STORMVEIL_FLOOR_COUNT; i++){
               if(sArea.aPlayerLocation[i] == 1){
                    if(i == 0){
                         runStormveil((int *)sArea.aSpawnFloor, &nFlag, &sArea, 7, 3);
                         break;
                    }
                    else if(i == 1){
                         runStormveil((int *)sArea.aSecondFloor, &nFlag, &sArea, 7, 7);
                         break;
                    }
                         else if(i == 2){
                              runStormveil((int *)sArea.aBossFloor, &nFlag, &sArea, 7, 5);
                              break;
                         }
               }
          }

     } while(nFlag != 1);

}