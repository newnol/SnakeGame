#pragma execution_character_set( "utf-8" )
#include "Menu.h"
#include "GamePlay.h"
#include "SaveGame.h"
using namespace std;

int MODE;

// Dem nguoc thoi gian
void CountDown() {
	setFont(L"Terminal", 12, 24);
	fixConsoleWindow();
	SetConsoleOutputCP(65001);
	if (SOUND) {
		PlaySoundW(L"resources/sfx/countdown.wav", NULL, SND_ASYNC);
	}
	setOutputColor(Green, White);
	GoToXY(0, 15);
	wcout << u8R"(
                                                         ██████╗ 
                                                         ╚════██╗
                                                          █████╔╝
                                                          ╚═══██╗
                                                         ██████╔╝
                                                         ╚═════╝ )";
	Sleep(1000);
	system("cls");
	setOutputColor(Yellow, White);
	GoToXY(0, 15);
	wcout << u8R"(
                                                         ██████╗ 
                                                         ╚════██╗
                                                          █████╔╝
                                                         ██╔═══╝ 
                                                         ███████╗
                                                          ╚═════╝ )";
	Sleep(1000);
	system("cls");
	setOutputColor(Red, White);
	GoToXY(0, 15);
	wcout << u8R"(
                                                            ██╗
                                                           ███║
                                                           ╚██║
                                                            ██║
                                                            ██║
                                                            ╚═╝ )";
	Sleep(1000);
	system("cls");
	setOutputColor(Blue, White);
	GoToXY(0, 15);
	wcout << u8R"(
                                          ███████╗████████╗ █████╗ ██████╗ ████████╗
                                          ██╔════╝╚══██╔══╝██╔══██╗██╔══██╗╚══██╔══╝
                                          ███████╗   ██║   ███████║██████╔╝   ██║   
                                          ╚════██║   ██║   ██╔══██║██╔══██╗   ██║   
                                          ███████║   ██║   ██║  ██║██║  ██║   ██║   
                                          ╚══════╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   )";
	Sleep(1000);
	system("cls");
	setOutputColor(Black, White);
}

// Hien level tren PlayArea
void UILevel(int x, int y) {
	if (LEVEL == 1) {
		GoToXY(x, y);
		wcout << u8R"(░█░░░█▀▀░█░█░█▀▀░█░░░░░▀█░)";
		GoToXY(x, y + 1);
		wcout << u8R"(░█░░░█▀▀░▀▄▀░█▀▀░█░░░░░░█░)";
		GoToXY(x, y + 2);
		wcout << u8R"(░▀▀▀░▀▀▀░░▀░░▀▀▀░▀▀▀░░░▀▀▀)";
	}
	if (LEVEL == 2) {
		GoToXY(x, y);
		wcout << u8R"(░█░░░█▀▀░█░█░█▀▀░█░░░░░▀▀▄)";
		GoToXY(x, y + 1);
		wcout << u8R"(░█░░░█▀▀░▀▄▀░█▀▀░█░░░░░▄▀░)";
		GoToXY(x, y + 2);
		wcout << u8R"(░▀▀▀░▀▀▀░░▀░░▀▀▀░▀▀▀░░░▀▀▀)";
	}
	if (LEVEL == 3) {
		GoToXY(x, y);
		wcout << u8R"(░█░░░█▀▀░█░█░█▀▀░█░░░░░▀▀█)";
		GoToXY(x, y + 1);
		wcout << u8R"(░█░░░█▀▀░▀▄▀░█▀▀░█░░░░░░▀▄)";
		GoToXY(x, y + 2);
		wcout << u8R"(░▀▀▀░▀▀▀░░▀░░▀▀▀░▀▀▀░░░▀▀▀)";
	}
	if (LEVEL == 4) {
		GoToXY(x, y);
		wcout << u8R"(░█░░░█▀▀░█░█░█▀▀░█░░░░░█░█)";
		GoToXY(x, y + 1);
		wcout << u8R"(░█░░░█▀▀░▀▄▀░█▀▀░█░░░░░░▀█)";
		GoToXY(x, y + 2);
		wcout << u8R"(░▀▀▀░▀▀▀░░▀░░▀▀▀░▀▀▀░░░░░▀)";
	}//.........................
}

// Load Game Menu
void menuLoadGame() {
	// Variables
	InitSavedData();
	Point box{ 3, 11 };
	int x = 18;
	int selected = 1;

	// Dram table
	system("cls");
	system("Color F0");
	SetConsoleOutputCP(65001);
	setFont(L"Terminal", 15, 18);
	fixConsoleWindow();
	GoToXY(x, 3);
	wcout << u8R"(██       ██████   █████  ██████       ██████   █████  ███    ███ ███████)";
	GoToXY(x, 3 + 1);
	wcout << u8R"(██      ██    ██ ██   ██ ██   ██     ██       ██   ██ ████  ████ ██)";
	GoToXY(x, 3 + 2);
	wcout << u8R"(██      ██    ██ ███████ ██   ██     ██   ███ ███████ ██ ████ ██ █████)";
	GoToXY(x, 3 + 3);
	wcout << u8R"(██      ██    ██ ██   ██ ██   ██     ██    ██ ██   ██ ██  ██  ██ ██)";
	GoToXY(x, 3 + 4);
	wcout << u8R"(███████  ██████  ██   ██ ██████       ██████  ██   ██ ██      ██ ███████)";
	GoToXY(x + 23, 9);
	cout << "PRESS ESC TO RETURN MENU" << endl;
	drawBox(box, 98, 25, Black);
	drawBox(box, 98, 3, Black);
	setOutputColor(Black, White);
	GoToXY(10, 13);
	cout << "SLOT";
	GoToXY(32, 13);
	cout << "NAME";
	GoToXY(50, 13);
	cout << "LEVEL";
	GoToXY(65, 13);
	cout << "SCORE";
	GoToXY(85, 13);
	cout << "DATE";

	// Draw Slots
	while (true) {
		for (int i = 1; i <= MAX_SAVE_SLOTS; i++) {
			if (i == selected) {
				printSlot(8, 16, i, Black, Yellow);
			}
			else {
				printSlot(8, 16, i, Black, White);
			}
		}
		int input = _getch();
		GoToXY(x + 23, 40);
		setOutputColor(White, White);
		cout << "                          ";
		switch (input) {
		case UP:
			selected--; 
			if (selected < 1) {
				selected = MAX_SAVE_SLOTS; 
			}
			break;
		case DOWN:
			selected++; 
			if (selected > MAX_SAVE_SLOTS) {
				selected = 1; 
			}
			break;
		case LEFT:      break;

		case RIGHT:     break;

		case ENTER:
			// Case load success
			if (SAVEDDATA[selected - 1].exist) {
				loadData(selected - 1);
				StartGameLoad();
				PlayGame();
				return;
			}
			// Case Error
			else {
				GoToXY(x + 23, 40);
				setOutputColor(Black, White);
				cout << "ERROR. PLEASE CHOOSE AGAIN";
				break;
			}

		case ESC: // Case return main menu
			system("cls");
			menuFunc();
			return;

		default:
			break;
		}

	}
}

// Save Game menu
void menuSaveGame() {
	// Variables
	InitSavedData();
	string name;
	Point box{ 3, 11 };
	int x = 18;
	int selected = 1;

	// Draw table
	system("cls");
	system("Color F0");
	SetConsoleOutputCP(65001);
	setFont(L"Terminal", 15, 18);
	fixConsoleWindow();
	GoToXY(x, 3);
	wcout << u8R"(███████  █████  ██    ██ ███████      ██████   █████  ███    ███ ███████)";
	GoToXY(x, 3 + 1);
	wcout << u8R"(██      ██   ██ ██    ██ ██          ██       ██   ██ ████  ████ ██      )";
	GoToXY(x, 3 + 2);
	wcout << u8R"(███████ ███████ ██    ██ █████       ██   ███ ███████ ██ ████ ██ █████   )";
	GoToXY(x, 3 + 3);
	wcout << u8R"(     ██ ██   ██  ██  ██  ██          ██    ██ ██   ██ ██  ██  ██ ██      )";
	GoToXY(x, 3 + 4);
	wcout << u8R"(███████ ██   ██   ████   ███████      ██████  ██   ██ ██      ██ ███████)";
	GoToXY(x + 23, 9);
	cout << "PRESS ESC TO RETURN MENU" << endl;
	drawBox(box, 98, 25, Black);
	drawBox(box, 98, 3, Black);
	setOutputColor(Black, White);
	GoToXY(10, 13);
	cout << "SLOT";
	GoToXY(32, 13);
	cout << "NAME";
	GoToXY(50, 13);
	cout << "LEVEL";
	GoToXY(65, 13);
	cout << "SCORE";
	GoToXY(85, 13);
	cout << "DATE";

	// Draw slots
	while (true) {
		for (int i = 1; i <= MAX_SAVE_SLOTS; i++) {
			if (i == selected) {
				printSlot(8, 16, i, Black, Yellow);
			}
			else {
				printSlot(8, 16, i, Black, White);
			}
		}

		// Input
		int input = _getch();
		switch (input) {
		case UP:
			selected--; 
			if (selected < 1) {
				selected = MAX_SAVE_SLOTS;
			}
			break;
		case DOWN:
			selected++; 
			if (selected > MAX_SAVE_SLOTS) {
				selected = 1;
			}
			break;
		case LEFT:       break;

		case RIGHT:          break;

		case ENTER: // Case Save
			setOutputColor(Black, White);
			GoToXY(20, 40);
			cout << "Enter save name (10 chars): ";
	
			getline(cin, name);
			if (name.length() > 10) {
				name.resize(10);
			}
			saveFile(name, selected);
			menuFunc();
			return;

		case ESC: // Case Return Menu
			menuFunc();
			return;

		default:
			break;
		}

	}
}

// Print slots
void printSlot(int x, int y, int slot, int text, int BG) {
	setOutputColor(text, BG);
	GoToXY(x - 4, y + slot);
	for (int i = 0; i < 97; i++) cout << " ";
	GoToXY(x, y + slot);
	cout << "SLOT " << slot;
	GoToXY(x + 22, y + slot);
	if (SAVEDDATA[slot-1].exist == true) {
		cout << SAVEDDATA[slot-1].name;
	}
	else {
		cout << "<EMPTY>";
	}
	GoToXY(x + 44, y + slot);
	if (SAVEDDATA[slot-1].exist == true) {
		cout << SAVEDDATA[slot-1].data.level;
	}
	else {
			cout << "0";
	}
	GoToXY(x + 59, y + slot);
	if (SAVEDDATA[slot-1].exist == true) {
		cout << SAVEDDATA[slot-1].data.score;
	}
	else {
		cout << "0";
	}
	GoToXY(x + 69, y + slot);
	if (SAVEDDATA[slot-1].exist == true) {
		cout << SAVEDDATA[slot-1].date;
	}
	else {
		GoToXY(83, y + slot);
		cout << "<EMPTY>";
	}
	
}

