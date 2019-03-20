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

public:
	int success_rate_bulls;
	int success_rate_singles;
	int success_rate_neighbour;

	player(int, string, int, int);
	~player();

	void getID(int i);

	void getName(string n);

	void getBullSuccess(int x);

	void getSingleSuccess(int y);

	int setID();

	string setName();

	int getBullSuccess();

	int getSingleSuccess();

	int getNeighbourRate();
};

