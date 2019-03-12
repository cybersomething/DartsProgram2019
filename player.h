#pragma once
#include <iostream>
#include <string>

using namespace std;

class player
{
private:
	int PlayerID;
	string PlayerName;
	int PlayerAverage;
	int PlayerSuccessRate;

public:
	player(int, string);
	~player();

	void setName(string n);

	string getName();
};

