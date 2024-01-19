// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Snake.h"

int main()
{
    system("color 70");
    firstWord();
    setOutputColor(Black, White);
    fixConsoleWindow(); //fix console to a set size
    setcursor(0, 0); //removed cursor
    MainMenu();
}
