#include "title.h"



/* * * * * * * * * * * * * * * * * * * * * * * * * *
 *               THE BASIC GAME LOOP               *
 * * * * * * * * * * * * * * * * * * * * * * * * * */

void runTitle() {
	int nInput = -1;

	do {
		displayTitle();
		scanf("%d", &nInput);
		processTitleInput(nInput);
	} while(nInput != 0);
}

void displayTitle() 
{
    printf("\n");
printf("\t╔════════════════════╗\n");
printf("\t│        MENU        │\n");
printf("\t╚════════════════════╝\n");
printf("\n");
printf("\t[1] Yey\n");
printf("\t[0] Ney\n");

}


void processTitleInput(int nInput) {
	switch(nInput) 
    {
        case 1:
            runcharacterCreation();
            break;
    }
}


