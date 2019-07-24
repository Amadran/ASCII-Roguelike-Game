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
	Monster(char type, int hp);

	//movement function
	void monsterMove(Level& gamelevel);

	//setters
	void setType(char type);
	void setHP(int hp);

	//getters
	char getType() const;
	int getHP() const;
};

#endif
