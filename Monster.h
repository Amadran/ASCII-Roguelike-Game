#ifndef MONSTER_H
#define MONSTER_H

#include "Level.h"
#include "Player.h"

class Monster
{
private:
	char monsterType;
	int hitpoints;
	int damage;
public:
	//constructors
	Monster();
	Monster(char type);

	//movement + other action function
	int monsterAction(Level& gamelevel, Player& player, int index);
	bool monsterAttack(Level& gamelevel, Player& player); //private?

	//setters
	void setType(char type);
	void setHP(int hp);

	//getters
	char getType() const;
	int getHP() const;

	//monster constants
	static const int MONSTER_GOBLIN_HP;
	static const int MONSTER_BOSS_HP;
	static const int MONSTER_GOBLIN_DMG;
	static const int MONSTER_BOSS_DMG;
};

#endif
