#include <iostream>
#include "player.h"
using namespace std;

player::player()
{
}


player::~player()
{
}

//setters

void player::setValues1(string PlayerName, int success, int PlayerID )
{
	this->PlayerName1 = PlayerName;
	this->success_rate1 = success;
	this->PlayerID1 = PlayerID;
}

void player::setValues2(string PlayerName, int success, int PlayerID)
{
	this->PlayerName2 = PlayerName;
	this->success_rate2 = success;
	this->PlayerID2 = PlayerID;
}

//getters

string player::getName1()
{
	return PlayerName1;
}

int player::getSuccess1()
{
	return success_rate1;
}

int player::getID1()
{
	return PlayerID1;
}

string player::getName2()
{
	return PlayerName2;
}

int player::getSuccess2()
{
	return success_rate2;
}

int player::getID2()
{
	return PlayerID2;
}


void player::displayMessage()
{
	cout << "This is to show that the classes are working." << endl;
}

//functions

int player::success_rate1 = success_rate1;
int player::PlayerID1 = PlayerID1;
string player::PlayerName1 = PlayerName1;


int player::success_rate2 = success_rate2;
int player::PlayerID2 = PlayerID2;
string player::PlayerName2 = PlayerName2;
