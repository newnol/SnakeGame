#pragma execution_character_set( "utf-8" )
#include "Bitmap.h"


HBITMAP gameover;
HBITMAP press;
HBITMAP pressB;
HBITMAP win;

bool SOUND = true;
bool MUSIC = true;
int COLOR = Blue;
// Function to load a bitmap from a file
HBITMAP LoadBitmapFromFile(LPCWSTR filename) {
    return (HBITMAP)LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

// Function to draw a bitmap at a given position
void DrawBitmap(HBITMAP hBitmap, int x, int y) {
    HWND hwndConsole = GetConsoleWindow();
    HDC hdc = GetDC(hwndConsole);
    BITMAP bitmap;
    HDC hdcMem = CreateCompatibleDC(hdc);
    SelectObject(hdcMem, hBitmap);
    GetObject(hBitmap, sizeof(bitmap), &bitmap);
    BitBlt(hdc, x, y, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
    DeleteDC(hdcMem);
    ReleaseDC(hwndConsole, hdc);
}
int DifficultyMenu() {
    system("color F0");
    HBITMAP title = LoadBitmapFromFile(L"resources/bmp/play/Title2.bmp");
    HBITMAP choose = LoadBitmapFromFile(L"resources/bmp/diff/Choose.bmp");
    DrawBitmap(title, 400, 30);
    DrawBitmap(choose, 490, 250);
    HBITMAP easy = LoadBitmapFromFile(L"resources/bmp/diff/Easy.bmp");
    HBITMAP normal = LoadBitmapFromFile(L"resources/bmp/diff/Normal.bmp");
    HBITMAP hard = LoadBitmapFromFile(L"resources/bmp/diff/Hard.bmp");
    DrawBitmap(easy, 500, 400);
    DrawBitmap(normal, 850, 400);
    DrawBitmap(hard, 1200, 400);
    HBITMAP arrow = LoadBitmapFromFile(L"resources/bmp/diff/Arrow.bmp");
    HBITMAP blank = LoadBitmapFromFile(L"resources/bmp/diff/Blank.bmp");

    int option = 1;
    while (true) {
        if (option == 1) {
            DrawBitmap(arrow, 550, 620);
            DrawBitmap(blank, 900, 620);
            DrawBitmap(blank, 1250, 620);
            if(SOUND)PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);
            Sleep(300);
        }
        if (option == 2) {
            DrawBitmap(blank, 550, 620);
            DrawBitmap(arrow, 900, 620);
            DrawBitmap(blank, 1250, 620);
            if(SOUND)PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);
            Sleep(300);
        }
        if (option == 3) {
            DrawBitmap(blank, 550, 620);
            DrawBitmap(blank, 900, 620);
            DrawBitmap(arrow, 1250, 620);
            if(SOUND)PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);
            Sleep(300);
        }

        int input = _getch();
        switch (input) {
        case LEFT:
            option--;
            if (option <= 0) {
                option = 3;
            }
            break;
        case RIGHT:
            option++;
            if (option > 3) {
                option = 1;
            }
            break;
        case UP:       break;

        case DOWN:          break;

        case ENTER:
            DeleteObject(title);
            DeleteObject(choose);
            DeleteObject(easy);
            DeleteObject(normal);
            DeleteObject(hard);
            DeleteObject(arrow);
            return option;

        case ESC:
            DeleteObject(title);
            DeleteObject(choose);
            DeleteObject(easy);
            DeleteObject(normal);
            DeleteObject(hard);
            DeleteObject(arrow);
            return 0;

        default:
            break;
        }

    }
}

int bmpMenu() {
    int max_option = 5;
    int option = 1;
    fixConsoleWindow();
    setcursor(0, 0);
    system("cls");
    system("color F0");

    HBITMAP hBitmap1 = LoadBitmapFromFile(L"resources/bmp/play/play01.bmp");
    HBITMAP hBitmap2 = LoadBitmapFromFile(L"resources/bmp/play/play02.bmp");
    HBITMAP title = LoadBitmapFromFile(L"resources/bmp/play/Title2.bmp");
    HBITMAP icon = LoadBitmapFromFile(L"resources/bmp/play/Death.bmp");
    HBITMAP load = LoadBitmapFromFile(L"resources/bmp/play/Load.bmp");
    HBITMAP setting = LoadBitmapFromFile(L"resources/bmp/play/Settings.bmp");
    HBITMAP dev = LoadBitmapFromFile(L"resources/bmp/play/Dev.bmp");
    HBITMAP replay1 = LoadBitmapFromFile(L"resources/bmp/play/replay01.bmp");
    HBITMAP replay2 = LoadBitmapFromFile(L"resources/bmp/play/replay02.bmp");
    HBITMAP option1 = LoadBitmapFromFile(L"resources/bmp/play/option01.bmp");
    HBITMAP option2 = LoadBitmapFromFile(L"resources/bmp/play/option02.bmp");
    HBITMAP about1 = LoadBitmapFromFile(L"resources/bmp/play/about01.bmp");
    HBITMAP about2 = LoadBitmapFromFile(L"resources/bmp/play/about02.bmp");
    HBITMAP tutorial = LoadBitmapFromFile(L"resources/bmp/tutorial/tutorial.bmp");
    HBITMAP leaderBut = LoadBitmapFromFile(L"resources/bmp/play/leaderboard01.bmp");
    HBITMAP leaderBut2 = LoadBitmapFromFile(L"resources/bmp/play/leaderboard02.bmp");




    DrawBitmap(title, 400, 30);
    DrawBitmap(icon, 370, 220);
    DrawBitmap(hBitmap1, 1100, 175);
    DrawBitmap(replay1, 1100, 325);
    DrawBitmap(option1, 1100, 475);
    DrawBitmap(about1, 1100, 625);
    DrawBitmap(leaderBut, 1100, 775);




    while (true) {
        if (option == 1) {
            DrawBitmap(icon, 370, 220);
            DrawBitmap(hBitmap2, 1100, 175);
            DrawBitmap(replay1, 1100, 325);
            DrawBitmap(option1, 1100, 475);
            DrawBitmap(about1, 1100, 625);
            DrawBitmap(leaderBut, 1100, 775);

            /*if (SOUND) PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);*/
            Sleep(300);
        }
        if (option == 2) {
            DrawBitmap(load, 370, 220);
            DrawBitmap(hBitmap1, 1100, 175);
            DrawBitmap(replay2, 1100, 325);
            DrawBitmap(option1, 1100, 475);
            DrawBitmap(about1, 1100, 625);
            DrawBitmap(leaderBut, 1100, 775);

            /*if (SOUND) PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);*/
            Sleep(300);
        }
        if (option == 3) {
            DrawBitmap(setting, 370, 220);
            DrawBitmap(hBitmap1, 1100, 175);
            DrawBitmap(replay1, 1100, 325);
            DrawBitmap(option2, 1100, 475);
            DrawBitmap(about1, 1100, 625);
            DrawBitmap(leaderBut, 1100, 775);

            /* if (SOUND)
                 PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);*/
            Sleep(300);
        }
        if (option == 4) {
            DrawBitmap(dev, 370, 220);
            DrawBitmap(hBitmap1, 1100, 175);
            DrawBitmap(replay1, 1100, 325);
            DrawBitmap(option1, 1100, 475);
            DrawBitmap(about2, 1100, 625);
            DrawBitmap(leaderBut, 1100, 775);

            /*if (SOUND)
                PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);*/
            Sleep(300);
        }
        if (option == 5) {
            DrawBitmap(dev, 370, 220);
            DrawBitmap(hBitmap1, 1100, 175);
            DrawBitmap(replay1, 1100, 325);
            DrawBitmap(option1, 1100, 475);
            DrawBitmap(about1, 1100, 625);
            DrawBitmap(leaderBut2, 1100, 775);

            /*if (SOUND)
                PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);*/
            Sleep(300);
        }

        int input = _getch();
        switch (input) {
        case UP:
            if (SOUND) PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);
            option--;
            if (option <= 0) {
                option = max_option;
            }
            break;
        case DOWN:
            if (SOUND) PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);
            option++;
            if (option > max_option) {
                option = 1;
            }
            break;
        case LEFT:       break;

        case RIGHT:          break;

        case ENTER:
            if (option == 1) {
                MODE = DifficultyMenu();
                if (MODE == 0) {
                    system("color F0");
                    DrawBitmap(title, 400, 30);
                    DrawBitmap(icon, 320, 220);
                    break;
                }
                else {
                    DeleteObject(title);
                    DeleteObject(icon);
                    DeleteObject(load);
                    DeleteObject(setting);
                    DeleteObject(dev);
                    DeleteObject(hBitmap1);
                    DeleteObject(hBitmap2);
                    DeleteObject(replay1);
                    DeleteObject(replay2);
                    DeleteObject(option1);
                    DeleteObject(option2);
                    DeleteObject(about1);
                    DeleteObject(about2);
                    DeleteObject(leaderBut);
                    DeleteObject(leaderBut2);
                    return 1;
                }
            }
            else {
                return option;
            }
            break;

        case ESC:
            DeleteObject(title);
            DeleteObject(icon);
            DeleteObject(load);
            DeleteObject(setting);
            DeleteObject(dev);
            DeleteObject(hBitmap1);
            DeleteObject(hBitmap2);
            DeleteObject(replay1);
            DeleteObject(replay2);
            DeleteObject(option1);
            DeleteObject(option2);
            DeleteObject(about1);
            DeleteObject(about2);
            DeleteObject(leaderBut);
            DeleteObject(leaderBut2);
            return 0;

        default:
            break;
        }
    }
}

void menuFunc() {
    int option = bmpMenu();
    if (option == 1) {
        StartGame();
        PlayGame();
        return;
    }
    if (option == 2) {
        menuLoadGame();
        return;
    }
    if (option == 3) {
        bmpSetting();
        return;
    }
    if (option == 4) {
        bmpAbout();
        //return;
    }
    if (option == 5) {
        MenuLegend();
    }
    if (option == 0) {
        int t = bmpExit();
        if (t == 1) {
            /*HWND hwnd = GetConsoleWindow();
            if (hwnd != NULL) {
                ShowWindow(hwnd, SW_HIDE);
            }*/
            system("cls");
            system("color F0");
            HBITMAP exit = LoadBitmapFromFile(L"resources/bmp/exit/Thanks.bmp");
            DrawBitmap(exit, 250, 400);
            Sleep(700);
            DeleteObject(exit);
            system("cls");
            return;
        }
        if (t == 2 || t == 0) {
            menuFunc();
            return;
        }
    }
}


void bmpGameOver() {
    if (SOUND) PlaySoundW(L"resources/sfx/GameOver.wav", 0, SND_ASYNC);
    Sleep(1500);
    //fixConsoleWindow();
    //setcursor(0, 0);
    system("cls");
    system("color F0");
    gameover = LoadBitmapFromFile(L"resources/bmp/over/GameOver.bmp");
    press = LoadBitmapFromFile(L"resources/bmp/over/press.bmp");
    pressB = LoadBitmapFromFile(L"resources/bmp/over/pressB.bmp");
    DrawBitmap(gameover, 580, 100);
    DrawBitmap(press, 320, 700);
}

void bmpWin()
{
    if (SOUND) PlaySoundW(L"resources/sfx/Win.wav", 0, SND_ASYNC);
    Sleep(1500);
    //fixConsoleWindow();
    //setcursor(0, 0);
    system("cls");
    system("color F0");
    win = LoadBitmapFromFile(L"resources/bmp/win/win.bmp");
    press = LoadBitmapFromFile(L"resources/bmp/over/press.bmp");

    DrawBitmap(win, 580, 300);
    DrawBitmap(press, 320, 700);
}

int bmpExit() {

    fixConsoleWindow();
    setcursor(0, 0);
    //system("cls");
    system("color F0");

    HBITMAP snake = LoadBitmapFromFile(L"resources/bmp/play/snake.bmp");
    HBITMAP exit = LoadBitmapFromFile(L"resources/bmp/play/Exit.bmp");
    HBITMAP yes1 = LoadBitmapFromFile(L"resources/bmp/play/yes01.bmp");
    HBITMAP yes2 = LoadBitmapFromFile(L"resources/bmp/play/yes02.bmp");
    HBITMAP no1 = LoadBitmapFromFile(L"resources/bmp/play/no01.bmp");
    HBITMAP no2 = LoadBitmapFromFile(L"resources/bmp/play/no02.bmp");

    DrawBitmap(snake, 0, 0);
    DrawBitmap(exit, 1100, 100);
    DrawBitmap(yes1, 1290, 450);
    DrawBitmap(no1, 1290, 700);

    int option = 1;
    while (true) {
        if (option == 1) {
            DrawBitmap(yes2, 1290, 450);
            DrawBitmap(no1, 1290, 700);
            Sleep(300);
        }
        if (option == 2) {
            DrawBitmap(yes1, 1290, 450);
            DrawBitmap(no2, 1290, 700);
            Sleep(300);
        }
   
        int input = _getch();
        switch (input) {
        case UP:
            if(SOUND)PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);
            option--;
            if (option < 1) {
                option = 2;
            }
            break;
        case DOWN:
            if(SOUND)PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);
            option++;
            if (option > 2) {
                option = 1;
            }
            break;
        case LEFT:       break;

        case RIGHT:          break;

        case ENTER:
            DeleteObject(snake);
            DeleteObject(exit);
            DeleteObject(yes1);
            DeleteObject(yes2);
            DeleteObject(no1);
            DeleteObject(no2);
            return option;
            break;

        case ESC:
            DeleteObject(snake);
            DeleteObject(exit);
            DeleteObject(yes1);
            DeleteObject(yes2);
            DeleteObject(no1);
            DeleteObject(no2);
            return 2;

        default:
            break;
        }
    }
}

void bmpAbout() {
	fixConsoleWindow();
	setcursor(0, 0);
	system("cls");
	system("color F0");

	HBITMAP about = LoadBitmapFromFile(L"resources/bmp/about/Group.bmp");
	//HBITMAP back = LoadBitmapFromFile(L"resources/bmp/play/Back.bmp");
    if (about == NULL) {
		cout << "Error: " << GetLastError() << endl;
		return;
	}
	DrawBitmap(about, 0, 0);
	//DrawBitmap(back, 1290, 700);

    while (true) {
		int input = _getch();
        if (input == ESC) {
			DeleteObject(about);
			menuFunc();
			return;
		}
	}
}

void bmpSetting()
{
    fixConsoleWindow();
    setcursor(0, 0);
    system("cls");
    system("color f0");
    
    //Point box{ 3, 11 };
    //int x = 18;
    //SetConsoleOutputCP(65001);
    //setFont(L"Terminal", 15, 18);
    ///*GoToXY(x, 3);
    //wcout << u8R"(███████ ███████ ████████ ████████ ██ ███    ██  ██████  ███████ )";
    //GoToXY(x, 3 + 1);
    //wcout << u8R"(██      ██         ██       ██    ██ ████   ██ ██       ██      )";
    //GoToXY(x, 3 + 2);
    //wcout << u8R"(███████ █████      ██       ██    ██ ██ ██  ██ ██   ███ ███████ )";
    //GoToXY(x, 3 + 3);
    //wcout << u8R"(     ██ ██         ██       ██    ██ ██  ██ ██ ██    ██      ██ )";
    //GoToXY(x, 3 + 4);
    //wcout << u8R"(███████ ███████    ██       ██    ██ ██   ████  ██████  ███████ )";
    //GoToXY(x + 23, 9);
    //cout << "PRESS ESC TO RETURN MENU" << endl;*/
    //drawBox(box, 40, 30, Black);
    HBITMAP snake = LoadBitmapFromFile(L"resources/bmp/setting/snake.bmp");
    HBITMAP play = LoadBitmapFromFile(L"resources/bmp/setting/Play.bmp");
    HBITMAP title = LoadBitmapFromFile(L"resources/bmp/setting/TITLE.bmp");
    HBITMAP music = LoadBitmapFromFile(L"resources/bmp/setting/MUSIC.bmp");
    HBITMAP sound = LoadBitmapFromFile(L"resources/bmp/setting/SOUND.bmp");
    HBITMAP color = LoadBitmapFromFile(L"resources/bmp/setting/COLOR.bmp");
    HBITMAP music1 = LoadBitmapFromFile(L"resources/bmp/setting/MUSIC1.bmp");
    HBITMAP sound1 = LoadBitmapFromFile(L"resources/bmp/setting/SOUND1.bmp");
    HBITMAP color1 = LoadBitmapFromFile(L"resources/bmp/setting/COLOR1.bmp");
    HBITMAP on = LoadBitmapFromFile(L"resources/bmp/setting/ON.bmp");
    HBITMAP off = LoadBitmapFromFile(L"resources/bmp/setting/OFF.bmp");
    HBITMAP blue = LoadBitmapFromFile(L"resources/bmp/setting/BLUE.bmp");
    HBITMAP yellow = LoadBitmapFromFile(L"resources/bmp/setting/YELLOW.bmp");
    HBITMAP aqua = LoadBitmapFromFile(L"resources/bmp/setting/AQUA.bmp");

    DrawBitmap(title, 100, 0);
    DrawBitmap(snake, 1500, 350);
    DrawBitmap(play, 0, 350);
    int selected = 1;
    int selected_1 = 1;
    if (!MUSIC) selected_1 = 2;
    int selected_2 = 1;
    if (!SOUND)selected_2 = 2;
    int selected_3 = 1;
    if (COLOR == Aqua) selected_3 = 2;
    if (COLOR == Yellow) selected_3 = 3;

    DrawBitmap(music1, 700, 350);
    DrawBitmap(color, 700, 850);
    DrawBitmap(sound, 700, 600);
    if (selected_1 == 1)DrawBitmap(on, 1100, 370);
    else DrawBitmap(off, 1100, 370);
    if (selected_2 == 1)DrawBitmap(on, 1100, 620);
    else DrawBitmap(off, 1100, 620);
    if (selected_3 == 1)DrawBitmap(blue, 1100, 870);
    else if (selected_3 == 2)DrawBitmap(aqua, 1100, 870);
    else DrawBitmap(yellow, 1100, 870);

    while (true)
    {
        int input = _getch();
        switch (input) {
        case UP:
            if (SOUND) PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);
            selected--;
            if (selected < 1) {
                selected = MAX_SETTINGS;
            }
            break;
        case DOWN:
            if (SOUND) PlaySoundW(L"resources/sfx/Button.wav", 0, SND_ASYNC);
            selected++;
            if (selected > MAX_SETTINGS) {
                selected = 1;
            }
            break;
        case LEFT:
            if (selected == 1)
            {
                selected_1--;
                if (selected_1 < 1)selected_1 = 2;
                if (selected_1 == 1)playMusic(true);
                else playMusic(false);
            }
            if (selected == 2)
            {
                selected_2--;
                if (selected_2 < 1)selected_2 = 2;
                if (selected_2 == 1)SOUND = true;
                else SOUND = false;
            }
            if (selected == 3)
            {
                selected_3--;
                if (selected_3 < 1)selected_3 = 3;
                if (selected_3 == 1)COLOR = Blue;
                else if (selected_3 == 2)COLOR = Aqua;
                else COLOR = Yellow;
            }
            break;
        case RIGHT:
            if (selected == 1)
            {
                selected_1++;
                if (selected_1 > 2)selected_1 = 1;
                if (selected_1 == 1)playMusic(true);
                else playMusic(false);
            }
            if (selected == 2)
            {
                selected_2++;
                if (selected_2 > 2)selected_2 = 1;
                if (selected_2 == 1)SOUND = true;
                else SOUND = false;
            }
            if (selected == 3)
            {
                selected_3++;
                if (selected_3 > 3)selected_3 = 1;
                if (selected_3 == 1)COLOR = Blue;
                else if (selected_3 == 2)COLOR = Aqua;
                else COLOR = Yellow;
            }
            break;
        case ESC: // Case Return Menu
            DeleteObject(title);
            DeleteObject(snake);
            DeleteObject(play);
            DeleteObject(sound);
            DeleteObject(sound1);
            DeleteObject(music);
            DeleteObject(music1);
            DeleteObject(color);
            DeleteObject(color1);
            DeleteObject(on);
            DeleteObject(off);
            DeleteObject(blue);
            DeleteObject(yellow);
            DeleteObject(aqua);
            setOutputColor(Black, White);
            system("cls");
            menuFunc();
            return;

        default:
            break;
        }
        if (selected == 1)
        {
           /* DeleteObject(sound1);
           DeleteObject(color1);
           DeleteObject(music);*/
           DrawBitmap(music1,700,350);
           DrawBitmap(color,700,850);
           DrawBitmap(sound, 700, 600);
           if (selected_1 == 1)DrawBitmap(on, 1100, 370);
           else DrawBitmap(off, 1100, 370);
           if (selected_2 == 1)DrawBitmap(on, 1100, 620);
           else DrawBitmap(off, 1100, 620);
           if (selected_3 == 1)DrawBitmap(blue, 1100, 870);
           else if (selected_3 == 2)DrawBitmap(aqua, 1100, 870);
           else DrawBitmap(yellow, 1100, 870);
           Sleep(300);
        }
        if (selected == 2)
        {
            /*DeleteObject(sound);
            DeleteObject(color1);
            DeleteObject(music1);*/
            DrawBitmap(music, 700, 350);
            DrawBitmap(color, 700, 850);
            DrawBitmap(sound1, 700, 600);
            if (selected_1 == 1)DrawBitmap(on, 1100, 370);
            else DrawBitmap(off, 1100, 370);
            if (selected_2 == 1)DrawBitmap(on, 1100, 620);
            else DrawBitmap(off, 1100, 620);
            if (selected_3 == 1)DrawBitmap(blue, 1100, 870);
            else if (selected_3 == 2)DrawBitmap(aqua, 1100, 870);
            else DrawBitmap(yellow, 1100, 870);
            Sleep(300);
        }
        if (selected == 3)
        {
            /*DeleteObject(sound1);
            DeleteObject(color);
            DeleteObject(music1);*/
            DrawBitmap(music, 7000, 350);
            DrawBitmap(color1, 700, 850);
            DrawBitmap(sound, 700, 600);
            if (selected_1 == 1)DrawBitmap(on, 1100, 370);
            else DrawBitmap(off, 1100, 370);
            if (selected_2 == 1)DrawBitmap(on, 1100, 620);
            else DrawBitmap(off, 1100, 620);
            if (selected_3 == 1)DrawBitmap(blue, 1100, 870);
            else if (selected_3 == 2)DrawBitmap(aqua, 1100, 870);
            else DrawBitmap(yellow, 1100, 870);
            Sleep(300);
        }
       
    }
}

void MenuLegend() {
    // Dram table
    system("cls");
    system("Color F0");
    //SetConsoleOutputCP(65001);
    setFont(L"default", 12, 18);
    fixConsoleWindow();
    setcursor(0, 0);
 
    HBITMAP leaderBoard = LoadBitmapFromFile(L"resources/bmp/leader/Legend.bmp");
    HBITMAP numberrow = LoadBitmapFromFile(L"resources/bmp/leader/number.bmp");
    //HBITMAP back = LoadBitmapFromFile(L"resources/bmp/play/Back.bmp");
    if (leaderBoard == NULL) {
        cout << "Error: " << GetLastError() << endl;
        return;
    }
    int pos = 30;
    setOutputColor(Black, White);
    GoToXY(22 + pos, 8);
    cout << "NAME";
    GoToXY(44 + pos, 8);
    cout << "LEVEL";
    GoToXY(59 + pos, 8);
    cout << "SCORE";


    for (int i = 0; i < 10; i++) {
        printSlotLegend(pos, 5 + 3 * i, i, Black, White);
    }
    DrawBitmap(leaderBoard, 0, 0);
    DrawBitmap(numberrow, pos-1, 190);

    //DrawBitmap(back, 1290, 700);

    while (true) {
        int input = _getch();
        if (input == ESC) {
            DeleteObject(leaderBoard);
            menuFunc();
            return;
        }
    }
}

void printSlotLegend(int x, int y, int slot, int text, int BG) {
    SavedData Lengend[10];
    for (int i = 0; i < MAX_SAVE_SLOTS; i++) {
        Lengend[i] = loadFile(i + 1);
    }
    //sort file
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (Lengend[i].data.score < Lengend[j].data.score)
                swap(Lengend[i], Lengend[j]);
        }
    }
    setOutputColor(text, BG);
    GoToXY(x + 22, y + slot);
    if (Lengend[slot - 1].exist == true) {
        cout << Lengend[slot - 1].name;
    }
    GoToXY(x+10, y + slot);
    if (Lengend[slot - 1].exist == true) {
        if (slot == 1) {
            setOutputColor(Yellow, BG);
            cout << slot;
            setOutputColor(text, BG);
        }if (slot == 2) {
            setOutputColor(Gray, BG);
            cout << slot;
            setOutputColor(text, BG);
        }if (slot == 3) {
            setOutputColor(Red, BG);
            cout << slot;
            setOutputColor(text, BG);
        }
        if (slot > 3)
            cout << slot;
    }
    else {
        return;
    }
    GoToXY(x + 44, y + slot);
    if (Lengend[slot - 1].exist == true) {
        cout << Lengend[slot - 1].data.level;
    }
    else {
        cout << "0";
    }
    GoToXY(x + 59, y + slot);
    if (Lengend[slot - 1].exist == true) {
        cout << Lengend[slot - 1].data.score;
    }
    else {
        cout << "0";
    }
}