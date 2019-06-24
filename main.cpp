#include <iostream>
#include <fstream>
#include <string>
#include "fcr.h" //replaces every oldChar with newChar in level file
#include "Level.h"
#include "Player.h"

//main game functions
void screenOutput(char** screenArray, int rows, int cols); //will eventually deprecate

//diagnostic functions
void arraySet(char** screenArray, int rows, int cols, char character);

/////////////////////////////////////////////////////////////////////

int main()
{
	std::string level_filename = "C:\\Users\\apikor\\Documents\\cpp_projects"
		"\\ascii_roguelike_game\\levels\\level1.txt";
	Level level1(level_filename);

	level1.screenOutput();



	return 0;
}

/////////////////////////////////////////////////////////////////////

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