#include "board.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
using namespace std;

board::board()
{
}


board::~board()
{

}

//This 2d array represents the dart board itself.
int bd[2][21] = { { 0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5 },
{ 0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1 } };

int board::throw_bull(int bull_success_rate)
{
	//  Throw for the bull with percent accuracy (20<p<85)


	int standing_score = 0;

	int random = rand() % 100;

	if (random < (bull_success_rate - 20))
	{
		standing_score = 50;
		return standing_score;
	}
	else if (random < 85)
	{
		standing_score = 25;
		return standing_score;
	}
	else
	{
		standing_score = (1 + rand() % 20);
		return standing_score;
	}
}

int board::throw_single(int d, int bull_success_rate, int single_success_rate)
{

	//  return result of throwing for single d with accuracy of the singles success rate 
		//(or accuracy of the bull success rate for the outer green ring of the bullseye)
		//d is the score that the player is aiming for

	 // Board neighbours ignoring slot zero – this might be better stored in a board class

	int standing_score = 0;

	int r = rand() % 100;

	if (d == 25)
	{	// outer  bull is hit with bull
		if (r < 80)
		{
			standing_score = 25;
			return standing_score;
		} //throw was successful
		else if (r < 90)
		{
			standing_score = 50;
			return standing_score;
		} //red inner bull hit instead
		else
		{

			standing_score = (1 + rand() % 20);
			return standing_score;
		} //return a random score between 1 and 20
	}
	else
	{				// 1 to 20 single
		if (r < 88)
		{
			standing_score = d;
			return standing_score;
		} 
		else if (r < 92)
		{
			return bd[0][d];
		} //return score to the left
		else if (r < 96)
		{
			return bd[1][d];
		} //return score to the right
		else if (r < 98)
		{
			return 3 * d;
		}//return random score?? Improve this?
		else
		{
			return 2 * d;
		} //return random score?? Improve this?
	}
}

int board::throw_double(int d)
{

	//  return result of throwing for double d with accuracy 80%

	// Board neighbours ignoring slot zero

	int r = rand() % 100;

	if (r < 80)
	{
		return 2 * d;
	}
	else if (r < 85)
	{
		return 0;
	}
	else if (r < 90)
	{
		return d;
	}
	else if (r < 93)
	{
		return 2 * bd[0][d];
	}
	else if (r < 96)
	{
		return 2 * bd[1][d];
	}
	else if (r < 98)
	{
		return bd[0][d];
	}
	else
	{
		return bd[1][d];
	}
}

int board::throw_triple(int d, int p)
{
	//  return result of throwing for treble d with accuracy p%  (o<90)

	// Board neighbours ignoring slot zero

	int r = rand() % 100;

	if (r < p)
	{
		return 3 * d;
	} //treble hit
	else if (r < 90)
	{
		return d;
	} //single hit
	else if (r < 93)
	{
		return 3 * bd[0][d];
	} //treble of left hand score hit
	else if (r < 96)
	{
		return 3 * bd[1][d];
	}//treble of right hand score hit

	else if (r < 98)
	{
		return bd[0][d];
	}//single of left hand score hit
	else
	{
		return bd[1][d];
	}//single of left hand score hi
}