#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#define NUM_DICE 6
#define DICE_VALUES 7

using namespace std;

int player_count();
bool is_int (string num);
int get_int(string prompt);
void begin_game(int totalPlayers);
void pop_arr(int* arr, int length);
void print_arr(int* arr, int length);
void print_scoreboard(int* arr, int length); 
int roll(int totalPlayers, int currentPlayer, int* scoreboard);
bool farkle(int* dice, int numDiceToRoll); 
void get_diceValueAmnts(int* diceValueAmnts, int* dice, int length);
int kind_counter(int* diceValueAmnts, int kind);
bool straight(int* diceValueAmnts);
bool roll_again(int totalPlayers, int currentPlayer, int runningScore, int* scoreboard, int numDiceToRoll);
int diceKeep(int* dice, int* numDiceToRoll);
int updateRunningScore(int* dice, int numDiceToRoll);
int triplet_type(int* diceValueAmnts);
bool win_reached(int* scoreboard, int totalPlayers);
void winner(int* scoreboard, int totalPlayers);
bool duplicate(int* specDiceKept, int numDiceKept, int dieKept);

/******************************************************************************
 ** Function: main
 ** Description: Where the program starts
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int main() {
	int totalPlayers;

	totalPlayers = player_count();
	
	begin_game(totalPlayers);
}

/******************************************************************************
 ** Function: player_count
 ** Description: Prompts the user to enter how many players there are
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int player_count() {
	string totalPlayers;
	do {
		
		cout << "How many players are there? ";
		getline(cin, totalPlayers);
		cout << endl;		

		//2 Players must be playing, and a number must be entered
		if (get_int(totalPlayers) < 2 || !is_int(totalPlayers)) {
			cout << "Please enter 2 or more" << endl;
		}
	} while (get_int(totalPlayers) < 2 || !is_int(totalPlayers));
	
	return get_int(totalPlayers);
}

/******************************************************************************
 ** Function: is_int
 ** Description: Indicates if a given string is an integer
 ** Parameters: string num
 ** Pre-Conditions: Determined what num is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool is_int (string num) {
	//Check every character of num
	for (int i = 0; i < num.length(); i++) {
		//Check if the current character is a num
		if ((num[i] >= 65 && num[i] <= 90) || (num[i] >= 97 && num[i] <= 122)) {
			return false;
		}
		//Check if the current character is a decimal
		if (num[i] == '.') {
			return false;
		}
	}
	//If the for loop runs all the way through, then the string must be an int
	return true;
}

/******************************************************************************
 ** Function: get_int
 ** Description: Takes a prompt from the user as a string literal, checks if input is a valid integer, returns the provided integer
 ** Parameters: string prompt
 ** Pre-Conditions: Determined what prompt is
 ** Post-Conditions: Return the prompt as an int if it is a valid int
*****************************************************************************/
int get_int(string prompt) {
	bool trueInt;
	int returnInt = 0;
	bool negative = false;
		
	//Keep checking if prompt is a valid integer until it is
	do {
		trueInt = is_int(prompt);
		if (trueInt == false) {
			cout << "That is not a valid integer! Please input a valid integer: ";
			cin >> prompt;
		}
	}
	while (trueInt == false);


	int i = 0;
	//Adjust i in case of a negative
	if (prompt[0] == '-') {
		i++;
		negative = true;
	}
		
	//Turn the string into an int
	for (; i < prompt.length(); i++) {
		returnInt += ((prompt[i] - 48) * (pow(10, prompt.length() - (i + 1))));
	}

	//Turn the int negative if needed
	if (negative == true) {
		returnInt *= -1;
	}

	return returnInt;
}

/******************************************************************************
 ** Function: begin_game
 ** Description: Continues to loop through the players, making them play the game until somebody wins
 ** Parameters: int totalPlayers
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void begin_game(int totalPlayers) {
	int currentPlayer = 0, lastPlayer = 0, test = 0;
	int* scoreboard = new int[totalPlayers];
	
	//Set all indices to 0
	pop_arr(scoreboard, totalPlayers);
	
	//Continue to loop through the players and have them take their turn until someone reaches the winning score
	for (; currentPlayer < totalPlayers; currentPlayer++) {
		//Let the player roll until farkle or they stop and update the scoreboard
		scoreboard[currentPlayer] += roll(totalPlayers, currentPlayer, scoreboard);
		
		print_scoreboard(scoreboard, totalPlayers);
		
		//If someone has reached the winning score (Default of 10,000) break
		if (win_reached(scoreboard, totalPlayers)) {
			break;
		}
		
		//If all players have taken a turn, start over from the first player
		if (currentPlayer == totalPlayers - 1) {
			currentPlayer = -1;
		}
	}
	
	//Log who got the winning score
	lastPlayer = currentPlayer;
	
	//Go to the next players turn
	if (lastPlayer == totalPlayers - 1) {
		currentPlayer = 0;
	}
	else {
		currentPlayer++;
	}

	cout << "Player " << lastPlayer + 1 << " has reached 10,000 points. Everyone but that player gets one more chance to raise their score." << endl;
	
	//Loop through all players one more time except for last player starting at the player after the last one to play
	while (currentPlayer != lastPlayer) {
		//Let the player roll until farkle or they stop and update the scoreboard
		scoreboard[currentPlayer] += roll(totalPlayers, currentPlayer, scoreboard);

		print_scoreboard(scoreboard, totalPlayers);

		//If all players have taken a turn, start over from the first player
		if (currentPlayer == totalPlayers - 1) {
			currentPlayer = -1;
		}
		currentPlayer++;
	}

	//Check who the winner is
	winner(scoreboard, totalPlayers);
	
	delete [] scoreboard;
	scoreboard = NULL;
}

/******************************************************************************
 ** Function: win_reached
 ** Description: Check to see if someone has reached the winning score
 ** Parameters: int* scoreboard, int totalPlayers
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool win_reached(int* scoreboard, int totalPlayers) {
	//Check if anyone has reached a win
	for (int i = 0; i < totalPlayers; i++) {
		if (scoreboard[i] >= 10000) {
			return true;	
		} 
	}
	return false;
}	

/******************************************************************************
 ** Function: winner
 ** Description: Check to see who won
 ** Parameters: int* scoreboard, int totalPlayers
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void winner(int* scoreboard, int totalPlayers) {
	int max = 0, winner;

	for (int i = 0; i < totalPlayers; i++) {
		if (scoreboard[i] > max) {
			max = scoreboard[i];
			winner = i;
		}
	}

	cout << "Congratulations Player " << winner + 1 << ". YOU WIN!!" << endl;

}

/******************************************************************************
 ** Function: pop_arr
 ** Description: Fills all indices of an array with 0
 ** Parameters: int* arr, int length
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void pop_arr(int* arr, int length) {
	//Fill the array with 0
	for (int i = 0; i < length; i++) {
		arr[i] = 0;
	}
}

void pop_arr(int* arr, int length, int setting) {
	//Fill the array with 0
	for (int i = 0; i < length; i++) {
		arr[i] = setting;
	}
}

/******************************************************************************
 ** Function: print_arr
 ** Description: Prints an array to the scrren
 ** Parameters: int* arr, int length
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void print_arr(int* arr, int length) {
	//Print the array to screen
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

/******************************************************************************
 ** Function: print_scoreboard
 ** Description: Prints an array to the scrren
 ** Parameters: int* arr, int length
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void print_scoreboard(int* arr, int length) {
	cout << "The scoreboard is as follows:" << endl;

	cout << "-----------------------------------------" << endl;
	//Print the array to screen
	for (int i = 0; i < length; i++) {
		cout << "Player " << i + 1 << ": ";	
		cout << arr[i] << endl;
	}
	cout << "-----------------------------------------" << endl;
}

/******************************************************************************
 ** Function: roll
 ** Description: Continues to roll dice and update the running score until the player stops or farkles
 ** Parameters: int currentPlayer
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int roll(int totalPlayers, int currentPlayer, int* scoreboard) {
	int runningScore = 0, numDiceToRoll = 6;
	bool boolFarkle;
	srand(time(NULL));
	
	//Keep rolling while the player wants to and there is no farkle
	do {
		int dice[numDiceToRoll];

		//roll the dice
		for (int i = 0; i < numDiceToRoll; i++) {
			dice[i] = (rand() % 6) + 1;
		}
		
		//Print what was rolled
		cout << "Player " << (currentPlayer + 1) << ", You rolled: ";
		print_arr(dice, numDiceToRoll);
		
		//Set boolFarkle to use outside of scope
		boolFarkle = farkle(dice, numDiceToRoll);
		
		//If the player did not farkle, ask the user which dice they want to keep and update the running score
		if (!boolFarkle) {
			runningScore += diceKeep(dice, &numDiceToRoll);
		}
		
		//Reset numDiceToRoll if all dice have been rolled
		if (numDiceToRoll == 0) {
			numDiceToRoll = 6;
		}
		
	} while (!boolFarkle && roll_again(totalPlayers, currentPlayer, runningScore, scoreboard, numDiceToRoll));

	//Set the running score to zero if there was a farkle
	if (boolFarkle) {
		cout << "Sorry Player " << currentPlayer + 1 << ". You have farkled and your running score has been lost!" << endl;
		runningScore = 0;
	}
	
	return runningScore;
}

/******************************************************************************
 ** Function: roll_again
 ** Description: Asks the player if they would like to roll again
 ** Parameters: int totalPlayers, int currentPlayer, int runningScore, int* scoreboard, int numDiceToRoll
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool roll_again(int totalPlayers, int currentPlayer, int runningScore, int* scoreboard, int numDiceToRoll) {
	string answer;
	
	do {
		cout << endl;
		cout << "Player " << currentPlayer + 1 << ", your running score is: " << runningScore << ". " << endl;
		print_scoreboard(scoreboard, totalPlayers);
		cout << "You have " << numDiceToRoll << " dice you can roll." << endl;
		cout << "Would you like to roll again or stop and bank your running score?" << endl;
		cout << "1) Roll again" << endl;
		cout << "2) Bank running score" << endl;
		getline(cin, answer);
		cout << endl;
		
		if (!is_int(answer) || get_int(answer) > 2 || get_int(answer) < 1) {
			cout << "Please enter 1 or 2 only!" << endl;
		}
		//Don't let the user bank their score if they have less than 500 runningScore and have not banked already
		else if (get_int(answer) == 2 && scoreboard[currentPlayer] == 0 & runningScore < 500 ) {
			cout << "Sorry, you must have a runinng score of at least 500 before you can bank your score for the first time. After that, you can bank your running score at any point. " << endl;
		}
	} while (!is_int(answer) || (get_int(answer) == 2 && scoreboard[currentPlayer] == 0 && runningScore < 500) || get_int(answer) > 2 || get_int(answer) < 1);
	

	if (get_int(answer) == 1) {
		return true;
	}
	if (get_int(answer) == 2) {
		return false;
	}
}

/******************************************************************************
 ** Function: farkle
 ** Description: Checks to see if the current roll is a farkle
 ** Parameters: int* dice, int numDiceToRoll
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool farkle(int* dice, int numDiceToRoll) {
	int diceValueAmnts[DICE_VALUES];
	pop_arr(diceValueAmnts, DICE_VALUES);
	get_diceValueAmnts(diceValueAmnts, dice, numDiceToRoll);
	
	//Check if there are two triplets
	if (kind_counter(diceValueAmnts, 3) == 2) {
		return false;
	}
	//Check if there are four of any number w/ a pair
	if (kind_counter(diceValueAmnts, 4) == 1 && kind_counter(diceValueAmnts, 2) == 1) {
		return false;
	}
	//Check if there are three pairs
	if (kind_counter(diceValueAmnts, 2) == 3) {
		return false;
	}
	//Check if there is a 1-6 straight
	if (straight(diceValueAmnts)) {
		return false;
	}
	//Check if there is 6 of any number
	if (kind_counter(diceValueAmnts, 6) == 1) {
		return false;	
	}	
	//Check if there is 5 of any number
	if (kind_counter(diceValueAmnts, 5) == 1) {
		return false;
	}
	//Check if there is 4 of any number
	if (kind_counter(diceValueAmnts, 4) == 1) {
		return false;
	}
	//Check if there is 3 of any number
	if (kind_counter(diceValueAmnts, 3) == 1) {
		return false;
	}
	//Check if there are any 1's or 5's
	if (diceValueAmnts[1] > 0 || diceValueAmnts[5] > 0) {
		return false;
	}

	//If all tests were passed, then it is a farkle!
	return true;
}

/******************************************************************************
 ** Function: get_diceValueAmnts
 ** Description: Runs through all of the die rolled and counts how many of each value there are
 ** Parameters: int* diceValueAmnts, int* dice
 ** Pre-Conditions: None
 ** Post-Conditions: diceValueAmnts should store how many of each value there are
*****************************************************************************/
void get_diceValueAmnts(int* diceValueAmnts, int* dice, int length) {
	//Runs through all of the die rolled and counts how many of each value there are
	for (int i = 0; i < length; i++) {
		int currentValue = dice[i];
		diceValueAmnts[currentValue]++;
	}
}

/******************************************************************************
 ** Function: kind_counter
 ** Description: Checks how many of a specific kind there are
 ** Parameters: int* diceValueAmnts
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int kind_counter(int* diceValueAmnts, int kind) {
	int kindCount = 0;

	for (int i = 1; i < DICE_VALUES; i++) {
		if (diceValueAmnts[i] == kind) {
			kindCount++;
		}
	}
	
	return kindCount;
}

/******************************************************************************
 ** Function: straight
 ** Description: Checks if there is a straight in an array
 ** Parameters: int* diceValueAmnts
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool straight(int* diceValueAmnts) {
	for (int i = 1; i < DICE_VALUES; i++) {
		//If there is a number missing or more than one of a certain value, there cannot be a straight
		if (diceValueAmnts[i] != 1) {
			return false;
		}
	}

	return true;
}

/******************************************************************************
 ** Function: diceKeep
 ** Description: Asks the user which dice they want to keep
 ** Parameters: int* dice, int* numDiceToRoll
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int diceKeep(int* dice, int* numDiceToRoll) {
	string answer;
	int numDiceKept = 0, dieKept = 0, runningScore = 0;
	int diceValueAmnts[DICE_VALUES];
	int* specDiceValuesKept;
	int* specDiceKept;
	pop_arr(diceValueAmnts, DICE_VALUES);
	
	
	do {
		do {
			cout << "How many dice would you like to keep? ";
			getline(cin, answer);
			
			if (!is_int(answer) || get_int(answer) > *numDiceToRoll || get_int(answer) < 1) {
				cout << "You must enter a minimum of 1 die and you can only enter a maximum amount of however many dice were rolled!" << endl;
			}
		} while (!is_int(answer) || get_int(answer) > *numDiceToRoll || get_int(answer) < 1);
		
		numDiceKept = get_int(answer);

		specDiceValuesKept = new int[numDiceKept];
		specDiceKept = new int[numDiceKept];
		pop_arr(specDiceKept, numDiceKept, -1);
	
		//Ask the user which dice they want to keep
		cout << "(Enter which dice you would like to keep one at a time. Enter the dice order number, not the value.)" << endl;
		for (int i = 0; i < numDiceKept; i++) {
			do {
				cout << "Die " << (i + 1) << ": ";
				getline(cin, answer);
								
				if (!is_int(answer) || get_int(answer) > *numDiceToRoll || get_int(answer) < 1 || duplicate(specDiceKept, numDiceKept, get_int(answer) - 1)) {
					cout << "Please choose a valid dice and not a dice you have already chosen!" << endl;
				}

			} while (!is_int(answer) || get_int(answer) > *numDiceToRoll || get_int(answer) < 1  || duplicate(specDiceKept, numDiceKept, get_int(answer) - 1));
			dieKept = get_int(answer);
			dieKept--;

			//Keep track of the values being kept
			specDiceValuesKept[i] = dice[dieKept];
			
			//Keep track of the dice being kept
			specDiceKept[i] = dieKept;


		}	
		
		if (updateRunningScore(specDiceValuesKept, numDiceKept) == 0) {
			cout << "PLEASE CHOOSE DICE THAT ALL CONTRIBUTE TO THE RUNNING SCORE!" << endl;	
		}		

	//Continue to ask the user for dice while the ones they entered do not all contribute to the score
	} while(updateRunningScore(specDiceValuesKept, numDiceKept) == 0);

	//Lower the amount of dice there are to roll by how many were taken
	*numDiceToRoll -= numDiceKept;
	
	runningScore = updateRunningScore(specDiceValuesKept, numDiceKept);
	
	delete [] specDiceValuesKept;
	specDiceValuesKept = NULL;
	
	delete [] specDiceKept;
	specDiceKept = NULL;

	return runningScore;
}

/******************************************************************************
 ** Function: duplicate
 ** Description: Checks if the user already chose that dice
 ** Parameters: int* specDiceValuesKept, int numDiceToRoll, int dieKept
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool duplicate(int* specDiceKept, int numDiceKept, int dieKept) {
	for (int i = 0; i < numDiceKept; i++) {
		if (specDiceKept[i] == dieKept) {
			return true;
		}
	}
	return false;
}

/******************************************************************************
 ** Function: updateRunningScore
 ** Description: Updates the running score and gives an error if not all dice were used
 ** Parameters: int* dice, int numDiceToRoll
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int updateRunningScore(int* dice, int numDiceToRoll) {
	int runningScore = 0, diceAccounted = 0;
	int diceValueAmnts[DICE_VALUES];
	pop_arr(diceValueAmnts, DICE_VALUES);
	get_diceValueAmnts(diceValueAmnts, dice, numDiceToRoll);
	
	//Check if there are two triplets
	if (kind_counter(diceValueAmnts, 3) == 2) {
		return 2500;
	}
	//Check if there are four of any number w/ a pair
	if (kind_counter(diceValueAmnts, 4) == 1 && kind_counter(diceValueAmnts, 2) == 1) {
		return 1500;
	}
	//Check if there are three pairs
	if (kind_counter(diceValueAmnts, 2) == 3) {
		return 1500;
	}
	//Check if there is a 1-6 straight
	if (straight(diceValueAmnts)) {
		return 1500;
	}
	//Check if there is 6 of any number
	if (kind_counter(diceValueAmnts, 6) == 1) {
		return 3000;	
	}	
	//Check if there is 5 of any number
	if (kind_counter(diceValueAmnts, 5) == 1) {
		runningScore += 2000;
		diceAccounted += 5;
	}
	//Check if there is 4 of any number
	if (kind_counter(diceValueAmnts, 4) == 1) {
		runningScore += 1000;
		diceAccounted += 4;
	}
	//Check if there is 3 of any number
	if (kind_counter(diceValueAmnts, 3) == 1) {
		if (triplet_type(diceValueAmnts) == 100) {
			runningScore += 300;
		} 
		else {
			runningScore += triplet_type(diceValueAmnts);
		}
		diceAccounted += 3;
	}
	//Check if there are any 1's
	if (diceValueAmnts[1] > 0 && diceValueAmnts[1] < 3) {
		runningScore += (100 * diceValueAmnts[1]);
		diceAccounted += diceValueAmnts[1];
	}
	//Check if there are any 5's
	if (diceValueAmnts[5] > 0 && diceValueAmnts[5] < 3) {
		runningScore += (50 * diceValueAmnts[5]);
		diceAccounted += diceValueAmnts[5];
	}
	
	//If there is a mismatch between the number of dice kept and the dice accounted for, return an error
	if (diceAccounted != numDiceToRoll) {
		return 0;
	}
	
	return runningScore;
}

/******************************************************************************
 ** Function: triplet_type
 ** Description: Checks what type of triplet was rolled and returns the appropriate score
 ** Parameters: int* diceValueAmnts
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int triplet_type(int* diceValueAmnts) {
	for (int i = 1; i < DICE_VALUES; i++) {
		if (diceValueAmnts[i] == 3) {
			return (i * 100);
		}
	}
}
