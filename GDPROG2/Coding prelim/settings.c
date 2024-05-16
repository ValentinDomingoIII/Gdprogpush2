#include "settings.h"

void runSettings() {
	int nInput = -1;

	do {
		displaySettings();
		scanf("%d", &nInput);
		processSettingsInput(nInput);
	} while(nInput != 0);
}

void displaySettings() {
    printf("\n");
    printf("\t╔════════════════════╗ \n");
    printf("\t│      SETTINGS      │ \n");
    printf("\t╚════════════════════╝ \n");
	printf("\t   [0] Exit");
    printf("\n");
    printf("\t[INPUT] : ");
}

void processSettingsInput(int nInput) {
	switch(nInput) {}
}
