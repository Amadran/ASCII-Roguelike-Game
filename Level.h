#ifndef LEVEL_H
#define LEVEL_H

#include <string>

class Level
{
private:
	char** screen;
	int screen_rows;
	int screen_cols;
public:
	//constructors and destructor
	Level();
	Level(char** screenArray, int rows, int cols);
	Level(std::string filename); //reads in level from file
	~Level();

	//setter, getter, and direct screen output methods
	void setScreen(char** screenArray); //if size does not change
	void setScreen(char** screenArray, int rows, int cols); //if size changes
	int getScreenRows() const;
	int getScreenCols() const;
	char** getScreen() const;
	void screenOutput(); //outputs current screen to cout (console)
	void levelRead(std::string filename);

	//default screen sizes (publically available)
	static const int DEFAULT_SCREEN_ROWS;
	static const int DEFAULT_SCREEN_COLS;
};

#endif
