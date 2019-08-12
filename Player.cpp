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

//not sure why I made it return a bool (made sense when it was only a move function),
//might make it void if I don't have anything to do with the value
//NOTE TO SELF: I feel like there is a more efficient way to organize my code so that in
//the case that there is no monster right next to the character to attack I don't
//needlessly pass in the whole vector of Monster's to this function each time
bool Player::playerAction(Level& gamelevel, std::vector<Monster>& monsters, char moveDir)
{
	Position pos = gamelevel.getPlayerPos();
	Position mPos; //position of monster to be attacked
	bool killFlag;
	int index = 0;

	switch (tolower(moveDir))
	{
	case 'w':
		//y-1 not y+1 because rows are read downwards in an array, so vertical is "inverted"
		if (gamelevel.getScreenElem(pos.x, pos.y-1) == BORDER_CHAR)
		{
			return false;
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

			//for (int i = 0; i < monsters.size(); i++)
			//{
			//	//test monster coordinates with those in Level's 'monster_pos' member
			//	if (gamelevel.getMonsterPos(i).x == mPos.x &&
			//		gamelevel.getMonsterPos(i).y == mPos.y)
			//	{
			//		index = i;
			//		break; //break out of loop since monster has been identified
			//	}
			//}

			killFlag = playerAttack(gamelevel, monsters[index]);

			if (killFlag)
			{
				auto rmIt = monsters.begin() + index;
				monsters.erase(rmIt); //delete Monster from vector
				gamelevel.setScreenElem(SPACE_CHAR, index, mPos.x, mPos.y);
			}
			return true;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x, pos.y-1); //move player
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y); //put space where player was
			return true;
		}
		break;
	case 's':
		if (gamelevel.getScreenElem(pos.x, pos.y+1) == BORDER_CHAR)
		{
			return false;
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

			//for (int i = 0; i < monsters.size(); i++)
			//{
			//	//test monster coordinates with those in Level's 'monster_pos' member
			//	if (gamelevel.getMonsterPos(i).x == mPos.x &&
			//		gamelevel.getMonsterPos(i).y == mPos.y)
			//	{
			//		index = i;
			//		break; //break out of loop since monster has been identified
			//	}
			//}

			killFlag = playerAttack(gamelevel, monsters[index]);

			if (killFlag)
			{
				auto rmIt = monsters.begin() + index;
				monsters.erase(rmIt); //delete Monster from vector
				gamelevel.setScreenElem(SPACE_CHAR, index, mPos.x, mPos.y);
			}
			return true;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x, pos.y+1);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return true;
		}
		break;
	case 'a':
		if (gamelevel.getScreenElem(pos.x-1, pos.y) == BORDER_CHAR)
		{
			return false;
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

			//for (int i = 0; i < monsters.size(); i++)
			//{
			//	//test monster coordinates with those in Level's 'monster_pos' member
			//	if (gamelevel.getMonsterPos(i).x == mPos.x &&
			//		gamelevel.getMonsterPos(i).y == mPos.y)
			//	{
			//		index = i;
			//		break; //break out of loop since monster has been identified
			//	}
			//}

			killFlag = playerAttack(gamelevel, monsters[index]);

			if (killFlag)
			{
				auto rmIt = monsters.begin() + index;
				monsters.erase(rmIt); //delete Monster from vector
				gamelevel.setScreenElem(SPACE_CHAR, index, mPos.x, mPos.y);
			}
			return true;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x-1, pos.y);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return true;
		}
		break;
	case 'd':
		if (gamelevel.getScreenElem(pos.x+1, pos.y) == BORDER_CHAR)
		{
			return false;
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

			//for (int i = 0; i < monsters.size(); i++)
			//{
			//	//test monster coordinates with those in Level's 'monster_pos' member
			//	if (gamelevel.getMonsterPos(i).x == mPos.x &&
			//		gamelevel.getMonsterPos(i).y == mPos.y)
			//	{
			//		index = i;
			//		break; //break out of loop since monster has been identified
			//	}
			//}

			killFlag = playerAttack(gamelevel, monsters[index]);

			if (killFlag)
			{
				auto rmIt = monsters.begin() + index;
				monsters.erase(rmIt); //delete Monster from vector
				gamelevel.setScreenElem(SPACE_CHAR, index, mPos.x, mPos.y);
			}
			return true;
		}
		else
		{
			gamelevel.setScreenElem(PLAYER_CHAR, pos.x+1, pos.y);
			gamelevel.setScreenElem(SPACE_CHAR, pos.x, pos.y);
			return true;
		}
		break;
	default:
		return false;
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

int Player::getHP() const
{
	return hitpoints;
}

