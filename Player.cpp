#include <cctype>
#include <iostream>
#include "Player.h"
#include "Level.h"
#include "Monster.h"
#include "global_constants.h"

Player::Player()
{
	hitpoints = 100;
	damage = 20;
}

Player::Player(int hp, int dmg)
{
	hitpoints = hp;
	damage = dmg;
}

//NOTE TO SELF: I feel like there is a more efficient way to organize my code so that in
//the case that there is no monster right next to the character to attack I don't
//needlessly pass in the whole vector of Monster's to this function each time
int Player::playerAction(Level& gamelevel, std::vector<Monster>& monsters,
	char moveDir, std::string& message)
{
	switch (tolower(moveDir))
	{
	case 'w': //up
	case '8':
		return processAction(gamelevel, monsters, 0, -1, message);
		break;
	case 's': //down
	case '2':
		return processAction(gamelevel, monsters, 0, 1, message);
		break;
	case 'a': //left
	case '4':
		return processAction(gamelevel, monsters, -1, 0, message);
		break;
	case 'd': //right
	case '6':
		return processAction(gamelevel, monsters, 1, 0, message);
		break;
	case 'q': //diagonally up-left
	case '7':
		return processAction(gamelevel, monsters, -1, -1, message);
		break;
	case 'e': //diagonally up-right
	case '9':
		return processAction(gamelevel, monsters, 1, -1, message);
		break;
	case 'z': //diagonally down-left
	case '1':
		return processAction(gamelevel, monsters, -1, 1, message);
		break;
	case 'c': //diagonally down-right
	case '3':
		return processAction(gamelevel, monsters, 1, 1, message);
		break;
	default:
		return ACTIONCODE_NO_ACTION;
		break;
	}
}

bool Player::playerAttack(Level& gamelevel, Monster& monster, std::string& message)
{
	int newHP = monster.getHP() - damage;
	char type = monster.getType();

	if (newHP > 0)
	{
		monster.setHP(newHP);
		switch (type)
		{
		case MONSTER_GOBLIN_CHAR:
			message = "The goblin took ";
			message += std::to_string(damage);
			message += " damage!";
			break;
		case MONSTER_BOSS_CHAR:
			message = "The boss took ";
			message += std::to_string(damage);
			message += " damage!";
			break;
		}
		return false; //false for 'it did not die'
	}
	else
	{
		monster.setHP(0); //probably unnecessary since the Monster will be deleted
		switch (type)
		{
		case MONSTER_GOBLIN_CHAR:
			message = "The goblin has died!";
			break;
		case MONSTER_BOSS_CHAR:
			message = "The boss has died!";
			break;
		}
		return true; //true for 'it did die'
	}
}

//xInc and yInc are the increments from the player's position to test
int Player::processAction(Level& gamelevel, std::vector<Monster>& monsters,
	int xInc, int yInc, std::string& message)
{
	Position pos = gamelevel.getPlayerPos();
	Position mPos; //position of monster to be attacked
	bool killFlag;
	int index = 0;

	if (gamelevel.getScreenElem(pos.x + xInc, pos.y + yInc) == BORDER_CHAR)
	{
		return ACTIONCODE_NO_ACTION;
	}
	else if (gamelevel.getScreenElem(pos.x + xInc, pos.y + yInc) == MONSTER_GOBLIN_CHAR ||
		gamelevel.getScreenElem(pos.x + xInc, pos.y + yInc) == MONSTER_BOSS_CHAR)
	{
		mPos.x = pos.x + xInc;
		mPos.y = pos.y + yInc;

		//test monster coordinates with those in Level's 'monster_pos' member
		//NOTE: !(P && Q) <=> !P || !Q -> keep in mind when converting the for loop
		//with internal if statement into overall while loop
		while (gamelevel.getMonsterPos(index).x != mPos.x ||
			gamelevel.getMonsterPos(index).y != mPos.y)
		{
			index++;
		}

		killFlag = playerAttack(gamelevel, monsters[index], message);

		if (killFlag)
		{
			auto rmIt = monsters.begin() + index;
			monsters.erase(rmIt); //delete Monster from vector
			gamelevel.setScreenElem(SPACE_CHAR, index, mPos.x, mPos.y);
			return ACTIONCODE_KILL;
		}
		else
		{
			return ACTIONCODE_ATTACK;
		}
	}
	else
	{
		gamelevel.setScreenElem(PLAYER_CHAR, pos.x + xInc, pos.y + yInc); //move player
		gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y); //put space where player was
		return ACTIONCODE_MOVE;
	}
}

void Player::setHP(int hp)
{
	hitpoints = hp;
}

void Player::setDMG(int dmg)
{
	damage = dmg;
}

int Player::getHP() const
{
	return hitpoints;
}

int Player::getDMG() const
{
	return damage;
}

