#ifndef RENDER_H
#define RENDER_H
#include <Windows.h>
#include "Color.h"
#include "Point.h"
#include "Menu.h"
#include <iostream>
#include <mutex>
#include <thread>
//thu vien can cho mo nhac
#include <mmsystem.h>
#include <mciapi.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

//Fix the console window to fit the game screen.
void fixConsoleWindow();

//Remove cursor
void setcursor(bool visible, DWORD size); 

//Move the console cursor to the specified coordinate
void GoToXY(int x, int y);
void GoToXY(Point a);

//Set the text and text background color of the console.
void setOutputColor(int text, int BG);

// Set the font of the console (Arial / Terminal / Consolas/ ...)
void setFont(const wchar_t* font, int sizeX, int sizeY);
void setFontSquare();

void clearScreen();
void clearArea(Point TopLeft, Point BottomRight, int BG);
void clearAreaAnimation(Point TopLeft, Point BottomRight, int BG);

//Draw box
void box(int x, int y, int weight, int height, int color); 
void drawBox(Point a, int width, int height, int color);

//draw image
void drawSnakeImage(Point a);

//Play music
void playMusic(bool play);
#endif