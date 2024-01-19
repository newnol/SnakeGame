
#include "Snake.h"

using namespace std;

void firstWord() {

	setOutputColor(Green, White);
	GoToXY(70 - 45, 0); cout << "~( :)>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
	GoToXY(70 - 45, 1); cout << "  SSSSSSSS   NNN      NN        A       KK    KKK  EEEEEEEEE\n";
	GoToXY(70 - 45, 2); cout << " SS      SS  NN N     NN       A A      KK   KK    EE\n";
	GoToXY(70 - 45, 3); cout << " SS          NN  N    NN      A   A     KK  KK     EE\n";
	GoToXY(70 - 45, 4); cout << "  SSSSSSSS   NN   N   NN     AAAAAAA    KKKKK      EEEEEEEEE\n";
	GoToXY(70 - 45, 5); cout << "         SS  NN    N  NN    AA     AA   KK  KK     EE\n";
	GoToXY(70 - 45, 6); cout << " SS      SS  NN     N NN   A         A  KK   KK    EE\n";
	GoToXY(70 - 45, 7); cout << "  SSSSSSSS   NN      NNN  A           A KK    KKK  EEEEEEEEE\n";
	setOutputColor(Green, White);
	GoToXY(70 - 45, 8); cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<(: )~\n";
	GoToXY(70 - 20, 9);
	Sleep(1000);
	cout << "<= THE_SNAKE = >\n";
	GoToXY(70 - 20, 10);
	Sleep(1000);
	cout << "team's member: \n";
	Sleep(1000);
	GoToXY(70 - 25, 11);
	Sleep(500);
	cout << "Pham Phat Loc     20127213\n";
	GoToXY(70 - 25, 12);
	Sleep(500);
	cout << "Do Xuan An   20127404\n";
	GoToXY(70 - 25, 13);
	Sleep(500);
	cout << "Pham Ngoc Quy        20127474\n";
	GoToXY(70 - 25, 14);
	Sleep(500);
	cout << "Ngo Tan Tai   20127204\n";
	GoToXY(70 - 25, 15);
	system("Pause");
	system("cls");
	setOutputColor(White, White);
}

void printRound(int LEVEL_STATE) {
	setOutputColor(Green, White);
	GoToXY(50, 10);
	cout << "ROUND: " << LEVEL_STATE;
	setOutputColor(White, White);
}

void MainMenu() {
	
    char menu[4][10] = { "New", "Continue", "Setting", "Exit" };
    int current = 0; // the index of the current option
    char input; // the input from the user
    int done = 0; // a flag to indicate whether the user has chosen to exit

    while (!done) {
        // display the menu
		GoToXY(50, 50);
        printf("Menu:\n");
		GoToXY(50, 51);
        printf("----\n");
		GoToXY(50, 52);
        printf("Team member: \n");
        for (int i = 0; i < 4; i++) {
            if (i == current) {
                printf("> %s <\n", menu[i]); // highlight the current option
            }
            else {
                printf("  %s  \n", menu[i]); // display the other options normally
            }
        }

        // read the input from the user
        input = _getch();

        // handle the input
        switch (input) {
        case UP:
            current--; // move up
            if (current < 0) {
                current = 3; // wrap around
            }
            system("cls");
            break;
        case DOWN:
            current++; // move down
            if (current > 3) {
                current = 0; // wrap around
            }
            system("cls");

            break; 
        case LEFT:            system("cls");

        case RIGHT:            system("cls");

            // do nothing for left and right keys
            break;
        case ENTER:
            // execute the current option
            printf("You chose %s\n", menu[current]);
            if (current == 3) {
                done = 1; // exit the loop if the user chose Exit
            }
			if (current == 0) {
				system("cls");
				New();
			}
            break;
        default:
            // do nothing for other keys
            break;
        }
    }
}

void New() {
	char menu[4][10] = { "Easy", "Normal", "Hard", "Back" };
	int current = 0; // the index of the current option
	char input; // the input from the user
	int done = 0; // a flag to indicate whether the user has chosen to exit

    while (!done) {
		// display the menu
		printf("Menu:\n");
		printf("----\n");
		printf("Team member: \n");
        for (int i = 0; i < 4; i++) {
            if (i == current) {
				printf("> %s <\n", menu[i]); // highlight the current option
			}
            else {
				printf("  %s  \n", menu[i]); // display the other options normally
			}
		}

		// read the input from the user
		input = _getch();

		// handle the input
        switch (input) {
		case UP:
			current--; // move up
            if (current < 0) {
				current = 3; // wrap around
			}
			system("cls");
			break;
		case DOWN:
			current++; // move down
            if (current > 3) {
				current = 0; // wrap around
			}
			system("cls");

			break;
		case LEFT:            system("cls");

		case RIGHT:            system("cls");

			// do nothing for left and right keys
			break;
		case ENTER:
			// execute the current option
			printf("You chose %s\n", menu[current]);
            if (current == 3) {
				done = 1; // exit the loop if the user chose Exit
			}
			break;
		default:
			// do nothing for other keys
			break;
		}
	}
}