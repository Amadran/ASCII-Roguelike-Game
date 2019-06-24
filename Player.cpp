#include "Player.h"

Player::Player()
{
	hitpoints = 100;
	position[0] = 0;
	position[1] = 0;
}

Player::Player(int hp, int pos[2])
{
	hitpoints = hp;
	position[0] = pos[0];
	position[1] = pos[1];
}

/*
bool Player::playerMove(char moveDir, char** screenArray)
{
	switch (moveDir)
	{
	case 'w':
		break;
	}
}
*/
