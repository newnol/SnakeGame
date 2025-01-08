#ifndef GAME_PLAY_H
#define GAME_PLAY_H

#define MAX_SIZE_SNAKE 32 
#define MAX_SIZE_FOOD 5 // Food moi level
#define MAX_SPEED 20
#define MAX_SIZE_GATE 5
#define MAX_SIZE_OBSTACLE 300
#define MAX_LEVEL 4 // So level
#define MAX_SIZE_SPECIAL 4
#define DEAULT_LENGTH 6
#define AUTO_SAVE_DELAY 5000

#define X_TABLE 5 // Toa do tuong tren
#define Y_TABLE 6 // Toa do tuong trai

#include "Render.h"
#include "SaveGame.h"
#include "Snake.h"
#include "KeyMapping.h"
#include "Menu.h"
#include "Bitmap.h"
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <thread>
#include <vector>
using namespace std;

const int HEIGH = 30; // Chieu cao PlayArea
const int WIDTH = 50; // Chieu rong PlayArea
const int X_TABLE_MAX = X_TABLE + WIDTH + 1;
const int Y_TABLE_MAX = Y_TABLE + HEIGH + 1;


extern Point snake[MAX_SIZE_SNAKE];
extern Point food[MAX_SIZE_FOOD];
extern Point gate[MAX_SIZE_GATE];//toa do cong qua man
extern Point obstacle[MAX_SIZE_OBSTACLE];//toa do chuong ngai vat

extern SpecialFood special_Food[MAX_SIZE_SPECIAL];

// Global var
extern int toado_x[4];
extern int toado_y[4];
extern int playerScore;
extern int PAUSE_STATE;
extern int SIZE_SNAKE;//size of snake
extern int SIZE_OBSTACLE;//size of obstacle
extern int STATE;
extern bool EXIT;// dieu kien de dung thread
extern int FOOD_IDX;
extern int SPECIAL_IDX;//chi so mang special food
extern bool SPECIAL;//dieu kien de ve special food
extern int SIZE_SPECIAL;
extern int BLOCKED_CHAR;
extern int MOVE;
extern float SPEED;
extern int LEVEL;// game level
extern bool FOOD;

const Point StatusPos{ X_TABLE_MAX + 5, Y_TABLE + 5 }; // Runinng / Paused
const Point ScorePos{ X_TABLE_MAX + 5, StatusPos.y + 3 };
const Point FoodPos{ X_TABLE_MAX + 5, ScorePos.y + 2 };
const Point LengthPos{ X_TABLE_MAX + 5, FoodPos.y + 2 };
const Point ScoreBarPos{ X_TABLE_MAX + 5, LengthPos.y + 2 };
const Point ResumePos{ X_TABLE_MAX + 5, StatusPos.y + 5 }; // Resume Button
const Point SavePos{ X_TABLE_MAX + 5, ResumePos.y + 6 }; // Save Buttion
const Point MainMenuPos{ X_TABLE_MAX + 5, SavePos.y + 6 }; // Return menu Button

bool PointValid(Point Position);
void GenerateFood();
void GenerateSpecial();
void InitSnake();
void InitGate();

void loadData(int slot);
void InitObstacle_Level2();
void InitObstacle_Level3();
void InitObstacle_Level4();
void InitData();
void InitData2();
void DrawMapLevel1(int width, int height);
void DrawMapLevel2_3_4(int width, int height);

void StartGame();
void StartLevel2();
void StartLevel3();
void StartLevel4();
void StartGameLoad();
void ExitGame(thread& t);
void PauseGame(HANDLE t);
void ProcessDead();

void DrawSnake(char* str, int color);
void DrawFood();
void DrawGate();
void drawScore(int color, int BG);
void DrawScoreBar();
void PausedMenu(int PauseState);

void EatFood();
void EatSpecialFood();
bool CheckEatThemselves();

bool CheckTouchWallGate();
void ClearSnake();
void MoveRight();
void MoveLeft();
void MoveUp();
void MoveDown();
void ThreadFunc();
void PlayGame();

#endif