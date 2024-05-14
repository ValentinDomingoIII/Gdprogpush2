#include "characterCreation.h"


void runcharacterCreation() {
	int nInput = -1;

	do {
		displaycharacterCreation();
		scanf("%d", &nInput);
		processcharacterCreationInput(nInput);
	} while(nInput != 0);
}

void displaycharacterCreation() 
{
    printf("open");
}

void processcharacterCreationInput(int nInput) {
	switch(nInput) {}
}