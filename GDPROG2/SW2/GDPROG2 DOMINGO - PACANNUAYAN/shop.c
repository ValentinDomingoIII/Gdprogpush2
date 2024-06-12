#include "shop.h"
#include "monster.h"

void runShop(){
    char cInput;
    int aShop[3] = {1,0,0};
    int nKey = 1;

    displayGhost();
    do{
        scanf(" %c", &cInput);
        processShop(aShop,cInput,&nKey);
        processDisplay(&nKey);

    }while(cInput != 'Q');

}



void processShop(int* pShop, char cInput, int* nKey){

    switch(cInput){
        case 'A':
                (*nKey)--;
                if(*nKey<=0)
                *nKey=1;
                    //pShop[i]--;
                    //pShop[i-1]++;
                
            
            break;
        case 'D':

                (*nKey)++;
                if(*nKey>=3)
                *nKey=3;
                    //pShop[i]--;
                    //pShop[i+1]++;
                
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