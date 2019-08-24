#ifndef GLOBAL_CONSTANTS
#define GLOBAL_CONSTANTS

//game entity definitions
enum ENTITY_CHAR : char
{
	BORDER_CHAR = '|',
	SPACE_CHAR = ' ',
	PLAYER_CHAR = '@',
	MONSTER_GOBLIN_CHAR = 'G',
	MONSTER_BOSS_CHAR = 'B'
};

//action codes to be returned by 'playerAction()' and 'monsterAction()'
enum ACTION_CODE : int
{
	ACTIONCODE_NO_ACTION = 100,
	ACTIONCODE_MOVE,
	ACTIONCODE_ATTACK,
	ACTIONCODE_KILL
};

#endif
