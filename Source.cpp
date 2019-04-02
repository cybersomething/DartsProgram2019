#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "board.h"
#include "score.h"
#include "game.h"

using namespace std;

int main()
{
	srand(time(0));

	int x = 0;
	int percent = 0;

	int hit = 0;
	int miss = 0;

	string name1;
	string name2;
	int bull_success1;
	int single_success1;
	int double_success1;
	int triple_success1;

	int bull_success2;
	int single_success2;
	int double_success2;
	int triple_success2;

	cout << "Welcome to Darts!" << endl;
	cout << "What is player one's name?" << endl;
	cin >> name1;
	cout << "What is your bullseye success rate?" << endl;
	cin >> bull_success1;
	cout << "What is your singles success rate?" << endl;
	cin >> single_success1;
	cout << "What is your doubles success rate?" << endl;
	cin >> double_success1;
	cout << "What is your triples success_rate?" << endl;
	cin >> triple_success1;

	cout << "***********************************" << endl;

	cout << "What is player two's name?" << endl;
	cin >> name2;
	cout << "What is your bullseye success rate?" << endl;
	cin >> bull_success2;
	cout << "What is your singles success rate?" << endl;
	cin >> single_success2;
	cout << "What is your doubles success rate?" << endl;
	cin >> double_success2;
	cout << "What is your triples success_rate?" << endl;
	cin >> triple_success2;


	player player1(1, name1, bull_success1, single_success1, double_success1, triple_success1);
	player player2(2, name2, bull_success2, single_success2, double_success2, triple_success2);

	game DeciderThrow(int bull_success1, int bull_success2);

	return 0;
}