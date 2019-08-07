#include "Level.h"
#include "global_constants.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

//***NOTE: player_pos[0] and player_pos[1] refers to x and y positions,
//respectively, as is normally done; however, the 2d screen array is organized
//in a row-column way, i.e. "y-x", so make sure the correct elements are being
//used and assigned

//default rows and cols sizes
const int Level::DEFAULT_SCREEN_ROWS = 20;
const int Level::DEFAULT_SCREEN_COLS = 50;

//constructors
Level::Level()
{
	player_pos.x = 2; //default player position
	player_pos.y = 2;
	screen.resize(DEFAULT_SCREEN_ROWS, std::string(DEFAULT_SCREEN_COLS, SPACE_CHAR));
	//screen.resize(screen_rows, "");

	for (int i = 0; i < DEFAULT_SCREEN_ROWS; i++)
	{
		//screen.push_back(std::string(screen_cols, SPACE_CHAR));
		//screen[i].reserve(screen_cols);
		for (int j = 0; j < DEFAULT_SCREEN_COLS; j++)
		{
			if (i == 0 || i == DEFAULT_SCREEN_ROWS - 1 || //creates screen border
				j == 0 || j == DEFAULT_SCREEN_COLS - 1)
			{
				screen[i][j] = BORDER_CHAR;
			}
			else if (i == player_pos.y && j == player_pos.x) //places player
			{
				screen[i][j] = PLAYER_CHAR;
			}
		}
	}
}

Level::Level(const std::string &filename)
{
	std::fstream file(filename, std::ios::in);
	std::string line;

	if (file.fail())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	while (getline(file, line))
	{
		screen.push_back(line);
		int x = (screen.end() - 1)->find(PLAYER_CHAR);
		if (x != std::string::npos)
		{
			player_pos.x = x;
			player_pos.y = screen.size() - 1;
		}
	}

	file.close();
}

//setters (individual elements)
void Level::setScreenElem(char ch, int x, int y)
{
	screen[y][x] = ch;

	if (ch == PLAYER_CHAR)
	{
		player_pos.x = x;
		player_pos.y = y;
	}
}

//getters (whole screen)
std::vector<std::string> Level::getScreen() const
{
	return screen;
}

//getters (individual elements and other data)
int Level::getScreenRows() const
{
	return screen.size();
}

int Level::getScreenCols() const
{
	return screen[0].size();
}

Position Level::getPlayerPos() const
{
	return player_pos;
}

char Level::getScreenElem(int x, int y) const
{
	return screen[y][x];
}

void Level::screenOutput() const
{
	for (int i = 0; i < screen.size(); i++)
	{
		std::cout << screen[i] << std::endl;
	}
}