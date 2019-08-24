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

int Monster::monsterAction(Level& gamelevel, Player& player, int index, std::string& message)
{
	int moveDir = std::rand() % 9; //0 - 8

	switch (moveDir)
	{
	case 0: //do nothing
		return ACTIONCODE_NO_ACTION;
		break;
	case 1: //up
		return processAction(gamelevel, player, 0, -1, index, message);
		break;
	case 2: //down
		return processAction(gamelevel, player, 0, 1, index, message);
		break;
	case 3: //left
		return processAction(gamelevel, player, -1, 0, index, message);
		break;
	case 4: //right
		return processAction(gamelevel, player, 1, 0, index, message);
		break;
	case 5: //diagonally up-left
		return processAction(gamelevel, player, -1, -1, index, message);
		break;
	case 6: //diagonally up-right
		return processAction(gamelevel, player, 1, -1, index, message);
		break;
	case 7: //diagonally down-left
		return processAction(gamelevel, player, -1, 1, index, message);
		break;
	case 8: //diagonally down-right
		return processAction(gamelevel, player, 1, 1, index, message);
		break;
	}
}

//may add overload for attacking other monsters later
bool Monster::monsterAttack(Level& gamelevel, Player& player, std::string& message)
{
	int newHP = player.getHP() - damage;

	if (newHP > 0)
	{
		player.setHP(newHP);
		message = "You took ";
		message += std::to_string(damage);
		message += " damage!";
		return false; //false for 'you did not die'
	}
	else
	{
		player.setHP(0); //probably unnecessary
		message = "You have died!";
		return true; //true for 'you did die'
	}
}

int Monster::processAction(Level& gamelevel, Player& player, int xInc, int yInc,
	int index, std::string& message)
{
	Position pos = gamelevel.getMonsterPos(index);
	Position pPos = gamelevel.getPlayerPos();
	bool killFlag;

	if (gamelevel.getScreenElem(pos.x + xInc, pos.y + yInc) == BORDER_CHAR ||
		gamelevel.getScreenElem(pos.x + xInc, pos.y + yInc) == MONSTER_GOBLIN_CHAR ||
		gamelevel.getScreenElem(pos.x + xInc, pos.y + yInc) == MONSTER_BOSS_CHAR)
	{
		return ACTIONCODE_NO_ACTION;
	}
	else if (gamelevel.getScreenElem(pos.x + xInc, pos.y + yInc) == PLAYER_CHAR)
	{
		killFlag = monsterAttack(gamelevel, player, message);

		if (killFlag)
		{
			return ACTIONCODE_KILL;
		}
		return ACTIONCODE_ATTACK;
	}
	else
	{
		gamelevel.setScreenElem(monsterType, index, pos.x + xInc, pos.y + yInc);
		gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
		return ACTIONCODE_MOVE;
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