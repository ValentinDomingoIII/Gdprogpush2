#pragma once

#define row 3
#define col 3

void displayInventory(int aItems[row][col], int nSelectedRow, int nSelectedCol);
void displayNormInventory(int aItems[row][col]);
void navigateInventory(int aItems[row][col]);

void processSelectBoxColor1(int* pItems, int nX, int nY);
void processSelectBoxColor2(int* pItems, int nX, int nY);
void processSelectBoxColor3(int* pItems, int nX, int nY);

void processNormBoxColor1(int* pItems, int nX, int nY);
void processNormBoxColor2(int* pItems, int nX, int nY);
void processNormBoxColor3(int* pItems, int nX, int nY);

void processDelBox1(int* pItems, int nX, int nY);
void processDelBox2(int* pItems, int nX, int nY);
void processDelBox3(int* pItems, int nX, int nY);
