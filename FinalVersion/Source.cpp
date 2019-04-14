#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include "player.h"
#include "game.h"
using namespace std;

int main()
{
	string name1;
	string name2;

	int playeroneID = 0;
	int playertwoID = 1;

	int coin = 0;

	int success_rate1 = 0;
	int success_rate2 = 0;

	cout << "Hello, welcome to 501!" << endl;
	cout << "What is the first player's name?" << endl;
	cin >> name1;
	cout << "************************************" << endl;
	cout << name1 << ", what is your success rate?" << endl;
	cin >> success_rate1;
	cout << "************************************" << endl;
	cout << "What is the second player's name?" << endl;
	cin >> name2;
	cout << "************************************" << endl;
	cout << name2 << ", what is your success rate?" << endl;
	cin >> success_rate2;
	cout << "************************************" << endl;
	cout << "Your starting score is 501, in order to win, you need to reach 0 and have your last dart finish on the bullseye or a double." << endl;
	cout << "Each player will have three darts. Once these darts have been thrown, it is the next player's turn and so on until someone wins." << endl;
	cout << name1 << ", you will start first." << endl;

	player playerone;
	player playertwo;
	
	playerone.setValues1(name1, success_rate1, playeroneID);
	playertwo.setValues2(name2, success_rate2, playertwoID);

	game NewGame;

	NewGame.playGame();

	return 0;
}
