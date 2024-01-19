#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <thread>
#include <string>

typedef unsigned long       DWORD;

//Color
#define Black 0
#define Blue 1
#define Green 2
#define Aqua 3
#define Red 4
#define Purple 5
#define Yellow 6
#define White 7
#define Gray 8
#define LBlue 9
#define LGreen 10
#define LAqua 11
#define LRed 12
#define LPurple 13
#define LYellow 14
#define BWhite 15

//Keyboard
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define ENTER '\r'

//Render
void setOutputColor(int text, int BG); //Set color
void GoToXY(int x, int y); //Move cursor to (x,y)
void fixConsoleWindow(); //Fix console size
void setcursor(bool visible, DWORD size); //Remove cursor

//Word
void firstWord(); //Print first word
void printRound(int LEVEL_STATE); //Print round
void MainMenu(); //Print main menu
void New(); //Print new game menu
