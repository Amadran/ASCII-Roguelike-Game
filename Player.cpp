#include <cctype>
#include "Player.h"
#include "Level.h"
#include "global_constants.h"

Player::Player()
{
	hitpoints = 100;
}

Player::Player(int hp)
{
	hitpoints = hp;
}


bool Player::playerMove(Level& gamelevel, char moveDir)
{
	int x = gamelevel.getPlayerPos().x;
	int y = gamelevel.getPlayerPos().y;

	switch (tolower(moveDir))
	{
	case 'w':
		//y-1 not y+1 because rows are read downwards in an array, so vertical is "inverted"
		if (gamelevel.getScreenElem(x, y-1) == BORDER_CHAR)
		{
			return false;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, x, y-1); //move player
			gamelevel.setScreenElem(SPACE_CHAR, x, y); //put space where player was
			return true;
		}
		break;
	case 's':
		if (gamelevel.getScreenElem(x, y+1) == BORDER_CHAR)
		{
			return false;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, x, y+1);
			gamelevel.setScreenElem(SPACE_CHAR, x, y);
			return true;
		}
		break;
	case 'a':
		if (gamelevel.getScreenElem(x-1, y) == BORDER_CHAR)
		{
			return false;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, x-1, y);
			gamelevel.setScreenElem(SPACE_CHAR, x, y);
			return true;
		}
		break;
	case 'd':
		if (gamelevel.getScreenElem(x+1, y) == BORDER_CHAR)
		{
			return false;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, x+1, y);
			gamelevel.setScreenElem(SPACE_CHAR, x, y);
			return true;
		}
		break;
	default:
		return false;
		break;
	}
}


void Player::setHP(int hp)
{
	hitpoints = hp;
}

int Player::getHP() const
{
	return hitpoints;
}

