#include "Menu.h"
#include "Gameplay.h"
#include <wingdi.h>
#pragma comment(lib, "Gdi32.lib")

#define MAX_SETTINGS 3

extern HBITMAP gameover;
extern HBITMAP press;
extern HBITMAP pressB;
extern HBITMAP win;

extern bool MUSIC;
extern bool SOUND;
extern int COLOR;

HBITMAP LoadBitmapFromFile(LPCWSTR filename);

void DrawBitmap(HBITMAP hBitmap, int x, int y);

int DifficultyMenu();

int bmpMenu();

void menuFunc();

void bmpGameOver();

int bmpExit();

void bmpAbout();

void bmpSetting();

void bmpWin();

void MenuLegend();

void printSlotLegend(int x, int y, int slot, int text, int BG);