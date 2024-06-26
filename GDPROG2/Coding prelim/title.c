#include "title.h"

void runTitle() {
	int nInput = -1;

	do {
		displayTitle();
		scanf("%d", &nInput);
		processTitleInput(nInput);
	} while(nInput != 0);
}

void displayTitle() {
    printf("\n");
    printf("\t╔════════════════════╗ \n");
    printf("\t│        MENU        │ \n");
    printf("\t╚════════════════════╝ \n");
	printf("\t   [1] New Game\n");
	printf("\t   [2] Settings\n");
	printf("\t   [3] Area\n");
	printf("\t   [0] Exit");
    printf("\n");
    printf("\t[INPUT] : ");
}

void processTitleInput(int nInput) {
	switch(nInput) {
		case 1:
		// OPEND
		runCharacterCreation();
		break;

		case 2:
		runSettings();
		break;

		case 3:
		runArea();
		break;
	}
}