#ifndef MONSTER_H
#define MONSTER_H

#include "Level.h"

class Monster
{
private:
	char monsterType;
	int hitpoints;
public:
	//constructors
	Monster();
	Monster(char type);

	//movement function
	bool monsterAction(Level& gamelevel, int index);

	//setters
	void setType(char type);
	void setHP(int hp);

	//getters
	char getType() const;
	int getHP() const;

	//monster hitpoints constants
	static const int MONSTER_GOBLIN_HP;
	static const int MONSTER_BOSS_HP;
};

#endif
