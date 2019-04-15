#include <cstdlib> //used for the random number generator
#include <iostream> //allows cin and cout to be used 
#include <string> //allows string to be used as a data type

#include "game.h" //includes the game class header

using namespace std;

game::game() //constructor left deliberately empty
{
}


game::~game()//constructor left deliberately empty
{
}

//this function assigns data to the variables needed for the game.
void game::init(player* p1, player* p2) //pointer variables passed in 
{
	standing_score = 0; //this variable holds the score achieved in the throw functions

	holding_score = 0; //this variable holds the score achieved in the throw functions, within the playGame() function

	player1 = p1; //player1 is now equal to the pointer variable
	player2 = p2; //player2 is now equal to the pointer variable

	random = 0;
}

//this function is used to simulate the user aiming and throwing at the bull on the board
int game::throw_bull(int success_rate) //success rate passsed in to the function
{
	standing_score = 0; //this variable sets standing_score to 0, as this variable holds the score achieved in this throw

	random = rand() % 100; //sets random variable to a random number between 0 and 99

	if (random < success_rate - 20) //if the random number generated is less than the success_rate-20, the bullseye will be hit.
	{
		standing_score = 50;
		cout << "Bullseye hit!" << endl;
		return standing_score;
	}
	else if (random < 85) //if the random number generated is less than 85, the outer bull will be hit.
	{
		standing_score = 25;
		cout << "Outer Bull hit!" << endl;
		return standing_score;
	}
	else
	{
		standing_score = (1 + rand() % 20); //if the bull or the outer bull are not hit, the bullseye will not be hit and the standing score will be set to a single on the board
		cout << "Missed the bullseye, you hit, " << standing_score << endl;
		return standing_score;
	}
}

//this function is used to simulate the user aiming and throwing at a single on the board.
int game::throw_single(int success_rate,  int d) //success rate and number to be aimed at passed in to the function
{
	standing_score = 0; //this variable sets standing_score to 0, as this variable holds the score achieved in this throw

	random = rand() % 100; //sets random variable to a random number between 0 and 99

	if (random < success_rate)
	{
		cout << "You hit your desired number! - " << d << endl;
		standing_score = d;
		return standing_score;
	}
	else if (random < 92)
	{
		standing_score = bd[0][d];
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	} //return score to the left
	else if (random < 96)
	{
		standing_score = bd[1][d];
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	} //return score to the right
	else if (random < 98)
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

	standing_score = 0; //this variable sets standing_score to 0, as this variable holds the score achieved in this throw

	random = rand() % 100; //sets random variable to a random number between 0 and 99

	if (random < success_rate)
	{
		standing_score = 2 * d;
		cout << "You hit your desired number! - " << standing_score << endl;
		return standing_score;
	}
	else if (random < 85)
	{
		standing_score = 0;
		cout << "You missed! - " << endl;
		return standing_score;
	}
	else if (random < 90)
	{
		standing_score = d;
		cout << "You missed, but you hit the single! - " << d << endl;
		return standing_score;
	}
	else if (random < 93)
	{
		standing_score = 2 * bd[0][d];
		cout << "You scored - " << standing_score << endl;

	}
	else if (random < 96)
	{
		standing_score = 2 * bd[1][d];
		cout << "You scored - " << standing_score << endl;
		return standing_score;
	}
	else if (random < 98)
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

	standing_score = 0; //this variable sets standing_score to 0, as this variable holds the score achieved in this throw

	random = rand() % 100; //sets random variable to a random number between 0 and 99

	if (random < success_rate)
	{
		standing_score = 3 * d;
		cout << "You hit your chosen number - " << standing_score << endl;
		return standing_score;
	} //treble hit
	else if (random < 90)
	{
		standing_score = d;
		cout << "You missed, but you hit a single - " << standing_score << endl;
		return standing_score;
	} //single hit
	else if (random < 93)
	{
		standing_score = 3 * bd[0][d];
		cout << "You missed, but you hit a treble- " << standing_score << endl;
		return standing_score;
	} //treble of left hand score hit
	else if (random < 96)
	{
		standing_score = 3 * bd[1][d];
		cout << "You missed, but you hit a treble - " << standing_score << endl;
		return standing_score;
	}//treble of right hand score hit
	else if (random < 98)
	{
		standing_score = bd[0][d];
		cout << "You missed, but you hit a single - " << standing_score << endl;
		return standing_score;
	}//single of left hand score hit
	else
	{
		standing_score = bd[1][d];
		cout << "You missed, but you hit a single - " << standing_score << endl;
		return standing_score;
	}//single of left hand score hit
}

int game::takeTurn(player* player, int &i)
{
	int d = 0;
	char throw_type = 'A';

	cout << "*****************************************" << endl;
	cout << player->getName() << ", your current score is, " << player->getCurrentScore() << endl;
	cout << "What multiplier would you like to aim at? Please enter, B for bullseye, S for single, D for double and T for Triple." << endl;
	cin >> throw_type;
	cout << "*****************************************" << endl;

	switch (throw_type)
	{
	case 'b':
		//Bullseye Function
		if (player->getCurrentScore() >= 50)
		{
			cout << "Bullseye chosen, " << endl;
			holding_score = throw_bull(player->getSuccess());
			cout << "You scored, " << holding_score << endl;
			player->setCurrentScore(player->getCurrentScore(), holding_score);
		}
		else if (player->getCurrentScore() < 50)
		{
			cout << "Illegal Throw, try another." << endl;
			i--;
		}
		break;
	case 's':
		cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
		cin >> d;

		//Singles Function
		if (player->getCurrentScore() >= 2)
		{
			cout << "Single chosen - ";
			holding_score = throw_single(player->getSuccess(), d);
			if (holding_score < player->getCurrentScore())
			{
				cout << "You scored, " << holding_score << endl;
				player->setCurrentScore(player->getCurrentScore(), holding_score);
			}
			else
			{
				cout << "Illegal Throw, try another." << endl;
				i--;
			}

		}
		else if (player->getCurrentScore() < 2)
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
		holding_score = throw_double(player->getSuccess(), d);

		if (holding_score < player->getCurrentScore())
		{
			cout << "You scored, " << holding_score << endl;
			player->setCurrentScore(player->getCurrentScore(), holding_score);
		}
		else if (holding_score > player->getCurrentScore())
		{
			cout << "Illegal throw, try another." << endl;
			i--;
		}
		else if (holding_score = player->getCurrentScore())
		{
			player->setCurrentScore(player->getCurrentScore(), holding_score);
			dartsWinner(player->getName());
		}
		break;
	case 't':
		cout << "What number would you like to aim at? Please enter a number between 1 to 20." << endl;
		cin >> d;

		//Triple Throw
		if (player->getCurrentScore() >= 6)
		{
			cout << "Triple chosen - ";
			holding_score = throw_triple(player->getSuccess(), d);

			if (holding_score > player->getCurrentScore())
			{
				cout << "Illegal Throw, try another." << endl;
				i--;
			}
			else
			{
				cout << "You scored, " << holding_score << endl;
				player->setCurrentScore(player->getCurrentScore(), holding_score);
			}
		}
		else if (player->getCurrentScore() < 5)
		{
			cout << "Illegal Throw, try another." << endl;
			i--;
		}
		break;

		return player->getCurrentScore();
	}
}

void game::playGame()
{
	int i = 0;
	bool loop = true;

	while (loop)
	{


		for (i = 0; i < 3; i++)
		{
			if (player1->getCurrentScore() == 0)
			{
				loop = false;
				break;
			}
			else if(player2->getCurrentScore() == 0)
			{
				loop = false;
				break;
			}

			takeTurn(player1, i);
		}

		cout << "*****************************************" << endl;
		cout << player1->getName() << ", your final score this round is: " << player1->getCurrentScore() << endl;
		cout << "*****************************************" << endl;

		for (i = 0; i < 3; i++)
		{
			if (player1->getCurrentScore() == 0)
			{
				loop = false;
				break;
			}
			else if (player2->getCurrentScore() == 0)
			{
				loop = false;
				break;
			}
			
			takeTurn(player2, i);
			
		}

		cout << "*****************************************" << endl;
		cout << player2->getName() << ", your final score this round is: " << player2->getCurrentScore() << endl;
		cout << "*****************************************" << endl;
	}

	if (player1->getCurrentScore() == 0)
	{
		dartsWinner(player1->getName());
	}
	else if (player2->getCurrentScore() == 0)
	{
		dartsWinner(player2->getName());
	}
}

int game::dartsWinner(string name)
{
	cout << "Congratulations, " << name << ", you have won this game!" << endl;

	return 0;
}
