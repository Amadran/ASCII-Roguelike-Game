#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <vector>
#include <array>

struct Position
{
	int x;
	int y;
};

class Level
{
private:
	std::vector<std::string> screen;
	Position player_pos;
public:
	//constructors
	Level();
	Level(const std::string &filename); //reads in level from file

	//setters (individual elements of screen)
	void setScreenElem(char ch, int x, int y);
	
	//getters (screen)
	int getScreenRows() const;
	int getScreenCols() const;
	std::vector<std::string> getScreen() const;

	//getters (game info)
	Position getPlayerPos() const;
	char getScreenElem(int x, int y) const; //returns char at screen[y][x]
	
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
