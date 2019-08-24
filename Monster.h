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
	int monsterAction(Level& gamelevel, Player& player, int index, std::string& message);
	bool monsterAttack(Level& gamelevel, Player& player, std::string& message); //private?
	int processAction(Level& gamelevel, Player& player, int xInc, int yInc,
		int index, std::string& message); //private?

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
