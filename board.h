#pragma once
class board
{
public:
	board();
	~board();

	int bd[2][21];

	int standing_score;

	int throw_bull(int bull_success_rate);
	int throw_single(int d, int bull_success_rate, int single_success_rate);
	int throw_double(int d);
	int throw_triple(int d, int p);
};

