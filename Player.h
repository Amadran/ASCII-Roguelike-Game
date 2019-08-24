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

	//main action function
	int playerAction(Level& gamelevel, std::vector<Monster>& monsters,
		char moveDir, std::string& message);

	//setters
	void setHP(int hp);
	void setDMG(int dmg);

	//getters
	int getHP() const;
	int getDMG() const;

private:
	//function to process combat (to be used inside 'playerAction')
	bool playerAttack(Level& gamelevel, Monster& monster, std::string& message);
	//function to process key presses (to be used inside 'playerAction')
	int processAction(Level& gamelevel, std::vector<Monster>& monsters,
		int xInc, int yInc, std::string& message);
};

#endif