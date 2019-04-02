#include <iostream>
#include "game.h"
#include "board.h"

using namespace std;

game::game()
{
}

game::~game()
{
}


int game::DeciderThrow(int bull_success1, int bull_success2)
{
	int first_player = 0;
	int second_player = 0;
	
	cout << bull_success1 << endl;
	cout << bull_success2 << endl;

	board throwBull(int bull_success1);
	board throwBull(int bull_success2);

	return first_player;
	return second_player;
}


