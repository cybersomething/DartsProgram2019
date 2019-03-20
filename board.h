#pragma once
class board
{
public:
	board();
	~board();

	int throw_bull(int bull_success_rate);
	int throw_single(int d);
};

