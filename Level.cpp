#include "Level.h"
#include <iostream>
#include <fstream>

//default rows and cols sizes
const int Level::DEFAULT_SCREEN_ROWS = 20;
const int Level::DEFAULT_SCREEN_COLS = 50;

//gameplay elements
const char Level::BORDER_CHAR = '|';
const char Level::SPACE_CHAR = ' ';
const char Level::PLAYER_CHAR = '@';
const char Level::MONSTER_GOBLIN_CHAR = 'G';
const char Level::MONSTER_BOSS_CHAR = 'B';

Level::Level()
{
	screen = nullptr;
	screen_rows = DEFAULT_SCREEN_ROWS;
	screen_cols = DEFAULT_SCREEN_COLS;
	player_pos[0] = 1;
	player_pos[1] = 1;

	screen = new char*[screen_rows];
	for (int i = 0; i < screen_rows; i++)
	{
		screen[i] = new char[screen_cols];
		for (int j = 0; j < screen_cols; j++)
		{
			if (i == 0 || i == screen_rows - 1 ||
				j == 0 || j == screen_cols - 1)
			{
				screen[i][j] = BORDER_CHAR;
			}
			else if (i == player_pos[0] && j == player_pos[1])
			{
				screen[i][j] = PLAYER_CHAR;
			}
			else
			{
				screen[i][j] = SPACE_CHAR;
			}
		}
	}
}
/*
Level::Level(char** screenArray, int rows, int cols)
{
	screen = nullptr;
	screen_rows = rows;
	screen_cols = cols;

	screen = new char*[screen_rows];
	for (int i = 0; i < screen_rows; i++)
	{
		screen[i] = new char[screen_cols];
		for (int j = 0; j < screen_cols; j++)
		{
			screen[i][j] = screenArray[i][j];
		}
	}
}
*/
Level::Level(std::string filename)
{
	std::fstream file(filename, std::ios::in);
	char ch;
	int rowCount = 0;
	int colCount = 0;

	if (file.fail())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	while (file.get(ch))
	{
		if (ch != '\n' && rowCount == 0)
		{
			colCount++;
		}
		else if (ch == '\n')
		{
			rowCount++;
		}
	}

	//increments rowCount once more if last line in file
	//does not end in \n
	if (ch != '\n')
	{
		rowCount++;
	}

	screen = nullptr;
	screen_rows = rowCount;
	screen_cols = colCount;
	screen = new char*[screen_rows];
	for (int i = 0; i < screen_rows; i++)
	{
		screen[i] = new char[screen_cols];
	}

	file.clear(); //MUST CLEAR BEFORE SETTING READ POSITION
	file.seekg(0, std::ios::beg);
	for (int i = 0; i < screen_rows; i++)
	{
		for (int j = 0; j < screen_cols; j++)
		{
			file.get(screen[i][j]);
			if (screen[i][j] == '\n')
			{
				j--; //goes back to this element "next" loop to overwrite \n
			}
			else if (screen[i][j] == PLAYER_CHAR)
			{
				player_pos[0] = i;
				player_pos[1] = j;
			}
		}
	}
	file.close();
}

Level::~Level()
{
	for (int i = 0; i < screen_rows; i++)
	{
		delete[] screen[i];
	}
	delete[] screen;
	screen = nullptr;
}

void Level::setScreen(char** screenArray) //if size of level does not change
{
	for (int i = 0; i < screen_rows; i++)
	{
		for (int j = 0; j < screen_cols; j++)
		{
			screen[i][j] = screenArray[i][j];
		}
	}
}

void Level::setScreen(char** screenArray, int rows, int cols) //if size of level changes
{
	for (int i = 0; i < screen_rows; i++)
	{
		delete[] screen[i];
	}
	delete[] screen;
	screen = nullptr;

	screen_rows = rows;
	screen_cols = cols;

	screen = new char*[screen_rows];
	for (int i = 0; i < screen_rows; i++)
	{
		screen[i] = new char[screen_cols];
		for (int j = 0; j < screen_cols; j++)
		{
			screen[i][j] = screenArray[i][j];
		}
	}
}

void Level::setPlayerPos(int x, int y)
{
	player_pos[0] = x;
	player_pos[1] = y;
}

int Level::getScreenRows() const
{
	return screen_rows;
}

int Level::getScreenCols() const
{
	return screen_cols;
}

int Level::getPlayerPosX() const
{
	return player_pos[0];
}

int Level::getPlayerPosY() const
{
	return player_pos[1];
}

char** Level::getScreen() const
{
	return screen;
}

void Level::screenOutput()
{
	for (int i = 0; i < screen_rows; i++)
	{
		for (int j = 0; j < screen_cols; j++)
		{
			std::cout << screen[i][j];
		}
		std::cout << std::endl;
	}
}

//first determines dimensions of level in 'filename', then reads it into 'screen'
void Level::levelRead(std::string filename)
{
	std::fstream file(filename, std::ios::in);
	char ch;
	int rowCount = 0;
	int colCount = 0;

	if (file.fail())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}
	
	while (file.get(ch))
	{
		if (ch != '\n' && rowCount == 0)
		{
			colCount++;
		}
		else if (ch == '\n')
		{
			rowCount++;
		}
	}

	//increments rowCount once more if last line in file
	//does not end in \n
	if (ch != '\n')
	{
		rowCount++;
	}

	if (screen_rows != rowCount || screen_cols != colCount)
	{
		for (int i = 0; i < screen_rows; i++)
		{
			delete[] screen[i];
		}
		delete[] screen;
		screen = nullptr;

		screen_rows = rowCount;
		screen_cols = colCount;
		screen = new char*[screen_rows];
		for (int i = 0; i < screen_rows; i++)
		{
			screen[i] = new char[screen_cols];
		}
	}

	file.clear(); //MUST CLEAR BEFORE SETTING READ POSITION
	file.seekg(0, std::ios::beg);
	for (int i = 0; i < screen_rows; i++)
	{
		for (int j = 0; j < screen_cols; j++)
		{
			file.get(screen[i][j]);
			if (screen[i][j] == '\n')
			{
				j--; //goes back to this element "next" loop to overwrite \n
			}
		}
	}
	file.close();
}