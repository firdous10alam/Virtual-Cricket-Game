#include "game.h"

using namespace std;

Game::Game() {

		playersPerTeam = 4;
		maxBalls = 6;
		totalPlayers = 11;

		players[0] = "Virat";
		players[1] = "Rohit";
		players[2] = "Dhawan";
		players[3] = "Pant";
		players[4] = "Karthik";
		players[5] = "KLRahul";
		players[6] = "Jadeja";
		players[7] = "Hardik";
		players[8] = "Bumrah";
		players[9] = "BKumar";
		players[10] = "Ishant";

		isFirstInnings = false;
		teamA.name = "Team-A";
		teamB.name = "Team-B";
}

void Game::welcome() {

		cout << "-----------------------------------------" << endl;
		cout << "|=============== CRIC-IN ===============|" << endl;
		cout << "|				        				 |"	<< endl;
		cout << "|      Welcome to Virtual Cricket Game  |"	<< endl;
		cout << "-----------------------------------------" << endl;

		cout << "--------------------------------------------------" << endl;
		cout << "|================== INSTRUCTIONS ================|" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "| 1. Create 2 teams (Team-A and Team-B with 4    |"<< endl;
		cout << "|    players each) from a given pool 11 players. |" << endl;
		cout << "| 2. Lead the toss and decide the choice of play.|" << endl;
		cout << "| 3. Each innings will be of 6 balls. 	         |" << endl;
		cout << "--------------------------------------------------" << endl;

}

void Game::showAllPlayers() {

	cout << "\nPress Enter to continue ";
	cin.get();

	cout << "-----------------------------------------" << endl;
	cout << "|=========== Pool of Players ===========|" << endl;
	cout << "-----------------------------------------" << endl;

	for(int i = 0; i < totalPlayers; i++) {
		cout << "\t\t" << "[" << i << "]" << players[i] << endl;
	}

}

int Game::takeIntegerInput() {

	int n;

	while (!(cin >> n)) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input! Please try again with valid input: ";
	}

	return n;
}

bool Game::validateSelectedPlayer(int index) {

	int n;
	vector<Player> players;

	players = teamA.players;
	n = players.size();
	for (int i = 0; i < n; i++) {
        if (players.at(i).id == index) {
        	return false;
        }
    }

    players = teamB.players;
    n = players.size();
    for (int i = 0; i < n; i++) {
        if (players.at(i).id == index) {
            return false;
        }
    }

    return true;
}

void Game::selectPlayers() {

	cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|========== Create Team-A and Team-B ==========|" << endl;
	cout << "------------------------------------------------" << endl;

	for (int i = 0; i < playersPerTeam; i++) {

		// Add player to team A
		teamASelection:
			cout << endl << "Select player " << i + 1 << " of Team A - ";
			int playerIndexTeamA = takeIntegerInput();

			if (playerIndexTeamA < 0 || playerIndexTeamA > 10) {
				cout << endl << "Please select from the given players" << endl;
				goto teamASelection;
			} else if (!validateSelectedPlayer(playerIndexTeamA)) {
				cout << endl << "Player has been already selected. Please select other player" << endl;
				goto teamASelection;
			} else {
				Player teamAPlayer;
				teamAPlayer.id = playerIndexTeamA;
				teamAPlayer.name = players[playerIndexTeamA];
				teamA.players.push_back(teamAPlayer);
			}

		// Add player to team B
		teamBSelection:
			cout << endl << "Select player " << i + 1 << " of Team B - ";
			int playerIndexTeamB = takeIntegerInput();

			if (playerIndexTeamB < 0 || playerIndexTeamB > 10) {
				cout << endl << "Please select from the given players" << endl;
				goto teamBSelection;
			} else if (!validateSelectedPlayer(playerIndexTeamB)) {
				cout << endl << "Player has been already selected. Please select other player" << endl;
				goto teamBSelection;
			} else {
				Player teamBPlayer;
				teamBPlayer.id = playerIndexTeamB;
				teamBPlayer.name = players[playerIndexTeamB];
				teamB.players.push_back(teamBPlayer);
			}
	}
}

void Game :: showTeamPlayers() {

	vector<Player> playersA;

	playersA = teamA.players;

	vector<Player> playersB;

	playersB = teamB.players;

	cout << "\n\n--------------------------\t\t--------------------------" << endl;
	cout << "|======== Team-A ========|\t\t|======== Team-B ========|" << endl;
	cout << "--------------------------\t\t--------------------------" << endl;

	for(int i = 0; i < playersPerTeam; i++) {
		cout << "|\t";
		cout << "[" << i << "]" << playersA[i].name << "\t |";
		cout << "\t\t|\t";
		cout << "[" << i << "]" << playersB[i].name << "\t |";
		cout << endl;
	}

}

void Game::toss() {

	cout << "\n--------------------------------" << endl;
	cout << "|========== Let's toss ========|" << endl;
	cout << "--------------------------------" << endl;

	cout << "\nTossing the coin...\n";
	sleep(2);

	int n;
	srand(time(NULL));

	if(rand() % 2 == 0) {
		cout << "\nTeam-A won the toss. \n\nEnter 1 to Bat and 2 to Ball first.\n1. Bat \n2. Bowl " << endl;
		n = takeIntegerInput();

			switch(n) {
				case 1:
					cout << "Team-A won the toss and elected to bat first." << endl;
						battingTeam = &teamA;
						bowlingTeam = &teamB;
					break;
				case 2:
					cout << "Team-A won the toss and elected to bowl first." << endl;
						battingTeam = &teamB;
						bowlingTeam = &teamA;
					break;
				default :
					cout << "Wrong input" << endl;
					toss();
					break;
			}
	} else {
		cout << "\nTeam-B won the toss. \n\nEnter 1 to Bat and 2 to Ball first.\n1. Bat \n2. Bowl ";
		n = takeIntegerInput();

			switch(n) {
				case 1:
					cout << "Team-B won the toss and elected to bat first." << endl;
						battingTeam = &teamB;
						bowlingTeam = &teamA;
					break;
				case 2:
					cout << "Team-B won the toss and elected to bowl first." << endl;
						battingTeam = &teamA;
						bowlingTeam = &teamB;
					break;
				default :
					cout << "Wrong input" << endl;
					toss();
					break;
	}
  }
}

void Game::startFirstInnings() {

	cout << "\n\n\t\t ||| FIRST INNINGS STARTS ||| " << endl << endl;

	isFirstInnings = true;

	initializePlayers();

	playInnings();
}

void Game::initializePlayers() {

	// Choose batsman and bowler: Initialize *batsman and *bowler
	batsman = &battingTeam->players[0];
	bowler = &bowlingTeam->players[0];

	cout << battingTeam->name << " - " << batsman->name << " is batting " << endl;
	cout << bowlingTeam->name << " - " << bowler->name << " is bowling " << endl << endl;

}

void Game::playInnings() {

	for (int i = 0; i < maxBalls; i++) {

		cout << "Press Enter to bowl...";
		cin.get();
		cout << "Bowling..." << endl;
		sleep(1);

		bat();

		if (!validateInningsScore()) {
					break;
				}
	}
}

void Game::bat() {

	srand(time(NULL));
	int runsScored = rand() % 7;

	// Update batting team and batsman score
	batsman->runsScored = batsman->runsScored + runsScored;
	battingTeam->totalRunsScored = battingTeam->totalRunsScored + runsScored;
	batsman->ballsPlayed = batsman->ballsPlayed + 1;

	// Update bowling team and bowler score
	bowler->ballsBowled = bowler->ballsBowled + 1;
	bowlingTeam->totalBallsBowled = bowlingTeam->totalBallsBowled + 1;
	bowler->runsGiven = bowler->runsGiven + runsScored;

    if (runsScored != 0) {	// if runsScored = 1, 2, 3, 4, 5, or 6
    	cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
    	showGameScorecard();
    } else { 	// else runScored = 0 and the batsman is ‘OUT’
    	cout << endl << bowler->name << " to " << batsman->name << " OUT!" << endl << endl;

    	battingTeam->wicketsLost = battingTeam->wicketsLost + 1;
    	bowler->wicketTaken = bowler->wicketTaken + 1;
    	showGameScorecard();

    	int nextPlayerIndex = battingTeam->wicketsLost;
    	batsman = &battingTeam->players[nextPlayerIndex];
    }

}

bool Game::validateInningsScore() {

	if (isFirstInnings) {

		if (battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

			cout << "\t\t ||| FIRST INNINGS ENDS ||| " << endl << endl;

			cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
					<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
					<< ")" << endl;

			cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
					<< " runs to win the match" << endl << endl;

			return false;
		}

	} else {	// Else 2nd innings

		if(battingTeam->totalRunsScored > bowlingTeam->totalRunsScored) {
			cout << battingTeam->name << " Won the match" << endl;
			return false;
		} else if(battingTeam->wicketsLost == playersPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {
			cout << bowlingTeam->name << " Won the match" << endl;
			return false;
		} else if(battingTeam->totalRunsScored == bowlingTeam->totalRunsScored && bowlingTeam->totalBallsBowled == maxBalls) {
			cout << "Match Tied" << endl;
			return false;
		}
	}

	return true;
}

void Game :: showGameScorecard() {

	cout << "\n-----------------------------------------------" << endl;
	cout << "\t" << battingTeam->name << " " << battingTeam->totalRunsScored << "-" <<
	    					battingTeam->wicketsLost << "(" << bowlingTeam->totalBallsBowled << ")"
	    					<< "|" << batsman->name << batsman->runsScored  << "(" << batsman->ballsPlayed << ")"
	    					<< "\t" << bowler->name << bowler->ballsBowled << "-" << bowler->runsGiven << "-" << bowler->wicketTaken  << endl;
	cout << "-------------------------------------------------" << endl;

}

void Game :: secondInnings() {

	sleep(3);
	cout << "\t\t ||| SECOND INNINGS STARTS ||| " << endl << endl;

	isFirstInnings = false;

	Team *ptr;

	ptr = battingTeam;
	battingTeam = bowlingTeam;
	bowlingTeam = ptr;

	initializePlayers();

	playInnings();
}

void Game :: summary() {

	cout << "\n\t\t ||| MATCH ENDS ||| " << endl << endl;


	cout << battingTeam->name << " " << battingTeam->totalRunsScored << " - "
		<< battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled
		<< ")" << endl;

	cout << "|======================================================|" << endl;
	cout << "|PLAYER \t\t BATTING \t\tBOWLING|" << endl;

	for(int i = 0; i < playersPerTeam; i++) {

		batsman = &battingTeam->players[i];
		cout << "|------------------------------------------------------|" << endl;
	    cout << "|";
		cout << "[" << i << "]" << batsman->name << "\t\t " << batsman->runsScored << "(" << batsman->ballsPlayed << ")" << "\t\t\t  "
			 << batsman->ballsBowled << "-" << batsman->runsGiven << "-" << batsman->wicketTaken << "|" <<endl;

	}

	cout << "|======================================================|\n\n" << endl;

	cout << bowlingTeam->name << " " << bowlingTeam->totalRunsScored << " - "
			<< bowlingTeam->wicketsLost << " (" << battingTeam->totalBallsBowled
			<< ")" << endl;

		cout << "|======================================================|" << endl;
		cout << "|PLAYER \t\t BATTING \t\tBOWLING|" << endl;

		for(int i = 0; i < playersPerTeam; i++) {

			batsman = &bowlingTeam->players[i];
			cout << "|------------------------------------------------------|" << endl;
		    cout << "|";
			cout << "[" << i << "]" << batsman->name << "\t\t " << batsman->runsScored << "(" << batsman->ballsPlayed << ")" << "\t\t\t  "
				 << batsman->ballsBowled << "-" << batsman->runsGiven << "-" << batsman->wicketTaken << "|" <<endl;

		}
		cout << "|======================================================|" << endl;
}
