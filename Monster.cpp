#include "Monster.h"
#include "global_constants.h"

Monster::Monster()
{
	monsterType = MONSTER_GOBLIN_CHAR;
	hitpoints = 25;
}

Monster::Monster(char type, int hp)
{
	monsterType = type;
	hitpoints = hp;
}

void Monster::monsterMove(Level& gamelevel)
{

}

void Monster::setType(char type)
{
	monsterType = type;
}

void Monster::setHP(int hp)
{
	hitpoints = hp;
}

char Monster::getType() const
{
	return monsterType;
}

int Monster::getHP() const
{
	return hitpoints;
}