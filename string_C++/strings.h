#ifndef __STRINGS_H

#define __STRINGS_H

/*function desccription is given in string.c file */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string CensorString(string text, string remove_str);
string RotateWord(string s, int index);
void PrintPermutation(string s, int index);

#endif
