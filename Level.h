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

	//setters (entire screen at once)
	void setScreen(char** screenArray); //if size does not change
	void setScreen(char** screenArray, int rows, int cols); //if size changes

	//setters (individual elements of screen)
	void setScreenElem(char ch, int x, int y);
	
	//getters
	char** getScreen() const;
	int getScreenRows() const;
	int getScreenCols() const;
	int getPlayerPosX() const; //want to return player_pos array in one function,
	int getPlayerPosY() const; //currently only have one for each coordinate
	char getScreenElem(int x, int y) const; //returns char at screen[x][y]
	
	//other functions (e.g. screen output)
	void screenOutput(); //outputs current screen to cout (console)
	void levelRead(std::string filename);

	//default screen sizes
	static const int DEFAULT_SCREEN_ROWS;
	static const int DEFAULT_SCREEN_COLS;

	//characters that represent game entities
	static const char BORDER_CHAR;
	static const char SPACE_CHAR; //player-walkable area
	static const char PLAYER_CHAR;
	static const char MONSTER_GOBLIN_CHAR;
	static const char MONSTER_BOSS_CHAR;
};

#endif
