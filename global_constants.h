#ifndef GLOBAL_CONSTANTS
#define GLOBAL_CONSTANTS

//game entity definitions
const char BORDER_CHAR = '|';
const char SPACE_CHAR = ' ';
const char PLAYER_CHAR = '@';
const char MONSTER_GOBLIN_CHAR = 'G';
const char MONSTER_BOSS_CHAR = 'B';

//action codes to be returned by 'playerAction()' and 'monsterAction()'
const int ACTIONCODE_NO_ACTION = 100;
const int ACTIONCODE_MOVE = 101;
const int ACTIONCODE_ATTACK = 102;
const int ACTIONCODE_KILL = 103;

#endif
