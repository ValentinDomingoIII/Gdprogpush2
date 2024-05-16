#include "character_creation.h"

void runCharacterCreation() {
	int nInput = -1;

	do {
		displayCharacterCreation();
		scanf("%d", &nInput);
		processCharacterCreationInput(nInput);
	} while(nInput != 0);
}

void displayCharacterCreation() {
    printf("\n");
    printf("\t╔════════════════════╗ \n");
    printf("\t│      NEW GAME      │ \n");
    printf("\t╚════════════════════╝ \n");
    printf("\t   [0] Exit");
    printf("\n");
    printf("\t[INPUT] : ");
}

void processCharacterCreationInput(int nInput) {
	switch(nInput) {}
}