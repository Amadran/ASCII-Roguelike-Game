#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <array>

class Level
{
private:
	std::vector<std::string> screen;
	int screen_rows;
	int screen_cols;
	std::array<int, 2> player_pos;
public:
	//constructors
	Level();
	Level(const std::string &filename); //reads in level from file

	//setters (individual elements of screen)
	void setScreenElem(char ch, int x, int y);
	
	//getters
	std::vector<std::string> getScreen() const;
	int getScreenRows() const;
	int getScreenCols() const;
	int getPlayerPosX() const; //want to return player_pos array in one function,
	int getPlayerPosY() const; //currently only have one for each coordinate
	char getScreenElem(int x, int y) const; //returns char at screen[x][y]
	
	//other functions (e.g. screen output)
	void screenOutput() const; //outputs current screen to cout (console)
	//^----- IMPORTANT CHANGE: console output will be a lot faster if
	//I only overwrite changes on the screen, instead of clearing and
	//re-outputting entire screen with marginal changes

	//default screen sizes
	static const int DEFAULT_SCREEN_ROWS;
	static const int DEFAULT_SCREEN_COLS;
};

#endif
