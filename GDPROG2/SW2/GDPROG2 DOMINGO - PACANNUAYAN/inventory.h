#pragma once

#define row 3
#define col 3

void displayGhostItem();
void displayAlienItem();
void displaySquidItem();
void displayInventory(int aItems[row][col], int nSelectedRow, int nSelectedCol);
void navigateInventory(int aItems[row][col]);
void processSelectBoxColor1(int* pItems, int nX, int nY);
void processSelectBoxColor2(int* pItems, int nX, int nY);
void processSelectBoxColor3(int* pItems, int nX, int nY);
void processNormBoxColor1(int* pItems, int nX, int nY);
void processNormBoxColor2(int* pItems, int nX, int nY);
void processNormBoxColor3(int* pItems, int nX, int nY);
