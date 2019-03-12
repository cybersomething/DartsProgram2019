#include "player.h"



player::player(int i, string name)
{
	playerID = i;
	playerName = "";
}


player::~player()
{
}

void player::setName(string n)
{
	PlayerName = n;
}

string player::getName()
{
	return PlayerName;
}