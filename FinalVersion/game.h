#pragma once
#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class game
{
public:
	game();
	~game();

	int bd[2][21];

	int success_rate;

	int playerID;

	int standing_score;

	int current_score;

	int holding_score;

	int starting_score;

	int playGame();

	int throw_bull(int success_rate);
	int throw_single(int success_rate, int d);
	int throw_double(int success_rate, int d);
	int throw_triple(int success_rate, int d);
};
