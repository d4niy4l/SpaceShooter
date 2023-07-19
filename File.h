#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class File
{
	int index;
	int max;
	string names[3];
	int scores[3];
public:
	File();
	void readFile();
	void writeFile(int score, string name);
	void sortFile();
	int returnLowestScore();
};

