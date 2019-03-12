#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"

using namespace std;

//int bull (int percent)

int main()
{
	srand(time(0));

	int x = 0;
	int percent = 0;

	int hit = 0;
	int miss = 0;

	player player1(1);
	player player2(2);

	cout << "Welcome to Darts!" << endl;
	cout << "What is player one's name?" << endl;
	string name = player1.getName();
	
	cout << "What is player two's name?" << endl;
	string name = player2.getName();

	cout << "What is your success rate?" << endl;
	cin >> percent;

		while (hit != 10)
		{ 
			int r = rand() % 100;

			if (r <= percent)
			{
			
			hit++;
			}
			else
			{
			
			miss++;
			}
		}

		cout << "It taken you " << hit + miss << " tries to hit the bullseye ten times." << endl;
	
		double average = ((double)hit+miss) /hit;

		cout << "Your average bullseye hits were, "<< average << endl;

	cin >> x;
	return 0;
	
}