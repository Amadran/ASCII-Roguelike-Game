#ifndef LEVEL_H
#define LEVEL_H

#include <string>

class Level
{
private:
	char** screen;
	int screen_rows;
	int screen_cols;
	int player_pos[2];
public:
	//constructors and destructor
	Level();
	//Level(char** screenArray, int rows, int cols);
	Level(std::string filename); //reads in level from file
	~Level();

	//setters
	void setScreen(char** screenArray); //if size does not change
	void setScreen(char** screenArray, int rows, int cols); //if size changes
	void setPlayerPos(int x, int y);
	
	//getters
	int getScreenRows() const;
	int getScreenCols() const;
	int getPlayerPosX() const; //want to return player_pos array in one function
	int getPlayerPosY() const; //currently only have one for each coordinate
	char** getScreen() const;
	
	//other functions (e.g. screen output)
	void screenOutput(); //outputs current screen to cout (console)
	void levelRead(std::string filename);

	//default screen sizes (publically available)
	static const int DEFAULT_SCREEN_ROWS;
	static const int DEFAULT_SCREEN_COLS;

	//characters that represent gameplay elements
	static const char BORDER_CHAR;
	static const char SPACE_CHAR; //player-walkable area
	static const char PLAYER_CHAR;
	static const char MONSTER_GOBLIN_CHAR;
	static const char MONSTER_BOSS_CHAR;
};

#endif
