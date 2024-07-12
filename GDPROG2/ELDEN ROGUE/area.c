#include "area.h"
#include "structures.h"

// EMPTY TILE = 0
// PLAYER TILE = 1
// SPAWN TILE = 2
// BOSS TILE = 3
// DOOR TILE = 4
// FAST TRAVEL = 5

void runStormveil()
{
     Stormveil sFloor; 
     int aTemp[21] = {0,4,0,2,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};
     char cInput;

     do{

     initializeFloor(aTemp, 21, &sFloor, 7, 3);
     printFloor(sFloor, 7, 3);
     printf("\n[INPUT]: ");
     scanf(" %c", &cInput);
     // processInput(cInput, &sFloor, 7, 3);

     } while(cInput != '0');

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
               else if(sFloor.aSpawnFloor[i][j] == 1){
                    printf("\x1b[38;5;34m");
                    printf("╔═══╗");
                    printf("\x1b[0m");
               }
                    else if(sFloor.aSpawnFloor[i][j] == 2){
                         printf("\x1b[38;5;33m");
                         printf("┌───┐");
                         printf("\x1b[0m");
                    }
                         else if(sFloor.aSpawnFloor[i][j] == 4){
                              printf("\x1b[38;5;220m");
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
               else if(sFloor.aSpawnFloor[i][j] == 1){
                    printf("\x1b[38;5;34m");
                    printf("║   ║");
                    printf("\x1b[0m");
               }
                    else if(sFloor.aSpawnFloor[i][j] == 2){
                         printf("\x1b[38;5;33m");
                         printf("│   │");
                         printf("\x1b[0m");
                    }
                         else if(sFloor.aSpawnFloor[i][j] == 4){
                              printf("\x1b[38;5;220m");
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
               else if(sFloor.aSpawnFloor[i][j] == 1){
                    printf("\x1b[38;5;34m");
                    printf("╚═══╝");
                    printf("\x1b[0m");
               }
                    else if(sFloor.aSpawnFloor[i][j] == 2){
                         printf("\x1b[38;5;33m");
                         printf("└───┘");
                         printf("\x1b[0m");
                    }
                         else if(sFloor.aSpawnFloor[i][j] == 4){
                              printf("\x1b[38;5;220m");
                              printf("└───┘");
                              printf("\x1b[0m");
                         }
          }

          printf("\n");
          
     }

}

// void processInput(char cInput, Stormveil* sFloor, int nRow, int nColumn){
//      // printf("Hello\n");

//      for(int i = 0; i < nRow; i++){
//           for(int j = 0; j < nColumn; j++){
//                if(sFloor->aSpawnFloor[i][j] == 1){
//                     switch(cInput){
//                          case 'W': 
//                               sFloor->aSpawnFloor[i][j] = 0
//                     }
//                }
//           }
//      }

// }