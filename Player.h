#ifndef PLAYER_H
#define PLAYER_H

class Player
{
private:
	int hitpoints;
	int position[2];
public:
	Player();
	Player(int hp, int pos[2]);
	//movement
	//bool playerMove(char moveDir, char** screenArray);
};

#endif