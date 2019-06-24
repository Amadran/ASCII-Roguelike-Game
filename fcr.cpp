#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include "fcr.h"

//fcr = "file character replace"
//functions written to work with std::string's; may want to use char*'s instead

//replaces every occurrence of oldChar in str with newChar
//may want to just use std::string's 'replace' method
void strCharReplace(std::string& str, char oldChar, char newChar)
{
	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		if (str[i] == oldChar)
		{
			str[i] = newChar;
		}
	}
}

//"copydelete" version: creates separate file then overwrites old with new
//NOTE: does not work if 'filename' is a full path because of the '(copy)' added
void fcr_copydelete(std::string& filename, char oldChar, char newChar)
{
	std::fstream file(filename, std::ios::in);
	std::fstream copyfile(filename + "(copy)", std::ios::out);
	std::string line;

	if (file && copyfile)
	{
		while (getline(file, line))
		{
			strCharReplace(line, oldChar, newChar);
			copyfile << line + '\n';
		}

		file.close();
		copyfile.close();

		if (std::remove(filename.c_str()))
		{
			std::cerr << "Error removing original file." << std::endl;
			return;
		}
		else if (std::rename((filename + "(copy)").c_str(), filename.c_str()))
		{
			std::cerr << "Error renaming copy file." << std::endl;
			return;
		}
	}
	else
	{
		std::cerr << "Error opening file." << std::endl;
	}
}

void fcr_memcopy(std::string& filename, char oldChar, char newChar)
{
	std::string fileString, temp;
	std::fstream file(filename, std::ios::in);

	if (!file.fail())
	{
		while (getline(file, temp))
		{
			fileString += (temp + '\n');
		}

		file.close();
		file.open(filename, std::ios::out);

		strCharReplace(fileString, oldChar, newChar);
		file << fileString;
		file.close();
	}
	else
	{
		std::cerr << "Error opening file." << std::endl;
	}
}