#pragma once

#define row 3
#define col 3

void displayGhostItem();
void displayAlienItem();
void displaySquidItem();
void displayInventory(int items[row][col], int selectedRow, int selectedCol);
void navigateInventory(int items[row][col]);