#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <cctype>
#include <vector>

#include "fcr.h" //replaces every oldChar with newChar in level file
#include "Level.h"
#include "Player.h"
#include "Monster.h"
#include "global_constants.h"

void UI_Output(Level& level, Player& player);
void gameInfoOutput(std::string& msg);

/////////////////////////////////////////////////////////////////////

int main()
{
	std::string level_filename = "C:\\Users\\apikor\\Documents\\cpp_projects"
		"\\ascii_roguelike_game\\levels\\level1.txt";
	Player player1;
	std::vector<Monster> monsterList;
	Level level1(level_filename, monsterList);
	char input;
	std::string playerMessage = "GAME START";
	std::string monsterMessage = "GAME START";
	int state;

	while (true)
	{
		//clear the screen
		std::cout << std::string(level1.getScreenRows()*10, '\n');
		
		//all relevant output to the screen
		UI_Output(level1, player1);
		level1.screenOutput();
		gameInfoOutput(playerMessage);
		gameInfoOutput(monsterMessage);

		//input processing
		input = _getch();
		if (tolower(input) == '-')
		{
			break;
		}
		else
		{
			//call playerAction to process input
			player1.playerAction(level1, monsterList, input, playerMessage);
			
			for (int i = 0; i < monsterList.size(); i++)
			{
				//call monsterAction to determine monster actions
				monsterList[i].monsterAction(level1, player1, i, monsterMessage);
			}
		}
	}

	//game quit message
	std::cout << "Thank you for playing!" << std::endl;
	return 0;
}

//////////////////////////////////////////////////////////////////////

void UI_Output(Level& level, Player& player)
{
	std::string gameInfo;
	Position pPos = level.getPlayerPos();

	gameInfo += " HP: ";
	gameInfo += std::to_string(player.getHP());
	gameInfo += "     Position: (";
	gameInfo += std::to_string(pPos.x);
	gameInfo += ", ";
	gameInfo += std::to_string(pPos.y);
	gameInfo += ")";

	std::cout << gameInfo << std::endl;
}

void gameInfoOutput(std::string& msg)
{
	std::cout << msg << std::endl;
}