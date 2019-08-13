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
int Player::playerAction(Level& gamelevel, std::vector<Monster>& monsters, char moveDir)
{
	Position pos = gamelevel.getPlayerPos();
	Position mPos; //position of monster to be attacked
	bool killFlag;
	int index = 0;

	switch (tolower(moveDir))
	{
	case 'w': //up
	case '8':
		if (gamelevel.getScreenElem(pos.x, pos.y-1) == BORDER_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x, pos.y-1) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x, pos.y-1) == MONSTER_BOSS_CHAR)
		{
			mPos.x = pos.x;
			mPos.y = pos.y-1;

			//test monster coordinates with those in Level's 'monster_pos' member
			//NOTE: !(P && Q) <=> !P || !Q -> keep in mind when converting the for loop
			//with internal if statement into overall while loop
			while (gamelevel.getMonsterPos(index).x != mPos.x ||
				   gamelevel.getMonsterPos(index).y != mPos.y)
			{
				index++;
			}

			killFlag = playerAttack(gamelevel, monsters[index]);

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
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x, pos.y-1); //move player
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y); //put space where player was
			return ACTIONCODE_MOVE;
		}
		break;
	case 's': //down
	case '2':
		if (gamelevel.getScreenElem(pos.x, pos.y+1) == BORDER_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x, pos.y+1) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x, pos.y+1) == MONSTER_BOSS_CHAR)
		{
			mPos.x = pos.x;
			mPos.y = pos.y+1;

			//test monster coordinates with those in Level's 'monster_pos' member
			//NOTE: !(P && Q) <=> !P || !Q -> keep in mind when converting the for loop
			//with internal if statement into overall while loop
			while (gamelevel.getMonsterPos(index).x != mPos.x ||
				   gamelevel.getMonsterPos(index).y != mPos.y)
			{
				index++;
			}

			killFlag = playerAttack(gamelevel, monsters[index]);

			if (killFlag)
			{
				auto rmIt = monsters.begin() + index;
				monsters.erase(rmIt); //delete Monster from vector
				gamelevel.setScreenElem(SPACE_CHAR, index, mPos.x, mPos.y);
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x, pos.y+1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 'a': //left
	case '4':
		if (gamelevel.getScreenElem(pos.x-1, pos.y) == BORDER_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x-1, pos.y) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x-1, pos.y) == MONSTER_BOSS_CHAR)
		{
			mPos.x = pos.x-1;
			mPos.y = pos.y;

			//test monster coordinates with those in Level's 'monster_pos' member
			//NOTE: !(P && Q) <=> !P || !Q -> keep in mind when converting the for loop
			//with internal if statement into overall while loop
			while (gamelevel.getMonsterPos(index).x != mPos.x ||
				   gamelevel.getMonsterPos(index).y != mPos.y)
			{
				index++;
			}

			killFlag = playerAttack(gamelevel, monsters[index]);

			if (killFlag)
			{
				auto rmIt = monsters.begin() + index;
				monsters.erase(rmIt); //delete Monster from vector
				gamelevel.setScreenElem(SPACE_CHAR, index, mPos.x, mPos.y);
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x-1, pos.y);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 'd': //right
	case '6':
		if (gamelevel.getScreenElem(pos.x+1, pos.y) == BORDER_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x+1, pos.y) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x+1, pos.y) == MONSTER_BOSS_CHAR)
		{
			mPos.x = pos.x+1;
			mPos.y = pos.y;

			//test monster coordinates with those in Level's 'monster_pos' member
			//NOTE: !(P && Q) <=> !P || !Q -> keep in mind when converting the for loop
			//with internal if statement into overall while loop
			while (gamelevel.getMonsterPos(index).x != mPos.x ||
				   gamelevel.getMonsterPos(index).y != mPos.y)
			{
				index++;
			}

			killFlag = playerAttack(gamelevel, monsters[index]);

			if (killFlag)
			{
				auto rmIt = monsters.begin() + index;
				monsters.erase(rmIt); //delete Monster from vector
				gamelevel.setScreenElem(SPACE_CHAR, index, mPos.x, mPos.y);
				return ACTIONCODE_KILL;
			}
			return ACTIONCODE_ATTACK;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x+1, pos.y);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return ACTIONCODE_MOVE;
		}
		break;
	case 'q': //diagonally up-left
	case '7':
		if (gamelevel.getScreenElem(pos.x-1, pos.y-1) == BORDER_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x-1, pos.y-1) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x-1, pos.y-1) == MONSTER_BOSS_CHAR)
		{
			mPos.x = pos.x-1;
			mPos.y = pos.y-1;

			//test monster coordinates with those in Level's 'monster_pos' member
			//NOTE: !(P && Q) <=> !P || !Q -> keep in mind when converting the for loop
			//with internal if statement into overall while loop
			while (gamelevel.getMonsterPos(index).x != mPos.x ||
				   gamelevel.getMonsterPos(index).y != mPos.y)
			{
				index++;
			}

			killFlag = playerAttack(gamelevel, monsters[index]);

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
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x-1, pos.y-1); //move player
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y); //put space where player was
			return ACTIONCODE_MOVE;
		}
		break;
	case 'e': //diagonally up-right
	case '9':
		if (gamelevel.getScreenElem(pos.x+1, pos.y-1) == BORDER_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x+1, pos.y-1) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x+1, pos.y-1) == MONSTER_BOSS_CHAR)
		{
			mPos.x = pos.x+1;
			mPos.y = pos.y-1;

			//test monster coordinates with those in Level's 'monster_pos' member
			//NOTE: !(P && Q) <=> !P || !Q -> keep in mind when converting the for loop
			//with internal if statement into overall while loop
			while (gamelevel.getMonsterPos(index).x != mPos.x ||
				   gamelevel.getMonsterPos(index).y != mPos.y)
			{
				index++;
			}

			killFlag = playerAttack(gamelevel, monsters[index]);

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
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x+1, pos.y-1); //move player
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y); //put space where player was
			return ACTIONCODE_MOVE;
		}
		break;
	case 'z': //diagonally down-left
	case '1':
		if (gamelevel.getScreenElem(pos.x-1, pos.y+1) == BORDER_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x-1, pos.y+1) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x-1, pos.y+1) == MONSTER_BOSS_CHAR)
		{
			mPos.x = pos.x-1;
			mPos.y = pos.y+1;

			//test monster coordinates with those in Level's 'monster_pos' member
			//NOTE: !(P && Q) <=> !P || !Q -> keep in mind when converting the for loop
			//with internal if statement into overall while loop
			while (gamelevel.getMonsterPos(index).x != mPos.x ||
				   gamelevel.getMonsterPos(index).y != mPos.y)
			{
				index++;
			}

			killFlag = playerAttack(gamelevel, monsters[index]);

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
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x-1, pos.y+1); //move player
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y); //put space where player was
			return ACTIONCODE_MOVE;
		}
		break;
	case 'c': //diagonally down-right
	case '3':
		if (gamelevel.getScreenElem(pos.x+1, pos.y+1) == BORDER_CHAR)
		{
			return ACTIONCODE_NO_ACTION;
		}
		else if (gamelevel.getScreenElem(pos.x+1, pos.y+1) == MONSTER_GOBLIN_CHAR ||
				 gamelevel.getScreenElem(pos.x+1, pos.y+1) == MONSTER_BOSS_CHAR)
		{
			mPos.x = pos.x+1;
			mPos.y = pos.y+1;

			//test monster coordinates with those in Level's 'monster_pos' member
			//NOTE: !(P && Q) <=> !P || !Q -> keep in mind when converting the for loop
			//with internal if statement into overall while loop
			while (gamelevel.getMonsterPos(index).x != mPos.x ||
				   gamelevel.getMonsterPos(index).y != mPos.y)
			{
				index++;
			}

			killFlag = playerAttack(gamelevel, monsters[index]);

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
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x+1, pos.y+1); //move player
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y); //put space where player was
			return ACTIONCODE_MOVE;
		}
		break;
	default:
		return ACTIONCODE_NO_ACTION;
		break;
	}
}

bool Player::playerAttack(Level& gamelevel, Monster& monster)
{
	int newHP = monster.getHP() - damage;
	char type = monster.getType();

	if (newHP > 0)
	{
		monster.setHP(newHP);
		switch (type)
		{
		case MONSTER_GOBLIN_CHAR:
			std::cout << "The goblin has taken a hit for " << damage << " damage!" << std::endl;
			break;
		case MONSTER_BOSS_CHAR:
			std::cout << "The boss has taken a hit for " << damage << " damage!" << std::endl;
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
			std::cout << "The goblin has died!" << std::endl;
			break;
		case MONSTER_BOSS_CHAR:
			std::cout << "The boss has died!" << std::endl;
			break;
		}
		return true; //true for 'it did die'
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

