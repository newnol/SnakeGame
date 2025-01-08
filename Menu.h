#ifndef MENU_H
#define MENU_H

#include "Render.h"
#include "KeyMapping.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <thread>
#include "Bitmap.h"

void UILevel(int x, int y); // Print level phia tren man choi

// Dem nguoc bat dau
void CountDown();

// Load game screen
void menuLoadGame(); 

// Save game screen
void menuSaveGame();

// Print slot from SAVEDDATA
void printSlot(int x, int y, int slot, int text, int BG);

extern int MODE;
#endif