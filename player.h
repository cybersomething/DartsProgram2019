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
	int success_rate_doubles;
	int success_rate_triples;

	player(int, string, int, int, int, int);
	~player();

	void getID(int i);

	void getName(string n);

	void getBullSuccess(int w);

	void getSingleSuccess(int x);

	void getDoubleSuccess(int y);

	void getTripleSuccess(int z);

	int setID();

	string setName();

	int setBullSuccess();

	int setSingleSuccess();

	int setDoubleSuccess();

	int setTripleSuccess();
};

