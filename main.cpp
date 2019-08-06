#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <cctype>
#include "fcr.h" //replaces every oldChar with newChar in level file
#include "Level.h"
#include "Player.h"

/*
//main game functions
void screenOutput(char** screenArray, int rows, int cols); //will eventually deprecate

//diagnostic functions
void arraySet(char** screenArray, int rows, int cols, char character);

/////////////////////////////////////////////////////////////////////
*/
int main()
{
	std::string level_filename = "C:\\Users\\apikor\\Documents\\cpp_projects"
		"\\ascii_roguelike_game\\levels\\level1.txt";
	Level level1 (level_filename);
	Player player1;
	char ch;

	while (true)
	{
		system("cls");
		level1.screenOutput();
		//std::cout << level1.getPlayerPosX() << " " << level1.getPlayerPosY() << std::endl;
		ch = _getch();
		if (tolower(ch) == 'q')
		{
			break;
		}
		else
		{
			player1.playerMove(level1, ch);
		}
	}
	
	//fcr_copydelete(level_filename, '.', ' ');

	std::cout << "Thank you for playing!" << std::endl;
	return 0;
}

/////////////////////////////////////////////////////////////////////
/*
//main game functions
void screenOutput(char** screenArray, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << " " << screenArray[i][j];
		}
		//std::cout << std::endl; //somehow not needed when screenArray read in from file
	}
}

//diagnostic functions
void arraySet(char** screenArray, int rows, int cols, char character)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			screenArray[i][j] = character;
		}
	}
}
*/