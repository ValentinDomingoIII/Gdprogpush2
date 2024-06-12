#include "title.h"
#include "character_creation.h"
#include "continue.h"

void runTitle(){
    int nInput = 0;

    do{
    printf("\n");
    displayTitle();
    scanf("%d", &nInput);
    processTitle(&nInput);
    }while(nInput != 0);

}

void displayTitle(){
    printf("\t╔═════════════════════╗\n");
    printf("\t│     ELDEN ROGUE     │\n");
    printf("\t╚═════════════════════╝\n");
    printf("\t[1] START\n");
    printf("\t[2] CONTINUE\n");
    printf("\t[0] EXIT\n");
    printf("\n\t[INPUT]: ");
}

void processTitle(int* nInput){
    switch(*nInput){
        case 1: 
            runCharCreation();
            break;
        case 2:
            runContinue();
            break;
        case 0: 
            *nInput = 0;
            break;
    }
}