#include "player.h"
using namespace std;

player::player(int i, string name, int x, int y)
{
	PlayerID = i;
	PlayerName = name;
	success_rate_bulls = x;
	success_rate_singles = y;
}


player::~player()
{
}

//getters

void player::getID(int i)
{
	PlayerID = i;
}

void player::getName(string n)
{
	PlayerName = n;
}

void player::getBullSuccess(int x)
{
	success_rate_bulls = x;
}

void player::getSingleSuccess(int y)
{
	success_rate_singles = y;
}

//setters

int player::setID()
{
	return PlayerID;
}

string player::setName()
{
	return PlayerName;
}

int player::getBullSuccess()
{
	return success_rate_bulls;
}

int player::getSingleSuccess()
{
	return success_rate_singles;
}

int player::getNeighbourRate()
{
	success_rate_neighbour = 100 - success_rate_singles;
	return success_rate_neighbour;
}
//functions
