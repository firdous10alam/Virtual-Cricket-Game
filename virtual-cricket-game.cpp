#include "game.h"

using namespace std;


int main() {

	Game game;
	game.welcome();
	game.showAllPlayers();

	cout << "\nPress enter to continue ";
	cin.get();

	game.selectPlayers();

	game.showTeamPlayers();

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "\n\nPress enter to toss ";
	cin.get();

	game.toss();

	game.startFirstInnings();
	game.secondInnings();
	game.summary();


	return 0;
}
