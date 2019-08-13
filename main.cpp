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

/////////////////////////////////////////////////////////////////////

int main()
{
	std::string level_filename = "C:\\Users\\apikor\\Documents\\cpp_projects"
		"\\ascii_roguelike_game\\levels\\level1.txt";
	Player player1;
	std::vector<Monster> monsterList;
	Level level1(level_filename, monsterList);
	char input;

	while (true)
	{
		std::cout << std::string(level1.getScreenRows()*10, '\n');
		level1.screenOutput();
		//std::cout << level1.getPlayerPosX() << " " << level1.getPlayerPosY() << std::endl;
		input = _getch();
		if (tolower(input) == '-')
		{
			break;
		}
		else
		{
			//for (int i = 0; i < monsterList.size(); i++)
			//{
			//	std::cout << monsterList[i].getType() << std::endl;
			//}

			player1.playerAction(level1, monsterList, input);
			
			for (int i = 0; i < monsterList.size(); i++)
			{
				monsterList[i].monsterAction(level1, player1, i);
			}
		}
	}

	std::cout << "Thank you for playing!" << std::endl;
	return 0;
}