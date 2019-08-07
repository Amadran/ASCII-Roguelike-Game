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
	Level level1(level_filename);
	Player player1;
	char input;

	while (true)
	{
		system("cls");
		level1.screenOutput();
		//std::cout << level1.getPlayerPosX() << " " << level1.getPlayerPosY() << std::endl;
		input = _getch();
		if (tolower(input) == 'q')
		{
			break;
		}
		else
		{
			player1.playerMove(level1, input);
		}
	}

	std::cout << "Thank you for playing!" << std::endl;
	return 0;
}