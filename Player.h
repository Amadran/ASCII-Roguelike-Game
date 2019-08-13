#ifndef PLAYER_H
#define PLAYER_H

#include "Level.h"

class Player
{
private:
	int hitpoints;
	int damage;
public:
	//constructors
	Player();
	Player(int hp, int dmg);

	//movement + other action functions
	int playerAction(Level& gamelevel, std::vector<Monster>& monsters, char moveDir);
	bool playerAttack(Level& gamelevel, Monster& monster); //private?

	//setters
	void setHP(int hp);
	void setDMG(int dmg);

	//getters
	int getHP() const;
	int getDMG() const;
};

#endif