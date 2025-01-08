#include "GamePlay.h"
using namespace std;

//global variable
Point snake[MAX_SIZE_SNAKE];
Point food[MAX_SIZE_FOOD];
Point gate[MAX_SIZE_GATE];//toa do cong qua man
Point obstacle[MAX_SIZE_OBSTACLE];//toa do chuong ngai vat

SpecialFood special_Food[MAX_SIZE_SPECIAL];

int toado_x[4];
int toado_y[4];
int playerScore = 0;
int PAUSE_STATE = 1;
bool EXIT;
int SIZE_SNAKE;//size of snake
int SIZE_OBSTACLE;//size of obstacle
int STATE;
int FOOD_IDX;
int SPECIAL_IDX;
bool SPECIAL;
int SIZE_SPECIAL = MAX_SIZE_SPECIAL;
int BLOCKED_CHAR;
int MOVE;
float SPEED = 1;
int LEVEL = 1;// game level
bool FOOD = true;//neu FOOD = true thi se in food len man hinh con FOOD = false se ngung in food len man hinh
char mssv[] = { '2','3','1','2','7','1','1','4',
				'2','3','1','2','7','0','2','0',
				'2','3','1','2','7','0','7','5',
				'2','3','1','2','7','4','7','0' };


//ham kiem tra toa do diem co hop le khong
bool PointValid(Point Position)
{
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		if (snake[i].x == Position.x && snake[i].y == Position.y)//neu toa do diem do trung voi toa do ran thi tra ve false
		{
			return false;
		}
	}
	if (LEVEL > 1)
	{
		for (int i = 0; i < SIZE_OBSTACLE; i++)
		{
			if (obstacle[i].x == Position.x && obstacle[i].y == Position.y || (LEVEL == 4 && Position.y == obstacle[i].y))//neu diem do trung voi toa do chuong ngai vat thi tra ve false
			{
				return false;
			}
		}
		if(LEVEL==4)
		{
			for (int i = 0; i < SIZE_OBSTACLE; i++)
			{
				if (obstacle[i].y==Position.y)
				{
					return false;
				}
			}
		}
	}
	if (LEVEL > 2)
	{
		for (int i = 0; i < SPECIAL_IDX; i++)
		{
			if (special_Food[i].pos.x == Position.x && special_Food[i].pos.y == Position.y)
			{
				return false;
			}
		}
	}
	
	return true;
}
//ham tao ra food
void GenerateFood()
{
	Point Position;
	srand((int)time(0));
	do {
		Position.x = rand() % (WIDTH - 2) + 1 + X_TABLE;
		Position.y = rand() % (HEIGH - 2) + 1 + Y_TABLE;
	} while (!PointValid(Position) || Position.x == food[FOOD_IDX - 1].x || Position.y == food[FOOD_IDX - 1].y);
	food[FOOD_IDX] = Position;//update lai (24/3)
}
void GenerateSpecial()
{
	SpecialFood special;
	srand((int)time(0));
	SPECIAL_IDX = 0;
	for (int i = 0; i < MAX_SIZE_SPECIAL; i++)
	{
		do {
			special.pos.x = rand() % (WIDTH - 2) + 1 + X_TABLE;
			special.pos.y = rand() % (HEIGH - 2) + 1 + Y_TABLE;
			special.func = rand() % 4;
		} while (!PointValid(special.pos));
		special_Food[SPECIAL_IDX++] = special;
	}
}
//ham khoi tao cong
void InitGate()
{
	srand((int)time(0));
	int option = rand() % 2;//neu bang 1 thi chon tuong tren hoac tuong duoi, neu bang 0 thi chon tuong trai hoac tuong phai
	if (option == 0)
	{
		do
		{
			gate[0].x = (rand() % 2 == 0) ? X_TABLE : X_TABLE_MAX;//neu bang 0 thi chon tuong trai, neu bang 1 thi chon tuong phai
			gate[0].y = rand() % (HEIGH - 4) + 2 + Y_TABLE;
			if (gate[0].x == X_TABLE)
			{
				gate[1].x = gate[0].x + 1; gate[1].y = gate[0].y - 1;
				gate[2].x = gate[0].x + 1; gate[2].y = gate[0].y + 1;
				gate[3].x = gate[0].x + 2; gate[3].y = gate[0].y - 1;
				gate[4].x = gate[0].x + 2; gate[4].y = gate[0].y + 1;
			}
			else
			{
				gate[1].x = gate[0].x - 1; gate[1].y = gate[0].y - 1;
				gate[2].x = gate[0].x - 1; gate[2].y = gate[0].y + 1;
				gate[3].x = gate[0].x - 2; gate[3].y = gate[0].y - 1;
				gate[4].x = gate[0].x - 2; gate[4].y = gate[0].y + 1;
			}
		} while (!PointValid(gate[1]) || !PointValid(gate[2]) || !PointValid(gate[3]) || !PointValid(gate[4]) || !PointValid(gate[0]));
	}
	else
	{
		do
		{
			gate[0].y = (rand() % 2 == 0) ? Y_TABLE : Y_TABLE_MAX;//neu bang 0 thi chon tuong tren, neu bang 1 thi chon tuong duoi
			gate[0].x = rand() % (WIDTH - 4) + 2 + X_TABLE;
			if (gate[0].y == Y_TABLE)
			{
				gate[1].x = gate[0].x - 1; gate[1].y = gate[0].y + 1;
				gate[2].x = gate[0].x + 1; gate[2].y = gate[0].y + 1;
				gate[3].x = gate[0].x - 1; gate[3].y = gate[0].y + 2;
				gate[4].x = gate[0].x + 1; gate[4].y = gate[0].y + 2;
			}
			else
			{
				gate[1].x = gate[0].x - 1; gate[1].y = gate[0].y - 1;
				gate[2].x = gate[0].x + 1; gate[2].y = gate[0].y - 1;
				gate[3].x = gate[0].x - 1; gate[3].y = gate[0].y - 2;
				gate[4].x = gate[0].x + 1; gate[4].y = gate[0].y - 2;
			}
		} while (!PointValid(gate[1]) || !PointValid(gate[2]) || !PointValid(gate[3]) || !PointValid(gate[4]) || !PointValid(gate[0]));
	}
}
//khoi tao toa do cua ran
void InitSnake()
{
	snake[0].x = X_TABLE + 5;
	snake[0].y = Y_TABLE_MAX - 3;
	for (int i = 1; i < SIZE_SNAKE; i++)
	{
		snake[i].x = snake[0].x - 1;
		snake[i].y = snake[0].y;
	}
}

void loadData(int slot) {
	SavedData saved = SAVEDDATA[slot];
	LEVEL = saved.data.level, playerScore = saved.data.score;
	FOOD_IDX = saved.data.food_idx, SPEED = saved.data.speed, SIZE_SNAKE = saved.data.sz_snake;
	BLOCKED_CHAR = saved.data.blocked, MOVE = saved.data.move, SIZE_OBSTACLE = saved.data.szOb, SIZE_SPECIAL = saved.data.szSpecial;
	for (int i = 0; i < SIZE_SNAKE; i++) {
		snake[i] = saved.data.snake[i];
	}
	for (int i = 0; i < MAX_SIZE_FOOD; i++) {
		food[i] = saved.data.food[i];
	}
	for (int i = 0; i < MAX_SIZE_GATE; i++) {
		gate[i] = saved.data.gate[i];
	}
	for (int i = 0; i < SIZE_OBSTACLE; i++)
	{
		obstacle[i] = saved.data.obstacle[i];
	}
	if (LEVEL >= 3) {
		for (int i = 0; i < SIZE_SPECIAL; i++)
		{
			special_Food[i] = saved.data.special[i];
		}
	}
}

//khoi tao cac du lieu
void InitData()
{
	playerScore = 0;
	SPEED = MODE * 2;
	BLOCKED_CHAR = 'A';
	MOVE = 'D';
	SIZE_SNAKE = 6;
	FOOD_IDX = 0;
	LEVEL = 1;
	EXIT = false;
	FOOD = true;
	InitSnake();
	GenerateFood();
}

void InitData2()
{
	BLOCKED_CHAR = 'A';
	MOVE = 'D';
	FOOD_IDX = 0;
	FOOD = true;
	InitSnake();
	if (LEVEL > 2)GenerateSpecial();
	GenerateFood();
	SPECIAL_IDX = 0;
}
//khoi tao chuong ngai vat man 2 va man 4
void InitObstacle_Level2()
{
	SIZE_OBSTACLE = WIDTH;
	obstacle[0].x = (WIDTH - (SIZE_OBSTACLE / 2)) / 2 + X_TABLE; obstacle[0].y = (HEIGH - 2) / 3 + Y_TABLE;
	for (int i = 1; i < SIZE_OBSTACLE / 2; i++)
	{
		obstacle[i].x = obstacle[i - 1].x + 1;
		obstacle[i].y = obstacle[i - 1].y;
	}
	obstacle[SIZE_OBSTACLE / 2].x = (WIDTH - (SIZE_OBSTACLE / 2)) / 2 + X_TABLE; obstacle[SIZE_OBSTACLE / 2].y = 2 * ((HEIGH - 2) / 3 + Y_TABLE);
	for (int i = (SIZE_OBSTACLE / 2) + 1; i < SIZE_OBSTACLE; i++)
	{
		obstacle[i].x = obstacle[i - 1].x + 1;
		obstacle[i].y = obstacle[i - 1].y;
	}
}
//khoi tao chuong ngai vat lv3
void InitObstacle_Level4()
{
	SIZE_OBSTACLE = (WIDTH / 2) * 6;
	obstacle[0].x = X_TABLE + 1; obstacle[0].y = Y_TABLE + 3 * (HEIGH / 10);
	int i = 3;
	int idx = 1;
	while (i < 9)
	{
		if (i % 2 == 1)
		{
			for (int j = 1; j < WIDTH / 2; j++)
			{
				obstacle[idx].x = obstacle[idx - 1].x + 1;
				obstacle[idx].y = obstacle[idx - 1].y;
				idx++;
			}
			i++;
			obstacle[idx].x = X_TABLE_MAX - 1; obstacle[idx++].y = Y_TABLE + i * (HEIGH / 10);
		}
		else
		{
			for (int j = 1; j < WIDTH / 2; j++)
			{
				obstacle[idx].x = obstacle[idx - 1].x - 1;
				obstacle[idx].y = obstacle[idx - 1].y;
				idx++;
			}
			i++;
			obstacle[idx].x = X_TABLE + 1; obstacle[idx++].y = Y_TABLE + i * (HEIGH / 10);
		}
	}
}
//draw obstacle level 4
void InitObstacle_Level3()
{
	SIZE_OBSTACLE = (WIDTH / 5) * 5 * (HEIGH / 5);
	int idx = 0;
	for (int i = 0; i < HEIGH / 5; i++)
	{
		obstacle[idx].x = X_TABLE + 5; obstacle[idx++].y = Y_TABLE + 5 + i;
		for (int j = 1; j < WIDTH / 5; j++)
		{
			obstacle[idx].x = obstacle[idx - 1].x + 1;
			obstacle[idx].y = obstacle[idx - 1].y;
			idx++;
		}
	}
	for (int i = 0; i < HEIGH / 5; i++)
	{
		obstacle[idx].x = X_TABLE + 5; obstacle[idx++].y = Y_TABLE_MAX - 5 - i;
		for (int j = 1; j < WIDTH / 5; j++)
		{
			obstacle[idx].x = obstacle[idx - 1].x + 1;
			obstacle[idx].y = obstacle[idx - 1].y;
			idx++;
		}
	}
	for (int i = 0; i < HEIGH / 5; i++)
	{
		obstacle[idx].x = X_TABLE_MAX - 5; obstacle[idx++].y = Y_TABLE + 5 + i;
		for (int j = 1; j < WIDTH / 5; j++)
		{
			obstacle[idx].x = obstacle[idx - 1].x - 1;
			obstacle[idx].y = obstacle[idx - 1].y;
			idx++;
		}
	}
	for (int i = 0; i < HEIGH / 5; i++)
	{
		obstacle[idx].x = X_TABLE_MAX - 5; obstacle[idx++].y = Y_TABLE_MAX - 5 - i;
		for (int j = 1; j < WIDTH / 5; j++)
		{
			obstacle[idx].x = obstacle[idx - 1].x - 1;
			obstacle[idx].y = obstacle[idx - 1].y;
			idx++;
		}
	}
	for (int i = 0; i < HEIGH / 5; i++)
	{
		obstacle[idx].x = (X_TABLE_MAX / 2) - 3; obstacle[idx++].y = (Y_TABLE_MAX / 2) + i;
		for (int j = 1; j < WIDTH / 5; j++)
		{
			obstacle[idx].x = obstacle[idx - 1].x + 1;
			obstacle[idx].y = obstacle[idx - 1].y;
			idx++;
		}
	}
}
void DrawMapLevel1(int width, int height)
{
	UILevel(X_TABLE + WIDTH / 4, Y_TABLE - 5);
	int x = X_TABLE; int y = Y_TABLE;
	GoToXY(x, y);
	if (x == X_TABLE && y == Y_TABLE)
	{
		setOutputColor(Green, Green);
	}
	for (int i = X_TABLE; i <= X_TABLE_MAX; i++)
	{
		cout << "+";
		setOutputColor(Green, Green);
	}
	GoToXY(x, Y_TABLE_MAX);
	for (int i = X_TABLE; i <= X_TABLE_MAX; i++)
	{
		cout << "+";
		setOutputColor(Green, Green);
	}
	for (int i = y; i <= Y_TABLE_MAX; i++)
	{
		GoToXY(X_TABLE_MAX, i);
		cout << "+";
		setOutputColor(Green, Green);
		GoToXY(x, i);
		cout << "+";
		setOutputColor(Green, Green);
	}
	drawScore(Black, LYellow);
}


//ham ve map lv2
void DrawMapLevel2_3_4(int width, int height)
{
	DrawMapLevel1(width, height);
	//Ve chuong ngai vat
	setOutputColor(Gray, Gray);
	for (int i = 0; i < SIZE_OBSTACLE; i++)
	{
		GoToXY(obstacle[i].x, obstacle[i].y);
		cout << "+";
		setOutputColor(Gray, Gray);
	}
}

void StartGame()
{
	system("cls");
	system("Color F0");
	CountDown();
	setFontSquare();
	InitData();
	DrawMapLevel1(WIDTH, HEIGH);
	STATE = 1;
}

void StartGameLoad()
{
	system("cls");
	system("Color F0");
	EXIT = false;
	CountDown();
	setFontSquare();
	if (LEVEL == 1)
	{
		DrawMapLevel1(WIDTH, HEIGH);
	}
	else
	{
		DrawMapLevel2_3_4(WIDTH, HEIGH);
	}
	if (FOOD_IDX == -1)
	{
		FOOD = false;
		DrawGate();//ve cong qua man
	}
	if (LEVEL >= 3)
	{
		SPECIAL = true;
		DrawFood();
	}
	STATE = 1;
}
//ham bat dau lv2
void StartLevel2()
{
	system("cls");
	system("Color F0");
	CountDown();
	setFontSquare();//doi sang o vuong
	InitObstacle_Level2();
	InitData2();
	DrawMapLevel2_3_4(WIDTH, HEIGH);
	STATE = 1;
}
//ham bat dau lv3
void StartLevel3()
{
	system("cls");
	system("Color F0");
	CountDown();
	setFontSquare();//doi sang o vuong
	InitObstacle_Level3();
	SPECIAL = true;
	SIZE_SPECIAL = MAX_SIZE_SPECIAL;
	InitData2();
	DrawMapLevel2_3_4(WIDTH, HEIGH);
	SPECIAL = true;
	STATE = 1;
}
//ham bat dau lv4
void StartLevel4()
{
	system("cls");
	system("Color F0");
	CountDown();
	setFontSquare();//doi sang o vuong
	InitObstacle_Level4();
	SPECIAL = true;
	SIZE_SPECIAL = MAX_SIZE_SPECIAL;
	InitData2();
	DrawMapLevel2_3_4(WIDTH, HEIGH);
	STATE = 1;
}
void ExitGame(thread& t)
{
	EXIT = true;
	if (t.joinable()) {
		t.join();
	}
}
void PauseGame(HANDLE t)
{
	SuspendThread(t);
	PausedMenu(PAUSE_STATE);
}
void ProcessDead()
{
	STATE = 0;
	EXIT = true;
	bmpGameOver();
}

// Chinh sua de ve ran dep hon =))))
void DrawSnake(char* str, int color)
{
	setOutputColor(Blue, Yellow);
	GoToXY(snake[0].x, snake[0].y);
	cout << str[0];
	setOutputColor(White, color);
	for (int i = 1; i < SIZE_SNAKE; i++)
	{
		GoToXY(snake[i].x, snake[i].y);
		cout << str[i];
	}
	setOutputColor(White, White);
}
//ham ghi de khoang trang len toa do ran truoc do
void ClearSnake()
{
	setOutputColor(White, White);
	for (int i = 0; i < SIZE_SNAKE; i++)
	{
		GoToXY(snake[i].x, snake[i].y);
		cout << " ";
	}
}

//ham ve food
void DrawFood()
{
	if (LEVEL > 2 && SPECIAL) {
		for (int i = 0; i < SIZE_SPECIAL; i++)
		{
			setOutputColor(Red, Red);
			GoToXY(special_Food[i].pos.x, special_Food[i].pos.y);
			cout << " ";
		}
	}
	setOutputColor(White, Red);
	GoToXY(food[FOOD_IDX].x, food[FOOD_IDX].y);
	std::cout << mssv[SIZE_SNAKE];
	setOutputColor(White, White);
}
//ham ve cong
void DrawGate()
{
	setOutputColor(Yellow, Yellow);
	GoToXY(gate[0].x, gate[0].y);
	std::cout << " ";
	for (int i = 1; i <= 4; i++)
	{
		GoToXY(gate[i].x, gate[i].y);
		std::cout << "+";
	}
}

void drawScore(int color, int BG) {
	int TABLE_WIDTH = 18;
	setOutputColor(BG, BG);
	for (int j = Y_TABLE; j <= Y_TABLE_MAX; j++) {
		for (int i = X_TABLE_MAX + 1; i <= X_TABLE_MAX + TABLE_WIDTH; i++) {
			GoToXY(i, j);
			cout << "*";
		}
	}
	setOutputColor(color, BG);
	GoToXY(StatusPos);
	cout << "RUNNING";
	GoToXY(ScorePos);
	cout << "SCORE: " << playerScore;
	GoToXY(FoodPos);
	cout << "FOOD: ";
	if (FOOD_IDX != -1) cout << FOOD_IDX;
	else cout << MAX_SIZE_FOOD;
	cout << "/" << MAX_SIZE_FOOD;
	GoToXY(LengthPos);
	cout << "LENGTH: " << SIZE_SNAKE;
	GoToXY(ScoreBarPos);
	DrawScoreBar();
}
void DrawScoreBar()
{
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 2);
	setOutputColor(Black, Black);
	cout << "         ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 3);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 4);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 5);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 6);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 7);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 8);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 9);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 10);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 11);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 12);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 5, LengthPos.y + 13);
	cout << "         ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 3);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 4);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 5);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 6);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 7);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 8);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 9);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 10);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 11);
	setOutputColor(Black, Black);
	cout << " ";
	GoToXY(X_TABLE_MAX + 13, LengthPos.y + 12);
	setOutputColor(Black, Black);
	cout << " ";
	setOutputColor(Green, Green);
	if (FOOD_IDX == 0)
	{
		setOutputColor(LYellow, LYellow);
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 12);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 11);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 10);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 9);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 8);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 7);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 6);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 5);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 4);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 3);
		cout << "       ";
	}
	if (FOOD_IDX >= 1)
	{
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 11);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 12);
		cout << "       ";
	}
	if (FOOD_IDX >= 2)
	{
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 10);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 9);
		cout << "       ";
	}
	if (FOOD_IDX >= 3)
	{
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 8);
		setOutputColor(Green, Green);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 7);
		setOutputColor(Green, Green);
		cout << "       ";
	}
	if (FOOD_IDX >= 4)
	{
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 6);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 5);
		cout << "       ";
	}
	if (FOOD_IDX == -1)
	{
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 12);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 11);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 10);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 9);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 8);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 7);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 6);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 5);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 4);
		cout << "       ";
		GoToXY(X_TABLE_MAX + 6, LengthPos.y + 3);
		cout << "       ";
	}

}
void PausedMenu(int PauseState) {
	int TABLE_WIDTH = 18;
	int TABLE_COLOR = LYellow;
	setOutputColor(TABLE_COLOR, TABLE_COLOR);
	for (int j = Y_TABLE; j <= Y_TABLE_MAX; j++) {
		for (int i = X_TABLE_MAX + 1; i <= X_TABLE_MAX + TABLE_WIDTH; i++) {
			GoToXY(i, j);
			cout << "*";
		}
	}
	int res, save, menu;
	res = save = menu = White;
	setOutputColor(Black, LYellow);
	GoToXY(StatusPos);
	cout << "PAUSED ";
	if (PauseState == 1) {
		res = Yellow;
		save = menu = White;
	}
	if (PauseState == 2) {
		save = Yellow;
		res = menu = White;
	}
	if (PauseState == 3) {
		menu = Yellow;
		save = res = White;
	}
	setOutputColor(Black, res);
	GoToXY(ResumePos);
	cout << "           " << endl;
	GoToXY(ResumePos.x, ResumePos.y + 1);
	cout << "  RESUME   " << endl;
	GoToXY(ResumePos.x, ResumePos.y + 2);
	cout << "           " << endl;
	GoToXY(SavePos);
	setOutputColor(Black, save);
	cout << "           " << endl;
	GoToXY(SavePos.x, SavePos.y + 1);
	cout << " SAVE GAME " << endl;
	GoToXY(SavePos.x, SavePos.y + 2);
	cout << "           " << endl;
	GoToXY(MainMenuPos);
	setOutputColor(Black, menu);
	cout << "           " << endl;
	GoToXY(MainMenuPos.x, MainMenuPos.y + 1);
	cout << " MAIN MENU " << endl;
	GoToXY(MainMenuPos.x, MainMenuPos.y + 2);
	cout << "           " << endl;
}
void EatSpecialFood()
{
	if (SOUND)PlaySoundW(L"resources/sfx/Correct.wav", NULL, SND_ASYNC);
	if (special_Food[SPECIAL_IDX].func == 0)
	{
		playerScore += 2;
	}
	if (special_Food[SPECIAL_IDX].func == 1)
	{
		playerScore--;
	}
	if (special_Food[SPECIAL_IDX].func == 2)
	{
		SPEED++;
	}
	if (special_Food[SPECIAL_IDX].func == 3)
	{
		SPEED--;
	}
	//remove
	SpecialFood temp = special_Food[SPECIAL_IDX];
	special_Food[SPECIAL_IDX] = special_Food[SIZE_SPECIAL - 1];
	special_Food[SIZE_SPECIAL - 1] = temp;
	SIZE_SPECIAL--;
	if (SIZE_SPECIAL == 0)
	{
		SPECIAL = false;
		SPECIAL_IDX = -1;
	}
	drawScore(Black, LYellow);
	DrawFood();
}
void EatFood()
{
	//Play sound effect
	if (SOUND) {
		//https://stackoverflow.com/questions/9961949/playsound-in-c-console-application
		PlaySoundW(L"resources/sfx/Correct.wav", NULL, SND_ASYNC);
	}
	if (FOOD_IDX == MAX_SIZE_FOOD - 1)//neu nhu ran an full food
	{
		FOOD = false; // ngung ve food len man hinh
		FOOD_IDX = -1; // khong con toa do food tren man hinh
		playerScore++;
		SIZE_SNAKE++;
		InitGate();//khoi tao cong
		DrawGate();//ve cong qua man
	}
	else
	{
		SIZE_SNAKE++;
		FOOD_IDX++;
		playerScore++;
		GenerateFood();
		DrawFood();
	}
	drawScore(Black, LYellow);
}
// ham check ran co an ban than khong
bool CheckEatThemselves()
{
	for (int i = 1; i < SIZE_SNAKE; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y && snake[0].x != gate[0].x && snake[0].y != gate[0].y)// (4/2) cap nhat lai ham
		{
			return true;
		}
	}
	return false;
}
//check ran dung tuong cua cong
bool CheckTouchWallGate()
{
	for (int i = 1; i < MAX_SIZE_GATE; i++)
	{
		if (snake[0].x == gate[i].x && snake[0].y == gate[i].y)
		{
			return true;
		}
	}
	return false;
}
//di chuyen qua phai
void MoveRight()
{
	if (CheckEatThemselves())
	{
		ProcessDead();
		return;
	}
	if (CheckTouchWallGate() && FOOD == false)//neu nhu cham tuong cua gate luc gate da in ra man hinh thi ran chet
	{
		ProcessDead();
		return;
	}
	if (LEVEL > 1)
	{
		for (int i = 0; i < SIZE_OBSTACLE; i++)
		{
			if (snake[0].x + 1 == obstacle[i].x && snake[0].y == obstacle[i].y)//ran cham chuong ngai vat thi se chet
			{
				ProcessDead();
				break;
			}
		}
	}
	if (snake[0].x + 1== X_TABLE_MAX)//neu nhu ran cham tuong
	{
		if (FOOD)//trong luc gate chua xuat hien
		{
			ProcessDead();
		}
		else//luc gate xuat hien
		{
			if (snake[0].y != gate[0].y)//ran cham tuong nhung khong phai cong khi cong da xuat hien (vi cong duoc mo tren tuong)
			{
				ProcessDead();
			}
		}
	}
	if (snake[0].x + 1 == food[FOOD_IDX].x && snake[0].y == food[FOOD_IDX].y)
	{
		EatFood();
	}
	for (int i = 0; i < SIZE_SPECIAL; i++)
	{
		if (snake[0].x + 1 == special_Food[i].pos.x && snake[0].y == special_Food[i].pos.y)
		{
			SPECIAL_IDX = i;
			 EatSpecialFood();
		}
	}
	for (int i = SIZE_SNAKE; i >= 1; i--)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	if (snake[0].x != X_TABLE_MAX)//neu nhu snake[0] chua vao cong thi moi cap nhat toa do moi
	{
		snake[0].x++;
	}
}
//di chuyen qua trai
void MoveLeft()
{
	if (CheckEatThemselves())
	{
		ProcessDead();
		return;
	}
	if (CheckTouchWallGate() && FOOD == false)
	{
		ProcessDead();
		return;
	}
	if (LEVEL > 1)
	{
		for (int i = 0; i < SIZE_OBSTACLE; i++)
		{
			if (snake[0].x - 1 == obstacle[i].x && snake[0].y == obstacle[i].y)//ran cham chuong ngai vat thi se chet
			{
				ProcessDead();
				break;
			}
		}
	}
	if (snake[0].x - 1 == X_TABLE)
	{
		if (FOOD)
		{
			ProcessDead();
		}
		else
		{
			if (snake[0].y != gate[0].y)
			{
				ProcessDead();
			}
		}
	}
	if (snake[0].x - 1 == food[FOOD_IDX].x && snake[0].y == food[FOOD_IDX].y)
	{
		EatFood();
	}
	for (int i = 0; i < SIZE_SPECIAL; i++)
	{
		if (snake[0].x - 1 == special_Food[i].pos.x && snake[0].y == special_Food[i].pos.y)
		{
			SPECIAL_IDX = i;
			 EatSpecialFood();
		}
	}
	for (int i = SIZE_SNAKE; i >= 1; i--)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	if (snake[0].x != X_TABLE)
	{
		snake[0].x--;//(24/3) sua lai loi ran vao cong sau khi cap nhat lai map
	}
}
//di chuyen len 
void MoveUp()
{
	if (CheckEatThemselves())
	{
		ProcessDead();
		return;
	}
	if (CheckTouchWallGate() && FOOD == false)//neu ran cham tuong cua cong trong luc cong da xuat hien
	{
		ProcessDead();
		return;
	}
	if (LEVEL > 1)
	{
		for (int i = 0; i < SIZE_OBSTACLE; i++)
		{
			if (snake[0].x == obstacle[i].x && snake[0].y - 1 == obstacle[i].y)//neu ran cham chuong ngai vat thi se chet
			{
				ProcessDead();
				break;
			}
		}
	}
	if (snake[0].y - 1 == Y_TABLE)
	{
		if (FOOD)//ran cham tuong luc cong chua xuat hien
		{
			ProcessDead();
		}
		else
		{
			if (snake[0].x != gate[0].x)//ran cham tuong nhung khong phai cong khi cong da xuat hien (vi cong duoc mo tren tuong)
			{
				ProcessDead();
			}
		}
	}
	if (snake[0].y - 1 == food[FOOD_IDX].y && snake[0].x == food[FOOD_IDX].x)
	{
		EatFood();
	}
	for (int i = 0; i < SIZE_SPECIAL; i++)
	{
		if (snake[0].x == special_Food[i].pos.x && snake[0].y - 1 == special_Food[i].pos.y)
		{
			SPECIAL_IDX = i;
			 EatSpecialFood();
		}
	}
	for (int i = SIZE_SNAKE; i >= 1; i--)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	if (snake[0].y != Y_TABLE)//neu snake[0] chua vao cong thi cap nhat toa do moi
	{
		snake[0].y--;//sua lai loi ran vao cong sau khi cap nhat lai map
	}
}
//di chuyen xuong
void MoveDown()
{
	if (CheckEatThemselves())
	{
		ProcessDead();
		return;
	}
	if (CheckTouchWallGate() && FOOD == false)//neu ran cham tuong cua cong trong luc cong da xuat hien
	{
		ProcessDead();
		return;
	}
	if (LEVEL > 1)
	{
		for (int i = 0; i < SIZE_OBSTACLE; i++)
		{
			if (snake[0].x == obstacle[i].x && snake[0].y + 1 == obstacle[i].y)//ran cham chuong ngai vat thi se chet
			{
				ProcessDead();
				break;
			}
		}
	}
	if (snake[0].y + 1 == Y_TABLE_MAX)
	{
		if (FOOD)//ran cham tuong luc cong chua xuat hien
		{
			ProcessDead();
		}
		else
		{
			if (snake[0].x != gate[0].x)//ran cham tuong nhung khong phai cong khi cong da xuat hien (vi cong duoc mo tren tuong)
			{
				ProcessDead();
			}
		}
	}
	if (snake[0].y + 1 == food[FOOD_IDX].y && snake[0].x == food[FOOD_IDX].x)
	{
		EatFood();
	}
	for (int i = 0; i < SIZE_SPECIAL; i++)
	{
		if (snake[0].x == special_Food[i].pos.x && snake[0].y + 1 == special_Food[i].pos.y)
		{
			SPECIAL_IDX = i;
			 EatSpecialFood();
		}
	}
	for (int i = SIZE_SNAKE; i >= 1; i--)
	{
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	if (snake[0].y != Y_TABLE_MAX)//neu snake[0] chua vao cong thi moi cap nhat toa do moi cho ran
	{
		snake[0].y++;
	}
}
void ThreadFunc()
{
	int temp;
	while (!EXIT)
	{
		temp = playerScore;
		if (STATE == 1)
		{
			ClearSnake();
			switch (MOVE)
			{
			case 'A':
			{
				MoveLeft();
				break;
			}
			case 'D':
			{
				MoveRight();
				break;
			}
			case 'W':
			{
				MoveUp();
				break;
			}
			case 'S':
			{
				MoveDown();
				break;
			}
			}
			if (EXIT) break;
			setOutputColor(White, LBlue);
			DrawSnake(mssv, COLOR);
			if (LEVEL == 1 && playerScore % 8 != 0 && snake[SIZE_SNAKE - 1].x == gate[0].x && snake[SIZE_SNAKE - 1].y == gate[0].y)//neu ran da vao cong het thi tang level
			{
				LEVEL++;
				SPEED += 1;
				StartLevel2();
			}
			if (LEVEL == 2 && snake[SIZE_SNAKE - 1].x == gate[0].x && snake[SIZE_SNAKE - 1].y == gate[0].y)
			{
				LEVEL++;
				SPEED += 1;
				StartLevel3();
			}
			if (LEVEL == 3 && snake[SIZE_SNAKE - 1].x == gate[0].x && snake[SIZE_SNAKE - 1].y == gate[0].y)//neu ran da vao cong het thi tang level
			{
				LEVEL++;
				SPEED += 1;
				StartLevel4();
			}
			if (LEVEL == 4 && snake[SIZE_SNAKE - 1].x == gate[0].x && snake[SIZE_SNAKE - 1].y == gate[0].y)//neu ran da vao cong het thi tang level
			{
				STATE = 2;
				bmpWin();
				EXIT = true;
				break;
			}
			if (FOOD == true)//neu food = true thi moi ve food ra
			{
				DrawFood();
			}
			Sleep(270 - 20 * (SPEED - 1));
		}
	}
}

void PlayGame()
{
	int temp;

	thread t1(ThreadFunc);
	HANDLE handle_t1 = t1.native_handle();
	while (1)
	{
		temp = toupper(_getch());
		if (STATE == 1)
		{
			/*if (_kbhit()) {*/
				if (temp == 'P')
				{
					PauseGame(handle_t1);
					int temp = 1;
					while (temp) {
						PausedMenu(PAUSE_STATE);
						int input = _getch();

						// handle the input
						switch (input) {
						case UP:
							PAUSE_STATE--; // move up
							if (PAUSE_STATE < 1) {
								PAUSE_STATE = 3; // wrap around
							}
							break;
						case DOWN:
							PAUSE_STATE++; // move down
							if (PAUSE_STATE > 3) {
								PAUSE_STATE = 1; // wrap around
							}
							break;
						case LEFT:       break;

						case RIGHT:          break;

						case ENTER:
							// execute the current option
							if (PAUSE_STATE == 1) {
								drawScore(Black, LYellow);
								GoToXY(ScoreBarPos);
								DrawScoreBar();
								temp = 0;
								ResumeThread(handle_t1);

								break;
							}

							if (PAUSE_STATE == 2) {
								ResumeThread(handle_t1);
								ExitGame(t1);
								EXIT = false;
								system("cls");
								system("Color F0");
								menuSaveGame();
								PAUSE_STATE = 1;
								return;
							}

							if (PAUSE_STATE == 3) {
								ResumeThread(handle_t1);
								ExitGame(t1);
								EXIT = false;
								system("cls");
								system("Color F0");
								menuFunc();
								PAUSE_STATE = 1;
								return;
							}
						default:
							// do nothing for other keys
							break;
						}
					}
				}
				else if (temp == 'X')
				{
					ExitGame(t1);
					EXIT = false;
					menuFunc();
					return;
				}
				else if ((temp != BLOCKED_CHAR) && (temp == 'D' || temp == 'A' || temp == 'W' || temp == 'S'))
				{
					if (temp == 'D')
					{
						BLOCKED_CHAR = 'A';
					}
					if (temp == 'A')
					{
						BLOCKED_CHAR = 'D';
					}
					if (temp == 'W')
					{
						BLOCKED_CHAR = 'S';
					}
					if (temp == 'S')
					{
						BLOCKED_CHAR = 'W';
					}
					MOVE = temp;
				}
			}
		/*}*/
		else if (STATE == 2)
		{
			ExitGame(t1);
			DeleteObject(win);
			DeleteObject(press);
			menuFunc();
			return;
		}
		else
		{
			//if (temp == 'Y')
			//{
			//	SPEED = 1 * MODE;//cap nhat lai toc do khi reset man choi 
			//	LEVEL = 1;//cap nhat lai lv khi reset man choi
			//	playerScore = 0;//cap nhat lai diem
			//	StartGame();
			//}
			ExitGame(t1);
			DeleteObject(gameover);
			DeleteObject(press);
			DeleteObject(pressB);
			system("cls");
			menuFunc();
			return;
		}
	}
}