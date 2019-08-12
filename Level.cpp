#include "Level.h"
#include "global_constants.h"
#include "Monster.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

//***NOTE: player_pos.x and player_pos.y refers to x and y positions,
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

Level::Level(const std::string &filename, std::vector<Monster> &monsters)
{
	std::fstream file(filename, std::ios::in);
	std::string line;
	bool playerFindFlag = false;
	char ch;
	std::vector<std::string>::iterator endIt;
	Position temp; //temporary Position object

	if (file.fail())
	{
		std::cerr << "Error opening file." << std::endl;
		return;
	}

	while (getline(file, line))
	{
		screen.push_back(line); //enter screen line into vector
		endIt = screen.end() - 1; //for finding entity positions
		temp.y = screen.size() - 1; //temp y-position

		//find player position
		if (!playerFindFlag)
		{
			temp.x = endIt->find(PLAYER_CHAR);
			if (temp.x != std::string::npos)
			{
				playerFindFlag = true;
				player_pos.x = temp.x;
				player_pos.y = temp.y;
			}
		}

		//find monster positions
		for (int i = 0; i < endIt->size(); i++)
		{
			ch = endIt->at(i); //cleaner than (*endIt)[i] or whatever
			if (ch == MONSTER_GOBLIN_CHAR ||
				ch == MONSTER_BOSS_CHAR)
			{
				temp.x = i;
				monster_pos.push_back(temp);
				monsters.push_back(Monster(ch));
			}
		}
	}

	file.close();
}

//setters (individual elements)
//general element overload
void Level::setScreenElem(char ch, int x, int y)
{
	screen[y][x] = ch;

	if (ch == PLAYER_CHAR)
	{
		player_pos.x = x;
		player_pos.y = y;
	}
}

//overload for handling monster objects ('index' is the monster index)
void Level::setScreenElem(char monsterType, int index, int x, int y)
{
	screen[y][x] = monsterType;

	if (monsterType == MONSTER_GOBLIN_CHAR ||
		monsterType == MONSTER_BOSS_CHAR)
	{
		monster_pos[index].x = x;
		monster_pos[index].y = y;
	}
	else //if monster dies (element becomes SPACE_CHAR)
	{
		auto rmIt = monster_pos.begin() + index;
		monster_pos.erase(rmIt);
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

std::vector<Position> Level::getMonsterPos() const
{
	return monster_pos;
}

Position Level::getMonsterPos(int index) const
{
	return monster_pos[index];
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