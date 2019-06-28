#ifndef PLAYER_H
#define PLAYER_H

#include "Level.h"

class Player
{
private:
	int hitpoints;
public:
	//constructors
	Player();
	Player(int hp);

	//movement function
	bool playerMove(Level& gamelevel, char moveDir);

	//setters
	void setHP(int hp);

	//getters
	int getHP() const;
};

#endif