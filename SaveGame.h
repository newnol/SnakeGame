#ifndef SAVE_GAME_H
#define SAVE_GAME_H

#include "Point.h"
#include <fstream>
#include <iomanip>
#include "Menu.h"
#include "Snake.h"
#include "Gameplay.h"
#include <string>
#include <ctime>

#define TIME_LENGTH 22 // Do dai cua date
#define MAX_SAVE_SLOTS 10 // Save slots toi da

// Phan data lay tu game dang choi
struct Data
{
	int level, score;
	int food_idx, speed, sz_snake, blocked, move, szOb, szSpecial;
	Point snake[MAX_SIZE_SNAKE];
	Point food[MAX_SIZE_FOOD];
	Point gate[MAX_SIZE_GATE];
	Point obstacle[MAX_SIZE_OBSTACLE];
	SpecialFood special[MAX_SIZE_SPECIAL];
};

// Phan data luu/doc file
struct SavedData
{
	bool exist = false;
	string name;
	string date;
	Data data;
};

extern SavedData SAVEDDATA[MAX_SAVE_SLOTS];

ofstream& operator<<(ofstream& stream, const SavedData& savedData);
ifstream& operator>>(ifstream& stream, SavedData& savedData);

SavedData loadFile(int slot);
void saveFile(string name, int slot);
void loadGame(int slot);
void InitSavedData();

#endif