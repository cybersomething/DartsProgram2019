#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <string>

#include "game.h"

using namespace std;

game::game()
{
}


game::~game()
{
}

int bd[2][21] = { { 0,20,15,17,18,12,13,19,16,14,6,8,9,4,11,10,7,2,1,3,5 },
{ 0,18,17,19,13,20,10,16,11,12,15,14,5,6,9,2,8,3,4,7,1 } };

int standing_score = 0;

int holding_score1 = 0;
int current_score1 = 501;
int starting_score1 = 501;

int holding_score2 = 0;
int current_score2 = 501;
int starting_score2 = 501;

int success_rate1 = player::success_rate1;
int playerID1 = player::PlayerID1;
string playerName1 = player::PlayerName1;

int success_rate2 = player::success_rate2;
int playerID2 = player::PlayerID2;
string playerName2 = player::PlayerName2;

int game::throw_bull(int success_rate)
{
	//  Throw for the bull with percent accuracy (20<p<85)
	int standing_score = 0;

	int random = rand() % 100;

	if (random < success_rate - 20)
	{
		standing_score = 50;
		cout << "Bullseye hit!" << endl;
		return standing_score;
	}
	else if (random < 85)
	{
		standing_score = 25;
		cout << "Outer Bull hit!" << endl;
		return standing_score;
	}
	else
	{
		standing_score = (1 + rand() % 20);
		cout << "Missed the bullseye, you hit, " << standing_score << endl;
		return standing_score;
	}
}

int game::throw_single(int success_rate,  int d)
{

	//  return result of throwing for single d with accuracy of the singles success rate 
		//(or accuracy of the bull success rate for the outer green ring of the bullseye)
		//d is the score that the player is aiming for

	 // Board neighbours ignoring slot zero – this might be better stored in a board class

	int standing_score = 0;

	int r = rand() % 100;

	if (r < success_rate)
	{
		cout << "You hit your desired number! - " << d << endl;
		standing_score = d;
		return standing_score;
	}
	else if (r < 92)
	{
		standing_score = bd[0][d];
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	} //return score to the left
	else if (r < 96)
	{
		standing_score = bd[1][d];
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	} //return score to the right
	else if (r < 98)
	{
		standing_score = 3 * d;
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}//double hit
	else
	{
		standing_score = 2 * d;
		cout << "You scored - " << standing_score << endl;
	} //triple hit
}


int game::throw_double(int success_rate, int d)
{
	//  return result of throwing for double d with user's entered accuracy 

	int standing_score = 0;

	int r = rand() % 100;

	if (r < success_rate)
	{
		standing_score = 2 * d;
		cout << "You hit your desired number! - " << standing_score << endl;
		return standing_score;
	}
	else if (r < 85)
	{
		standing_score = 0;
		cout << "You missed! - " << endl;
		return standing_score;
	}
	else if (r < 90)
	{
		standing_score = d;
		cout << "You missed, but you hit the single! - " << d << endl;
		return standing_score;
	}
	else if (r < 93)
	{
		standing_score = 2 * bd[0][d];
		cout << "You scored - " << standing_score << endl;

	}
	else if (r < 96)
	{
		standing_score = 2 * bd[1][d];
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}
	else if (r < 98)
	{
		standing_score = bd[0][d];
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}
	else
	{
		standing_score = bd[1][d];
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}
}

int game::throw_triple(int success_rate, int d)
{
	//  return result of throwing for treble d with accuracy stated by user

	int r = rand() % 100;
	int standing_score = 0;

	if (r < success_rate)
	{
		standing_score = 3 * d;
		cout << "You hit your chosen number - " << standing_score << endl;
		return standing_score;
	} //treble hit
	else if (r < 90)
	{
		standing_score = d;
		cout << "You missed, but you hit a single - " << standing_score << endl;
		return standing_score;
	} //single hit
	else if (r < 93)
	{
		standing_score = 3 * bd[0][d];
		cout << "You hit - " << standing_score << endl;
		return standing_score;
	} //treble of left hand score hit
	else if (r < 96)
	{
		standing_score = 3 * bd[1][d];
		cout << "You hit - " << standing_score << endl;
		return standing_score;
	}//treble of right hand score hit
	else if (r < 98)
	{
		standing_score = bd[0][d];
		cout << "You hit - " << standing_score << endl;
		return standing_score;
	}//single of left hand score hit
	else
	{
		standing_score = bd[1][d];
		cout << "You hit - " << standing_score << endl;
		return standing_score;
	}//single of left hand score hit
}

int game::playGame()
{
	int i = 0;

	do {

		for (i = 0; i < 3; i++)
		{
			int d = 0;
			char throw_type = 'A';

			cout << "*****************************************" << endl;
			cout << player::PlayerName1 << ", your current score is, " << current_score1 << endl;
			cout << "What multiplier would you like to aim at? Please enter, B for bullseye, S for single, D for double and T for Triple." << endl;
			cin >> throw_type;
			cout << "*****************************************" << endl;

			switch (throw_type)
			{
			case 'b':
				//Bullseye Function
				if (current_score1 >= 50)
				{
					cout << "Bullseye chosen, " << endl;
					holding_score1 = throw_bull(player::success_rate1);
					cout << "You scored, " << holding_score1 << endl;
					current_score1 = (current_score1 - holding_score1);
				}
				else if (current_score1 < 50)
				{
					cout << "Illegal Throw, try another." << endl;
					i--;
				}
				break;
			case 's':
				cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
				cin >> d;

				//Singles Function
				if (current_score1 >= 2)
				{
					cout << "Single chosen - ";
					holding_score1 = throw_single(player::success_rate1, d);
					if (holding_score1 < current_score1)
					{
						cout << "You scored, " << holding_score1 << endl;
						current_score1 = (current_score1 - holding_score1);
					}
					else 
					{
						cout << "Illegal Throw, try another." << endl;
						i--;
					}
					
				}
				else if (current_score1 < 2)
				{
					cout << "Illegal Throw, try another." << endl;
					i--;
				}
				break;
			case 'd':
				cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
				cin >> d;

				//Doubles Throw
				cout << "Double chosen - ";
				holding_score1 = throw_double(player::success_rate1, d);

				if (holding_score1 < current_score1)
				{
					cout << "You scored, " << holding_score1 << endl;
					current_score1 = (current_score1 - holding_score1);
				}
				else if (holding_score1 > current_score1)
				{
					cout << "Illegal throw, try another." << endl;
					i--;
				}
				break;
			case 't':
				cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
				cin >> d;

				//Triple Throw
				if (current_score1 >= 2)
				{
					cout << "Triple chosen - ";
					holding_score1 = throw_triple(player::success_rate1, d);
					cout << "You scored, " << holding_score1 << endl;
					current_score1 = (current_score1 - holding_score1);
				}
				else if (current_score1 < 2)
				{
					cout << "Illegal Throw, try another." << endl;
					i--;
				}
				break;

				return current_score1;
			}
		}

		cout << "*****************************************" << endl;
		cout << player::PlayerName1 << ", your final score this round is: " << current_score1 << endl;
		cout << "*****************************************" << endl;

		for (i = 0; i < 3; i++)
		{
			int d = 0;
			char throw_type = 'A';

			cout << "*****************************************" << endl;
			cout << player::PlayerName2 << ", your current score is, " << current_score2 << endl;
			cout << "What multiplier would you like to aim at? Please enter, B for bullseye, S for single, D for double and T for Triple." << endl;
			cin >> throw_type;
			cout << "*****************************************" << endl;

			switch (throw_type)
			{
			case 'b':
				//Bullseye Function
				if (current_score2 >= 50)
				{
					cout << "Bullseye chosen, " << endl;
					holding_score2 = throw_bull(player::success_rate2);
					cout << "You scored, " << holding_score2 << endl;
					current_score2 = (current_score2 - holding_score2);
				}
				else if (current_score2 < 50)
				{
					cout << "Illegal Throw, try another." << endl;
					i--;
				}
				break;
			case 's':
				cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
				cin >> d;

				//Singles Fucntion
				if (current_score2 >= 2)
				{
					cout << "Single chosen - ";
					holding_score2 = throw_single(player::success_rate2, d);
					cout << "You scored, " << holding_score2 << endl;
					current_score2 = (current_score2 - holding_score2);
				}
				else if (current_score2 < 2)
				{
					cout << "Illegal Throw, try another." << endl;
					i--;
				}
				break;
			case 'd':
				cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
				cin >> d;

				//Doubles Throw
				cout << "Double chosen - ";
				holding_score2 = throw_double(player::success_rate2, d);

				if (holding_score2 < current_score2)
				{
					cout << "You scored, " << holding_score2 << endl;
					current_score2 = (current_score2 - holding_score2);
				}
				else if (holding_score2 > current_score2)
				{
					cout << "Illegal throw, try another." << endl;
					i--;
				}
				break;
			case 't':
				cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
				cin >> d;

				//Triple Throw
				if (current_score2 >= 2)
				{
					cout << "Triple chosen - ";
					holding_score2 = throw_triple(player::success_rate2, d);
					cout << "You scored, " << holding_score2 << endl;
					current_score2 = (current_score2 - holding_score1);
				}
				else if (current_score2 < 2)
				{
					cout << "Illegal Throw, try another." << endl;
					i--;
				}
				break;

				return current_score2;
			}

		}

		cout << "*****************************************" << endl;
		cout << player::PlayerName2 << ", your final score this round is: " << current_score2 << endl;
		cout << "*****************************************" << endl;

	} while (current_score1 != 0 || current_score2 != 0);
}
