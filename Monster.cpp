#include "Monster.h"
#include "global_constants.h"
#include <cstdlib>
#include <iostream>

const int Monster::MONSTER_GOBLIN_HP = 25;
const int Monster::MONSTER_BOSS_HP = 150;
const int Monster::MONSTER_GOBLIN_DMG = 4;
const int Monster::MONSTER_BOSS_DMG = 15;

Monster::Monster()
{
	monsterType = MONSTER_GOBLIN_CHAR;
	hitpoints = MONSTER_GOBLIN_HP;
	damage = MONSTER_GOBLIN_DMG;
}

Monster::Monster(char type)
{
	monsterType = type;

	switch (type)
	{
		case MONSTER_GOBLIN_CHAR:
			hitpoints = MONSTER_GOBLIN_HP;
			damage = MONSTER_GOBLIN_DMG;
			break;
		case MONSTER_BOSS_CHAR:
			hitpoints = MONSTER_BOSS_HP;
			damage = MONSTER_BOSS_DMG;
			break;
		default:
			std::cerr << "ERROR: invalid monster type." << std::endl;
			std::exit(-1);
			break;
	}
}

bool Monster::monsterAction(Level& gamelevel, int index)
{
	Position pos = gamelevel.getMonsterPos()[index]; //getMonsterPos() returns a vector of Position's of Monster's
	int moveDir;

	moveDir = std::rand() % 5; //0 - 4

	switch (moveDir)
	{
	case 0: //do nothing
		return false;
		break;
	case 1: //up
		if (gamelevel.getScreenElem(pos.x, pos.y-1) == BORDER_CHAR)
		{
			return false;
		}
		else if (gamelevel.getScreenElem(pos.x, pos.y-1) == PLAYER_CHAR ||
				 gamelevel.getScreenElem(pos.x, pos.y-1) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x, pos.y-1) == MONSTER_BOSS_CHAR)
		{
			//some sort of attack function
			return true;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x, pos.y-1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
		}
		break;
	case 2: //down
		if (gamelevel.getScreenElem(pos.x, pos.y+1) == BORDER_CHAR)
		{
			return false;
		}
		else if (gamelevel.getScreenElem(pos.x, pos.y+1) == PLAYER_CHAR ||
				 gamelevel.getScreenElem(pos.x, pos.y+1) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x, pos.y+1) == MONSTER_BOSS_CHAR)
		{
			//some sort of attack function
			return true;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x, pos.y+1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
		}
		break;
	case 3: //left
		if (gamelevel.getScreenElem(pos.x-1, pos.y) == BORDER_CHAR)
		{
			return false;
		}
		else if (gamelevel.getScreenElem(pos.x-1, pos.y) == PLAYER_CHAR ||
				 gamelevel.getScreenElem(pos.x-1, pos.y) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x-1, pos.y) == MONSTER_BOSS_CHAR)
		{
			//some sort of attack function
			return true;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x-1, pos.y);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
		}
		break;
	case 4: //right
		if (gamelevel.getScreenElem(pos.x+1, pos.y) == BORDER_CHAR)
		{
			return false;
		}
		else if (gamelevel.getScreenElem(pos.x+1, pos.y) == PLAYER_CHAR ||
				 gamelevel.getScreenElem(pos.x+1, pos.y) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x+1, pos.y) == MONSTER_BOSS_CHAR)
		{
			//some sort of attack function
			return true;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x+1, pos.y);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
		}
		break;
	}
}

void Monster::setType(char type)
{
	monsterType = type;
}

void Monster::setHP(int hp)
{
	hitpoints = hp;
}

char Monster::getType() const
{
	return monsterType;
}

int Monster::getHP() const
{
	return hitpoints;
}