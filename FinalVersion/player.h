#pragma once

#include <iostream>
#include <string>

using namespace std;

class player
{
public:
	static string PlayerName1; //public only so game can access this variable.

	static int success_rate1;

	static int PlayerID1;

	static string PlayerName2; //public only so game can access this variable.

	static int success_rate2;

	static int PlayerID2;

	player();
	~player();

	void setValues1(string PlayerName, int success, int PlayerID);

	void setValues2(string PlayerName, int success, int PlayerID);

	string getName1();

	int getSuccess1();

	int getID1();

	string getName2();

	int getSuccess2();

	int getID2();

	void displayMessage();
};
