#include "player.h"
using namespace std;

player::player(int i, string name, int w, int x, int y, int z)
{
	PlayerID = i;
	PlayerName = name;
	success_rate_bulls = w;
	success_rate_singles = x;
	success_rate_doubles = y;
	success_rate_triples = z;
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

void player::getDoubleSuccess(int y)
{
	success_rate_doubles = y;
}

void player::getTripleSuccess(int y)
{
	success_rate_triples = y;
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

int player::setBullSuccess()
{
	return success_rate_bulls;
}

int player::setSingleSuccess()
{
	return success_rate_singles;
}

int player::setDoubleSuccess()
{
	return success_rate_doubles;
}

int player::setTripleSuccess()
{
	return success_rate_triples;
}



//functions
