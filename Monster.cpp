#include "Monster.h"
#include "Player.h"
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

int Monster::monsterAction(Level& gamelevel, Player& player, int index)
{
	Position pos = gamelevel.getMonsterPos(index);
	Position pPos = gamelevel.getPlayerPos();
	bool killFlag;
	int moveDir;

	moveDir = std::rand() % 9; //0 - 8

	switch (moveDir)
	{
	case 0: //do nothing
		return ACTIONCODE_NO_ACTION;
		break;
	case 1: //up
		if (gamelevel.getScreenElem(pos.x, pos.y-1) == BORDER_CHAR ||
			gamelevel.getScreenElem(pos.x, pos.y-1) == MONSTER_GOBLIN_CHAR ||
			gamelevel.getScreenElem(pos.x, pos.y-1) == MONSTER_BOSS_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x, pos.y-1) == PLAYER_CHAR)
		{
			killFlag = monsterAttack(gamelevel, player);

			if (killFlag)
			{
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x, pos.y-1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 2: //down
		if (gamelevel.getScreenElem(pos.x, pos.y+1) == BORDER_CHAR ||
			gamelevel.getScreenElem(pos.x, pos.y+1) == MONSTER_GOBLIN_CHAR ||
			gamelevel.getScreenElem(pos.x, pos.y+1) == MONSTER_BOSS_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x, pos.y+1) == PLAYER_CHAR)
		{
			killFlag = monsterAttack(gamelevel, player);

			if (killFlag)
			{
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x, pos.y+1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 3: //left
		if (gamelevel.getScreenElem(pos.x-1, pos.y) == BORDER_CHAR ||
			gamelevel.getScreenElem(pos.x-1, pos.y) == MONSTER_GOBLIN_CHAR ||
			gamelevel.getScreenElem(pos.x-1, pos.y) == MONSTER_BOSS_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x-1, pos.y) == PLAYER_CHAR)
		{
			killFlag = monsterAttack(gamelevel, player);

			if (killFlag)
			{
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x-1, pos.y);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 4: //right
		if (gamelevel.getScreenElem(pos.x+1, pos.y) == BORDER_CHAR ||
			gamelevel.getScreenElem(pos.x+1, pos.y) == MONSTER_GOBLIN_CHAR ||
			gamelevel.getScreenElem(pos.x+1, pos.y) == MONSTER_BOSS_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x+1, pos.y) == PLAYER_CHAR)
		{
			killFlag = monsterAttack(gamelevel, player);

			if (killFlag)
			{
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x+1, pos.y);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 5: //diagonally up-left
		if (gamelevel.getScreenElem(pos.x-1, pos.y-1) == BORDER_CHAR ||
			gamelevel.getScreenElem(pos.x-1, pos.y-1) == MONSTER_GOBLIN_CHAR ||
			gamelevel.getScreenElem(pos.x-1, pos.y-1) == MONSTER_BOSS_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x-1, pos.y-1) == PLAYER_CHAR)
		{
			killFlag = monsterAttack(gamelevel, player);

			if (killFlag)
			{
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x-1, pos.y-1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 6: //diagonally up-right
		if (gamelevel.getScreenElem(pos.x+1, pos.y-1) == BORDER_CHAR ||
			gamelevel.getScreenElem(pos.x+1, pos.y-1) == MONSTER_GOBLIN_CHAR ||
			gamelevel.getScreenElem(pos.x+1, pos.y-1) == MONSTER_BOSS_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x+1, pos.y-1) == PLAYER_CHAR)
		{
			killFlag = monsterAttack(gamelevel, player);

			if (killFlag)
			{
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x+1, pos.y-1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 7: //diagonally down-left
		if (gamelevel.getScreenElem(pos.x-1, pos.y+1) == BORDER_CHAR ||
			gamelevel.getScreenElem(pos.x-1, pos.y+1) == MONSTER_GOBLIN_CHAR ||
			gamelevel.getScreenElem(pos.x-1, pos.y+1) == MONSTER_BOSS_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x-1, pos.y+1) == PLAYER_CHAR)
		{
			killFlag = monsterAttack(gamelevel, player);

			if (killFlag)
			{
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x-1, pos.y+1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 8: //diagonally down-right
		if (gamelevel.getScreenElem(pos.x+1, pos.y+1) == BORDER_CHAR ||
			gamelevel.getScreenElem(pos.x+1, pos.y+1) == MONSTER_GOBLIN_CHAR ||
			gamelevel.getScreenElem(pos.x+1, pos.y+1) == MONSTER_BOSS_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x+1, pos.y+1) == PLAYER_CHAR)
		{
			killFlag = monsterAttack(gamelevel, player);

			if (killFlag)
			{
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(monsterType, index, pos.x+1, pos.y+1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	}
}

//may add overload for attacking other monsters later
bool Monster::monsterAttack(Level& gamelevel, Player& player)
{
	int newHP = player.getHP() - damage;

	if (newHP > 0)
	{
		player.setHP(newHP);
		std::cout << "You have taken a hit for " << damage << " damage!" << std::endl;
		return false; //false for 'you did not die'
	}
	else
	{
		player.setHP(0); //probably unnecessary
		std::cout << "You have died!" << std::endl;
		return true; //true for 'you did die'
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