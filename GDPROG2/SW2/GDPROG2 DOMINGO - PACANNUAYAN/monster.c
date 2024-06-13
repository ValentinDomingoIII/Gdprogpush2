#include "monster.h"
#include "inventory.h"
#include "color.h"

void displayGhost(){
    printf("   ► SHOP ────────────\n\n"); 
    ghostFG();
    printf("\t┌");
    reset();
    printf("═══════");
    ghostFG();
    printf("┐\n");
    printf("\t├───────┤\n");
    printf("\t│ GHOST │\n");
    printf("\t├───────┤\n");
    printf("\t└");
    reset();
    printf("═╤═══╤═");
    ghostFG();
    printf("┘\n");
    printf("\t ╔┴█──┤\n");
    printf("\t ╚┬───┤\n");
    printf("\t  └─");
    reset();
    printf("│");
    ghostFG();
    printf("─┘\n");
    reset();
    printf("\t  ┌─│─┐\n");
    printf("\t  │   │\n");
    printf("   ───────╨───╨───────\n");
    printf("   [INPUT]  : ");
}

void displayAlien(){
    printf("   ► SHOP ────────────\n\n"); 
    alienFG();
    printf("\t┌");
    reset();
    printf("═══════");
    alienFG();
    printf("┐\n");
    printf("\t├───────┤\n");
    printf("\t│ ALIEN │\n");
    printf("\t├───────┤\n");
    printf("\t└");
    reset();
    printf("═╤═══╤═");
    alienFG();
    printf("┘\n");
    printf("\t ╔┴█──┤\n");
    printf("\t ╚┬───┤\n");
    printf("\t  └─");
    reset();
    printf("│");
    alienFG();
    printf("─┘\n");
    reset();
    printf("\t  ┌─│─┐\n");
    printf("\t  │   │\n");
    printf("   ───────╨───╨───────\n");
    printf("   [INPUT]  : ");
}

void displaySquid(){
    printf("   ► SHOP ────────────\n\n"); 
    squidFG();
    printf("\t┌");
    reset();
    printf("═══════");
    squidFG();
    printf("┐\n");
    printf("\t├───────┤\n");
    printf("\t│ SQUID │\n");
    printf("\t├───────┤\n");
    printf("\t└");
    reset();
    printf("═╤═══╤═");
    squidFG();
    printf("┘\n");
    printf("\t ╔┴█──┤\n");
    printf("\t ╚┬───┤\n");
    printf("\t  └─");
    reset();
    printf("│");
    squidFG();
    printf("─┘\n");
    reset();
    printf("\t  ┌─│─┐\n");
    printf("\t  │   │\n");
    printf("   ───────╨───╨───────\n");
    printf("   [INPUT]  : ");
}

void displayGhostItem() {
    char cInput;

    do{
        printf("\n   ► ITEM ────────────\n\n");
        printf("      ┌── GHOST ──┐\n"); //6 SPACES
        printf("      │");
        ghostFG();
        printf(" ╔═══════╗ ");
        reset();
        printf("│\n");
        printf("      │");
        ghostFG();
        printf(" ║");
        reset();
        printf(" ▄███▄");
        ghostFG();
        printf(" ║");
        reset();
        printf(" │\n");
        printf("      │");
        ghostFG();
        printf(" ║");
        reset();
        printf(" █");
        ghostFG();
        printf("█");
        reset();
        printf("█");
        ghostFG();
        printf("█");
        reset();
        printf("█");
        ghostFG();
        printf(" ║");
        reset();
        printf(" │\n");
        printf("      │");
        ghostFG();
        printf(" ║");
        reset();
        printf(" █▀█▀█");
        ghostFG();
        printf(" ║");
        reset();
        printf(" │\n");
        printf("      │");
        ghostFG();
        printf(" ╚═══════╝");
        reset();
        printf(" │\n");
        printf("      └───────────┘\n\n\n");
        printf("   ───────────────────\n");
        printf("   [INPUT]  : ");
        scanf(" %c", &cInput);

    }while(cInput != 'Q');
}

void displayAlienItem() {
    char cInput;

    do{
        printf("\n   ► ITEM ────────────\n\n");
        printf("      ┌── ALIEN ──┐\n"); //6 SPACES
        printf("      │");
        alienFG();
        printf(" ╔═══════╗ ");
        reset();
        printf("│\n");
        printf("      │");
        alienFG();
        printf(" ║");
        reset();
        printf(" ▀▄▄▄▀"); //│ ║ ▀▄▄▄▀ ║ │  │ ║  ▄█▄  ║ │
        alienFG();        //│ ║▄█ █ █▄║ │  │ ║▄█ █ █▄║ │
        printf(" ║");     //│ ║ █▀▀▀█ ║ │  │ ║ ▄▀▀▀▄ ║ │
        reset();
        printf(" │\n");
        printf("      │");
        alienFG();
        printf(" ║");
        reset();
        printf("▄█");
        alienFG();
        printf("█");
        reset();
        printf("█");
        alienFG();
        printf("█");
        reset();
        printf("█▄");
        alienFG();
        printf("║");
        reset();
        printf(" │\n");
        printf("      │");
        alienFG();
        printf(" ║");
        reset();
        printf(" █▀▀▀█");
        alienFG();
        printf(" ║");
        reset();
        printf(" │\n");
        printf("      │");
        alienFG();
        printf(" ╚═══════╝");
        reset();
        printf(" │\n");
        printf("      └───────────┘\n\n\n");
        printf("   ───────────────────\n");
        printf("   [INPUT]  : ");
        scanf(" %c", &cInput);

    }while(cInput != 'Q');
}

void displaySquidItem() {
    char cInput;

    do{
        printf("\n   ► ITEM ────────────\n\n");
        printf("      ┌── SQUID ──┐\n"); //6 SPACES
        printf("      │");
        squidFG();
        printf(" ╔═══════╗ ");
        reset();
        printf("│\n");
        printf("      │");
        squidFG();
        printf(" ║");
        reset();
        printf("  ▄█▄ ");
        squidFG();
        printf(" ║");
        reset();
        printf(" │\n");
        printf("      │");
        squidFG();
        printf(" ║");
        reset();
        printf("▄█");
        squidFG();
        printf("█");
        reset();
        printf("█");
        squidFG();
        printf("█");
        reset();
        printf("█▄");
        squidFG();
        printf("║");
        reset();
        printf(" │\n");
        printf("      │");
        squidFG();
        printf(" ║");
        reset();
        printf(" ▄▀▀▀▄");
        squidFG();
        printf(" ║");
        reset();
        printf(" │\n");
        printf("      │");
        squidFG();
        printf(" ╚═══════╝");
        reset();
        printf(" │\n");
        printf("      └───────────┘\n\n\n");
        printf("   ───────────────────\n");
        printf("   [INPUT]  : ");
        scanf(" %c", &cInput);

    }while(cInput != 'Q');
}