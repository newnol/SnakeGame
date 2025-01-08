#include <fstream>
#include "Render.h"
using namespace std;

// Chuyen sang dinh dang font vuong (neu can tui co the lam ham doi font luon)
void playMusic(bool play) {
    if (play == true) {
	mciSendString(L"open \"resources/sfx/bgmusic.wav\" type mpegvideo alias wav", NULL, 0, NULL);
    //mciSendString(L"play wav play", NULL, 0, NULL);
    mciSendString(L"play wav repeat", NULL, 0, NULL);
    return;
    	}
	else {
        mciSendString(L"close wav", NULL, 0, NULL);
	}
}
void setFontSquare() {
    //Change to square font
    //https://stackoverflow.com/questions/46047495/changing-font-in-console-application-to-raster-font
    CONSOLE_FONT_INFOEX cf = { 0 };
    cf.cbSize = sizeof cf;
    cf.dwFontSize.X = 20; //Chieu dai
    cf.dwFontSize.Y = 20; //Chieu cao
    wcscpy_s(cf.FaceName, L"Terminal"); //Ten Font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
}

void setFont(const wchar_t* font, int sizeX, int sizeY) {
    CONSOLE_FONT_INFOEX cf = { 0 };
    cf.cbSize = sizeof cf;
    cf.dwFontSize.X = sizeX; //Chieu dai
    cf.dwFontSize.Y = sizeY; //Chieu cao
    wcscpy_s(cf.FaceName, font); //Ten Font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, &cf);
}

void setOutputColor(int text, int BG) {
    //textColor+ BGColor*16
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, text + BG * 16);
}

void GoToXY(int x, int y) {
    COORD coord;
    coord.X = x, coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void GoToXY(Point a) {
    COORD coord;
    coord.X = a.x, coord.Y = a.y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void fixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

    //Show the program frame with the max size
    ShowWindow(consoleWindow, SW_MAXIMIZE);

    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    if (size == 0)
    {
        size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void Animate(char a[], int x, int y) {
    const int screenWidth = 80;
    const int rectWidth = 5;
    int rectPosition = 0;
    int rectDirection = 1;

    // Vòng l?p chính
    while (true) {
        // Hi?n th? hình ch? nh?t trên màn hình console
        system("cls");
        for (int i = 0; i < rectPosition; ++i) {
            cout << ' ';
        }
        cout << "~( :)>>>" << a << ">>>>\n";

        /*for (int j = 0; j < ; j++)
            cout << a[j];*/


        cout << endl;
        // Di chuy?n hình ch? nh?t
        rectPosition += rectDirection;

        if (rectPosition == x) {

            break;
        }


        // T?m ngh? ?? h?n ch? t?c ?? vòng l?p
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

// An 4/2
// Xoa mot vung chi dinh theo mau da chon (chua xai)
void clearArea(Point TopLeft, Point BottomRight, int BG) {
    setOutputColor(BG, BG);
    for (int i = TopLeft.y; i <= BottomRight.y; i++) {
        for (int j = TopLeft.x; j <= BottomRight.x; j++) {
            GoToXY(j, i);
            cout << " ";
        }
    }
}

void clearAreaAnimation(Point TopLeft, Point BottomRight, int BG) {
	setOutputColor(BG, BG);
    for (int i = TopLeft.y; i <= BottomRight.y; i++) {
        for (int j = TopLeft.x; j <= BottomRight.x; j++) {
			GoToXY(j, i);
			cout << " ";
			this_thread::sleep_for(chrono::milliseconds(10));
		}
	}
}


void printMyFile(const char* fileName) {
    ifstream file(fileName);
    if (!file) {
        std::cout << "Failed to open file: " << fileName << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        std::cout << line << "\n";
    }

    file.close();
}


void box(int x, int y, int width, int height, int color)
{
    //draw the top line
    for (int i = x; i < x + width; i++) {
        GoToXY(i, y);
        cout << char(205);
    }
    //draw the bottom line
    for (int i = x; i < x + width; i++) {
        GoToXY(i, y + height);
        cout << char(205);
    }
    //draw the left line
    for (int i = y; i < y + height; i++) {
        GoToXY(x, i);
        cout << char(186);
    }
    //draw the right line
    for (int i = y; i < y + height; i++) {
        GoToXY(x + width, i);
        cout << char(186);
    }
    //draw the top left corner
    GoToXY(x, y);
    cout << char(201);
    //draw the top right corner
    GoToXY(x + width, y);
    cout << char(187);
    //draw the bottom left corner
    GoToXY(x, y + height);
    cout << char(200);
    //draw the bottom right corner
    GoToXY(x + width, y + height);
    cout << char(188);
}

void drawBox(Point a, int width, int height, int color)
{
    setOutputColor(color, color);
    //draw the top line
    for (int i = a.x; i <= a.x + width; i++) {
        GoToXY(i, a.y);
        cout << "*";
    }
    //draw the bottom line
    for (int i = a.x; i <= a.x + width; i++) {
        GoToXY(i, a.y + height);
        cout << char(186);
    }
    //draw the left line
    for (int i = a.y; i <= a.y + height; i++) {
        GoToXY(a.x, i);
        cout << char(186);
    }
    //draw the right line
    for (int i = a.y; i <= a.y + height; i++) {
        GoToXY(a.x + width, i);
        cout << char(186);
    }
}

void drawSnakeImage(Point a)
{
    ifstream fileIn;
    fileIn.open("resources/image/Snake.txt");
    if (fileIn.fail()) return;
    string snake[100];
    int i = 0;
    while (!fileIn.eof())
    {
        getline(fileIn, snake[i]);
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        GoToXY(a.x, a.y + j);
        for (int k = 0; k < snake[j].length(); k++)
        {
            switch (snake[j][k])
            {
            case '0':
                setOutputColor(Black, Black);
                cout << snake[j][k];
                break;

            case '9':
                setOutputColor(Red, Red);
                cout << snake[j][k];
                break;

            case ' ':
                setOutputColor(White, White);
                cout << snake[j][k];
                break;

            default:
                setOutputColor(COLOR, COLOR);
                cout << snake[j][k];
                break;
            }
        }
    }
    fileIn.close();
}
