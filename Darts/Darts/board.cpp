#include "board.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;



board::board()
{
}


board::~board()
{
}

int board::throw_bull(int percentage) 
{
	//  Throw for the bull with percent accuracy (20<p<85)

	int random = rand() % 100;

	if (random<(percentage - 20))
	{
		return 50;
	}
	else if (random<85)
	{
		return 25;
	}
	else
	{
		return 1 + rand() % 20;
	}
}

int board::throw_single(int d)
{//  return result of throwing for single d with accuracy 88% 
 //(or 80% for the outer green ring of the bullseye)
 //d is the score that the player is aiming for

 // Board neighbours ignoring slot zero – this might be better stored in a board class
	int bd[2][21] = { { 0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5 },
	{ 0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1 } };
	int r = rand() % 100;

	if (d == 25) {	// outer  bull is hit with 80% accuracy
		if (r<80)
		{
			return 25;
		} //throw was successful
		else if (r<90)
		{
			return 50;
		} //red inner bull hit instead
		else
		{
			return 1 + rand() % 20;
		} //return a random score between 1 and 20
	}
	else {			// 1 to 20 single
		if (r<88)
		{
			return d;
		} //return score
		else if (r<92)
		{
			return bd[0][d];
		} //return score to the left
		else if (r<96)
		{
			return bd[1][d];
		} //return score to the right
		else if (r<98)
		{
			return 3 * d;
		}//return random score?? Improve this?
		else
		{
			return 2 * d;
		} //return random score?? Improve this?
	}
}