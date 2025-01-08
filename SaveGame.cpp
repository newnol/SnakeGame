#define _CRT_SECURE_NO_WARNINGS
#include "SaveGame.h"
SavedData SAVEDDATA[MAX_SAVE_SLOTS];

// Cau truc luu data
ofstream& operator<<(ofstream& stream, const SavedData& savedData)
{
	stream << LEVEL << " " << playerScore << " " << FOOD_IDX << " " << SPEED << " " << SIZE_SNAKE << " "
		<< BLOCKED_CHAR << " " << MOVE << " " << SIZE_OBSTACLE;
	if (LEVEL >= 3) {
		stream << " " << SIZE_SPECIAL << endl;
	}
	else stream << endl;
	for (int i = 0; i < SIZE_SNAKE; i++) {
		stream << snake[i].x << " " << snake[i].y << " ";
	}
	stream << "\n";
	for (int i = 0; i < MAX_SIZE_FOOD; i++) {
		stream << food[i].x << " " << food[i].y << " ";
	} stream << "\n";
	for (int i = 0; i < MAX_SIZE_GATE; i++) {
		stream << gate[i].x << " " << gate[i].y << " ";
	} stream << "\n";
	for (int i = 0; i < SIZE_OBSTACLE; i++) {
		stream << obstacle[i].x << " " << obstacle[i].y << " ";
	} stream << "\n";
	if (LEVEL >= 3){
		for (int i = 0; i < SIZE_SPECIAL; i++) {
			stream << special_Food[i].pos.x << " " << special_Food[i].pos.y << " " << special_Food[i].func << " ";
		} stream << "\n";
	}
	return stream;
}

// Cau truc doc data
ifstream& operator>>(ifstream& stream, SavedData& savedData)
{
	stream >> savedData.data.level >> savedData.data.score >> savedData.data.food_idx >> savedData.data.speed >> savedData.data.sz_snake
		>> savedData.data.blocked >> savedData.data.move >> savedData.data.szOb;
	if (savedData.data.level >= 3) { 
		stream >> savedData.data.szSpecial; 
	}
	for (int i = 0; i < savedData.data.sz_snake; i++) {
		stream >> savedData.data.snake[i].x >> savedData.data.snake[i].y;
	}
	for (int i = 0; i < MAX_SIZE_FOOD; i++) {
		stream >> savedData.data.food[i].x >> savedData.data.food[i].y;
	}
	for (int i = 0; i < MAX_SIZE_GATE; i++) {
		stream >> savedData.data.gate[i].x >> savedData.data.gate[i].y;
	}
	for (int i = 0; i < savedData.data.szOb; i++) {
		stream >> savedData.data.obstacle[i].x >> savedData.data.obstacle[i].y;
	}
	if (savedData.data.level >= 3) {
		for (int i = 0; i < savedData.data.szSpecial; i++) {
			stream >> savedData.data.special[i].pos.x >> savedData.data.special[i].pos.y >> savedData.data.special[i].func;
		} 
	}
	return stream;
}

// Lay data tu file save_(slot).txt
SavedData loadFile(int slot) {
	ifstream stream;
	stream.open("saves/save_" + to_string(slot) + ".txt");
	SavedData saved;
	if (stream.is_open()) {
		getline(stream, saved.name);
		getline(stream, saved.date);
		stream >> saved;
		stream.close();
		saved.exist = true;
	}
	return saved;
}

// Save data dang choi vao file (name <= 10)
void saveFile(string name, int slot) {
	// Khoi tao cac gia tri luu vao file
	SavedData saved;
	saved.name = name;
	saved.data.level = LEVEL, saved.data.score = playerScore;
	saved.data.food_idx = FOOD_IDX, saved.data.speed = SPEED, saved.data.sz_snake = SIZE_SNAKE, saved.data.szOb = SIZE_OBSTACLE;

	// Input current date time to saved.date
	//https://stackoverflow.com/questions/16357999/current-date-and-time-as-string
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[TIME_LENGTH + 1];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	std::string str(buffer);
	saved.date = str;

	// Luu file
	ofstream stream;
	stream.open("saves/save_" + to_string(slot) + ".txt");
	stream << saved.name << endl;
	stream << saved.date << endl;
	stream << saved;
	stream.close();
}

// Khoi tao mang SAVEDDATA khi vao chuong trinh
void InitSavedData() {
	for (int i = 0; i < MAX_SAVE_SLOTS; i++) {
		SAVEDDATA[i] = loadFile(i + 1);
	}
}

