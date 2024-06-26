#include "shop.h"
#include "monster.h"
#include "inventory.h"

#define row 3
#define col 3


void runShop(){
    char cInput;
    int aShop[3] = {1,0,0};
    int nKey = 1;
    int aItems[row][col];
    
    int i=0,j=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
        aItems[i][j]=0;
        }
    }

    displayGhost();

    do{
        scanf(" %c", &cInput);
        processShop(aShop,cInput,&nKey,aItems);
        processDisplay(&nKey);

    }while(cInput != 'Q');

}



void processShop(int* pShop, char cInput, int* nKey, int aItems[row][col]){
    int i,j;
    switch(cInput){
        case 'A':
            (*nKey)--;

            if(*nKey<=0)
            *nKey=1;
                   
            break;
        case 'D':
            (*nKey)++;
            
            if(*nKey>=3)
            *nKey=3;
                
            break;

        case 'E':
            if(*nKey==1){
                for(i=0;i<row;i++){
                    for(j=0;j<col;j++){
                        if (aItems[i][j]==0){
                            aItems[i][j]=1;
                            displayGhostItem();
                            return;
                        }            
                    }
                }
            }   

            else if(*nKey==2){
                for(i=0;i<row;i++){
                    for(j=0;j<col;j++){
                        if (aItems[i][j]==0){
                            aItems[i][j]=2;
                            displayAlienItem();
                            return;
                        }
                    }
                }
            }   


            else if(*nKey==3){
                for(i=0;i<row;i++){
                    for(j=0;j<col;j++){
                        if (aItems[i][j]==0){
                            aItems[i][j]=3;
                            displaySquidItem();
                            return;
                        }
                    }
                }
            }   

            break;

        case 'I':
            displayNormInventory(aItems);
            break;
    
    }
}

void processDisplay(int* nKey){

        if(*nKey == 1)
            displayGhost();
        else if(*nKey == 2)
                displayAlien();
            else if(*nKey == 3)
                    displaySquid();
      
}