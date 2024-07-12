#include "area.h"
#include "structures.h"

// EMPTY TILE = 0
// PLAYER TILE = [SELECTED TILE] + 1
// SPAWN TILE = 2
// BOSS TILE = 4
// DOOR TILE = 6
// FAST TRAVEL = 8

void runStormveil()
{
     Stormveil sFloor; 
     int aTemp[21] = {0,6,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,9,0};
     char cInput;

     initializeFloor(aTemp, 21, &sFloor, 7, 3);

     do{

     // initializeFloor(aTemp, 21, &sFloor, 7, 3);
     printFloor(sFloor, 7, 3);
     printf("\n[INPUT]: ");
     scanf(" %c", &cInput);
     processInput(cInput, &sFloor, 7, 3);

     for(int i = 0; i < 7; i++){
          printf("\n");
          for(int j = 0; j < 3; j++){
               printf("%d ", sFloor.aSpawnFloor[i][j]);
          }
     }
     printf("\n");

     } while(cInput != '0');

     // for(int i = 0; i < 7; i++){
     //      printf("\n");
     //      for(int j = 0; j < 3; j++){
     //           printf("%d ", sFloor.aSpawnFloor[i][j]);
     //      }
     // }

}

void initializeFloor(int* pTemp, int nSize, Stormveil* sFloor, int nRow, int nColumn) 
{

     int k = 0;
     // sFloor->aSpawnFloor[0][1] = 4;
     // printf("Inside the function: %d", sFloor->aSpawnFloor[0][1]);

     for (int i = 0; i < nRow; i++) {
          for (int j = 0; j < nColumn; j++, k++) {
               sFloor->aSpawnFloor[i][j] = pTemp[k];
          }
     }
     
}

void printFloor(Stormveil sFloor, int nRow, int nColumn){

     for (int i = 0; i < nRow; i++){
          for (int j = 0; j < nColumn; j++){
               
               if(sFloor.aSpawnFloor[i][j] == 0){
                    printf("\x1b[38;5;8m");
                    printf("┌───┐");
                    printf("\x1b[0m");
               }
               else if(sFloor.aSpawnFloor[i][j] == 1 || sFloor.aSpawnFloor[i][j] == 3 || sFloor.aSpawnFloor[i][j] == 5 || sFloor.aSpawnFloor[i][j] == 7 || sFloor.aSpawnFloor[i][j] == 9){
                    printf("\x1b[38;5;13m");
                    printf("╔═══╗");
                    printf("\x1b[0m");
               }
                    else if(sFloor.aSpawnFloor[i][j] == 2){
                         printf("\x1b[38;5;33m");
                         printf("┌───┐");
                         printf("\x1b[0m");
                    }
                         else if(sFloor.aSpawnFloor[i][j] == 6){
                              printf("\x1b[38;5;220m");
                              printf("┌───┐");
                              printf("\x1b[0m");
                         }
                              else if(sFloor.aSpawnFloor[i][j] == 8){
                                   printf("\x1b[38;5;34m");
                                   printf("┌───┐");
                                   printf("\x1b[0m");
                              }
          }

          printf("\n");

          for (int j = 0; j < nColumn; j++){
               
               if(sFloor.aSpawnFloor[i][j] == 0){
                    printf("\x1b[38;5;8m");
                    printf("│   │");
                    printf("\x1b[0m");
               }
               else if(sFloor.aSpawnFloor[i][j] == 1 || sFloor.aSpawnFloor[i][j] == 3 || sFloor.aSpawnFloor[i][j] == 5 || sFloor.aSpawnFloor[i][j] == 7 || sFloor.aSpawnFloor[i][j] == 9){
                    printf("\x1b[38;5;13m");
                    printf("║   ║");
                    printf("\x1b[0m");
               }
                    else if(sFloor.aSpawnFloor[i][j] == 2){
                         printf("\x1b[38;5;33m");
                         printf("│   │");
                         printf("\x1b[0m");
                    }
                         else if(sFloor.aSpawnFloor[i][j] == 6){
                              printf("\x1b[38;5;220m");
                              printf("│   │");
                              printf("\x1b[0m");
                         }
                              else if(sFloor.aSpawnFloor[i][j] == 8){
                                   printf("\x1b[38;5;34m");
                                   printf("│   │");
                                   printf("\x1b[0m");
                              }
          }

          printf("\n");

          for (int j = 0; j < nColumn; j++){
               
               if(sFloor.aSpawnFloor[i][j] == 0){
                    printf("\x1b[38;5;8m");
                    printf("└───┘");
                    printf("\x1b[0m");
               }
               else if(sFloor.aSpawnFloor[i][j] == 1 || sFloor.aSpawnFloor[i][j] == 3 || sFloor.aSpawnFloor[i][j] == 5 || sFloor.aSpawnFloor[i][j] == 7 || sFloor.aSpawnFloor[i][j] == 9){
                    printf("\x1b[38;5;13m");
                    printf("╚═══╝");
                    printf("\x1b[0m");
               }
                    else if(sFloor.aSpawnFloor[i][j] == 2){
                         printf("\x1b[38;5;33m");
                         printf("└───┘");
                         printf("\x1b[0m");
                    }
                         else if(sFloor.aSpawnFloor[i][j] == 6){
                              printf("\x1b[38;5;220m");
                              printf("└───┘");
                              printf("\x1b[0m");
                         }
                              else if(sFloor.aSpawnFloor[i][j] == 8){
                                   printf("\x1b[38;5;34m");
                                   printf("└───┘");
                                   printf("\x1b[0m");
                              }
          }

          printf("\n");
          
     }

}

void processInput(char cInput, Stormveil* sFloor, int nRow, int nColumn){
     // printf("Hello\n");

     for(int i = 0; i < nRow; i++){
          for(int j = 0; j < nColumn; j++){
               if(sFloor->aSpawnFloor[i][j] == 1 || sFloor->aSpawnFloor[i][j] == 3 || sFloor->aSpawnFloor[i][j] == 5 || sFloor->aSpawnFloor[i][j] == 7 || sFloor->aSpawnFloor[i][j] == 9){
                    switch(cInput){
                         case 'W': 
                              if(i == 0)
                              break;
                              sFloor->aSpawnFloor[i][j]--;
                              sFloor->aSpawnFloor[i-1][j]++;
                              break;
                         case 'D':
                              if(j == 2)
                              break;
                              sFloor->aSpawnFloor[i][j]--;
                              j++;
                              sFloor->aSpawnFloor[i][j]++;
                              break;
                         case 'A':
                              if(j == 0)
                              break;
                              sFloor->aSpawnFloor[i][j]--;
                              j--;
                              sFloor->aSpawnFloor[i][j]++;
                              break;
                         case 'S':
                              if(i == 6)
                              break;
                              sFloor->aSpawnFloor[i][j]--;
                              i++;
                              sFloor->aSpawnFloor[i][j]++;
                              break;
                    }
               }
          }
     }

}