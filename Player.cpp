#include <cctype>
#include "Player.h"

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
	int x = gamelevel.getPlayerPosX();
	int y = gamelevel.getPlayerPosY();

	switch (tolower(moveDir))
	{
	case 'w':
		//y-1 not y+1 because rows are read downwards in an array, so vertical is "inverted"
		if (gamelevel.getScreenElem(x, y-1) == gamelevel.BORDER_CHAR)
		{
			return false;
		}
		else
		{
			gamelevel.setScreenElem(gamelevel.PLAYER_CHAR, x, y-1); //move player
			gamelevel.setScreenElem(gamelevel.SPACE_CHAR, x, y); //put space where player was
			return true;
		}
		break;
	case 's':
		if (gamelevel.getScreenElem(x, y+1) == gamelevel.BORDER_CHAR)
		{
			return false;
		}
		else
		{
			gamelevel.setScreenElem(gamelevel.PLAYER_CHAR, x, y+1);
			gamelevel.setScreenElem(gamelevel.SPACE_CHAR, x, y);
			return true;
		}
		break;
	case 'a':
		if (gamelevel.getScreenElem(x-1, y) == gamelevel.BORDER_CHAR)
		{
			return false;
		}
		else
		{
			gamelevel.setScreenElem(gamelevel.PLAYER_CHAR, x-1, y);
			gamelevel.setScreenElem(gamelevel.SPACE_CHAR, x, y);
			return true;
		}
		break;
	case 'd':
		if (gamelevel.getScreenElem(x+1, y) == gamelevel.BORDER_CHAR)
		{
			return false;
		}
		else
		{
			gamelevel.setScreenElem(gamelevel.PLAYER_CHAR, x+1, y);
			gamelevel.setScreenElem(gamelevel.SPACE_CHAR, x, y);
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

