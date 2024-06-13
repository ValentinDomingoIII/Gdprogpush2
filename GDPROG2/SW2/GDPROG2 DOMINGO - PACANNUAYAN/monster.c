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