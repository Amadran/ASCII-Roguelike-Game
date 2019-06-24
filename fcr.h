#ifndef FCR_H
#define FCR_H

#include <string>

void strCharReplace(std::string& str, char oldChar, char newChar);
void fcr_copydelete(std::string& filename, char oldChar, char newChar);
void fcr_memcopy(std::string& filename, char oldChar, char newChar);

#endif