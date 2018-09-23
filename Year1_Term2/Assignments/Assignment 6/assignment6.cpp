/**************************************************************************************************************************************************
 ** Program Filename: Assignment 6: Checkers
 ** Author: Zach Bishop
 ** Date: 3/18/2018
 ** Description: This program runs the game of checkers
 ** Input: User input
 ** Output: Prompts and game board printed to the screen
**************************************************************************************************************************************************/
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <cstring>

using namespace std;

bool winner(char**board, char currentPlayer, int size); 
void switch_players(char* currentPlayer);
char* choose_piece(char currentPlayer);
bool valid_piece(char** board, char currentPlayer, char* currentPiece);	
bool valid_piece_format(char* currentPiece, int rows);
char* choose_path(char* currentPiece, char currentPlayer);
bool valid_path(char** board, char currentPlayer, char* currentPiece, char* movement, int rows);
bool path_possible(char** board, char currentPlayer, int currentPieceRow, int currentPieceCol, int moveToRow, int moveToCol);
bool valid_path_format(char* movement, int rows);
void move(char** board, char* currentPiece, char* movement, int rows, char currentPlayer, int* xsCaptured, int* osCaptured);
void king(char** board, int currentPieceRow, int currentPieceCol, char currentPlayer, int rows);
char* get_currentMove(char* movement, int* i);
int get_row(char* str);
void print_board(char** board, int rows, int cols, int xsCaptured, int osCaptured);
char** init_arr(int rows, int cols);
void pop_arr(char** board, int rows, int cols);
void del_arr(char** arr, int rows);
char* get_input();
void add_one_char(char** str, char c);
bool is_int (char* num);
int get_int(char* prompt);


//TO DO:
//Make check for winning by no moves available
//Make check for keep moving after being kinged (not allowed)
//Make check for incorrect formatting

/******************************************************************************
 ** Function: main
 ** Description: Where the program starts
 ** Parameters: int argc, char** argv
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int main(int argc, char** argv) {
	char** board;
	char currentPlayer = 'X';
	char* currentPiece;
	char* movement;
	char* str;
	int rows = 8, cols = 8, xsCaptured = 0, osCaptured = 0;
	
	//Deal with command line arguments
	if (argc != 2) {
		do {
			str = get_input();

			//If the user enters an input that is not valid notify them
			if (!is_int(str) || (get_int(str) != 8 && get_int(str) != 10 && get_int(str) != 12)) {
				cout << "Please input a valid integer that is 8, 10, or 12!" << endl;
			}
		} while(!is_int(str) || (get_int(str) != 8 && get_int(str) != 10 && get_int(str) != 12));
		
		rows = get_int(str);
		cols = get_int(str);	
		delete [] str;
	}
	else if (!is_int(argv[1]) || (get_int(argv[1]) != 8 && get_int(argv[1]) != 10 && get_int(argv[1]) != 12)){
		do {
			str = get_input();
			
			//If the user enters an input that is not valid notify them
			if (!is_int(str) || (get_int(str) != 8 && get_int(str) != 10 && get_int(str) != 12)) {
				cout << "Please input a valid integer that is 8, 10, or 12!" << endl;
			}
		} while(!is_int(str) || (get_int(str) != 8 && get_int(str) != 10 && get_int(str) != 12));
		rows = get_int(str);
		cols = get_int(str);		
		delete [] str;
	}
	else {		
		str = new char[strlen(argv[1]) + 1];
		strcpy(str, argv[1]);
		rows = get_int(str);
		cols = get_int(str);		
		delete [] str;
	}
	
	//Initialize, populate, and print the board
	board = init_arr(rows, cols);
	pop_arr(board, rows, cols);
	print_board(board, rows, cols, xsCaptured, osCaptured);
	
	do {
		//Continue to ask the player to choose a piece while the chosen piece is not valid
		do {
			//Ask the user which piece they want to move
			currentPiece = choose_piece(currentPlayer);	
		} while(!valid_piece_format(currentPiece, rows) || !valid_piece(board, currentPlayer, currentPiece));
	
		//Continue to ask the player to choose a path while the path chosen is not valid
		do {
			//Ask the user how they want to move the piece
			movement = choose_path(currentPiece, currentPlayer);	
		} while(!valid_path(board, currentPlayer, currentPiece, movement, rows) || !valid_path_format(movement, rows));
		
		//Move and capture
		move(board, currentPiece, movement, rows, currentPlayer, &xsCaptured, &osCaptured);

		delete [] currentPiece;
		delete [] movement;
		break;	
		//Change players
		switch_players(&currentPlayer);
	} while (!winner(board, currentPlayer, rows));
	
	del_arr(board, rows);

	return 0;
}

/******************************************************************************
 ** Function: winner
 ** Description: Checks if there is a winner
 ** Parameters: char** board, char currentPlayer, int size
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool winner(char**board, char currentPlayer, int size) {
	bool winner = true;
	
	//Check if Player O won
	if (currentPlayer == 'X') {
		//If the current player has any pieces left, there is possibly no winner
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (board[i][j] == 'x' || board[i][j] == 'X') {
					winner = false;
				}
						
			}
		}	
	
		if (winner == true) {
			switch_players(&currentPlayer);
			cout << "Congratulations Player " << currentPlayer << "! You Win!" << endl;
			return winner;
		}
	}
	//Check if Player X won
	else {
		//If the current player has any pieces left, there is no winner
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (board[i][j] == 'o' || board[i][j] == 'O') {
					winner = false;
				}	
			}
		}
		
		if (winner == true) {
			switch_players(&currentPlayer);
			cout << "Congratulations Player " << currentPlayer << "! You Win!" << endl;
			return winner;
		}
	}
}

/******************************************************************************
 ** Function: switch_players
 ** Description: Changes to the other player
 ** Parameters: char* currentPlayer
 ** Pre-Conditions: None
 ** Post-Conditions: currentPlayer is switched to its "opposite"
*****************************************************************************/
void switch_players(char* currentPlayer) {
	if (*currentPlayer == 'X') {
		*currentPlayer = 'O';
	}
	else {
		*currentPlayer = 'X';
	}
}

/******************************************************************************
 ** Function: print_board
 ** Description: Prints out the board in a checker pattern
 ** Parameters: char** board, int rows, int cols
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void print_board(char** board, int rows, int cols, int xsCaptured, int osCaptured) {	
	//Print out the column indices on the top of the board
	cout << "    ";
	for (int i = 0; i < cols; i++) {
		cout << ((char) (i+65)) << "   ";
	}
	cout << endl;
	
	for (int i = 0; i < rows; i++) {
		//Print out row indices on the left side
		if (i < 9) {
			cout << i+1 << " ";
		}
		else {
			cout << i+1;
		}
		
		//Print colors
		for (int j = 0; j < cols; j++) {
			if (i % 2 == 0 && j % 2 == 0)
				cout << "|\033[30;47m " << board[i][j] << " ";
			else if (i % 2 == 1 && j % 2 == 1)
				cout << "|\033[30;47m " << board[i][j] << " ";
			else
				cout << "|\033[0m " << board[i][j] << " ";
			cout << "\033[0m";
		}
		cout << endl;
	}
	cout << "The amount of X pieces captured by Player O: " << xsCaptured << endl;
	cout << "The amount of O pieces captured by Player X: " << osCaptured << endl;
	cout << endl;	
}

/******************************************************************************
 ** Function: choose_piece
 ** Description: Asks the currentPlayer to choose a piece
 ** Parameters: char currentPlayer
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
char* choose_piece(char currentPlayer) {
	char* currentPiece = new char[256];

	cout << "Player " << currentPlayer << ", please choose a piece based on the coordinate system (Ex: F2) ";
	cin.get(currentPiece, 256, '\n');	
	cin.clear();
	cin.ignore();
	
	return currentPiece;
}

/******************************************************************************
 ** Function: valid_piece
 ** Description: Check if the piece chosen is valid
 ** Parameters: char** board, char currentPlayer, char* currentPiece
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool valid_piece(char** board, char currentPlayer, char* currentPiece) {		
	int currentPieceRow = get_row(currentPiece), currentPieceCol = (currentPiece[0] - 65);
		
	//Make sure the currentPlayer is choosing their place
	if (currentPlayer == 'O') {
		if (board[currentPieceRow][currentPieceCol] != 'o' && board[currentPieceRow][currentPieceCol] != 'O') {
			cout << endl << "THAT IS NOT YOUR PIECE!" << endl;
			return false;
		}
	}
	else {
		if (board[currentPieceRow][currentPieceCol] != 'x' && board[currentPieceRow][currentPieceCol] != 'X') {	
			cout << endl << "THAT IS NOT YOUR PIECE!" << endl;
			return false;
		}
	}

	
	//Make sure the player chose a piece that can move
	//Check if the piece can move by one in any direction
	if (!path_possible(board, currentPlayer, currentPieceRow, currentPieceCol, (currentPieceRow + 1), (currentPieceCol + 1))) {
		if (!path_possible(board, currentPlayer, currentPieceRow, currentPieceCol, (currentPieceRow + 1), (currentPieceCol - 1))) {
			if (!path_possible(board, currentPlayer, currentPieceRow, currentPieceCol, (currentPieceRow - 1), (currentPieceCol - 1))) {
				if (!path_possible(board, currentPlayer, currentPieceRow, currentPieceCol, (currentPieceRow - 1), (currentPieceCol + 1))) {
					//Check if the piece can move by two in any direction
					if (!path_possible(board, currentPlayer, currentPieceRow, currentPieceCol, (currentPieceRow + 2), (currentPieceCol + 2))) {
						if (!path_possible(board, currentPlayer, currentPieceRow, currentPieceCol, (currentPieceRow + 2), (currentPieceCol - 2))) {
							if (!path_possible(board, currentPlayer, currentPieceRow, currentPieceCol, (currentPieceRow - 2), (currentPieceCol - 2))) {
								if (!path_possible(board, currentPlayer, currentPieceRow, currentPieceCol, (currentPieceRow - 2), (currentPieceCol - 2))) {
									cout << endl << "THAT PIECE CANNOT BE MOVED! CHOOSE A DIFFERENT PIECE!" << endl;
									return false;
								}
							}
						}	
					}
				}
			}
		}
	}	

	//If all test passed then the piece choice is valid!
	return true;
} 

/******************************************************************************
 ** Function: valid_piece_format
 ** Description: Make sure the piece selection format is correct
 ** Parameters: char* currentPiece, int rows
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool valid_piece_format(char* currentPiece, int rows) {
	//Make sure the currentPiece format is the correct length
	if (strlen(currentPiece) > 3 || strlen(currentPiece) < 2) {
		cout << endl << "ERROR! YOUR INPUT IS NOT VALID! LOOK AT THE EXAMPLE!" << endl;
		return false;
	}

	//If the piece is greater than 3 long, make sure the row format is correct
	if (strlen(currentPiece) == 3) {
		if (currentPiece[2] > '2' || currentPiece[2] < '0') {
			return false;
		}
	}

	//Make sure the column selection was entered correctly
	if (currentPiece[0] < 'A' || currentPiece[0] > rows + 64) {
		cout << endl << "ERROR! YOUR INPUT IS NOT VALID! LOOK AT THE EXAMPLE!" << endl;
		return false;	
	}
	
	//Make sure the row selection was entered correctly 
	if (get_row(currentPiece) < 0 || get_row(currentPiece) > (rows - 1)) {
		cout << endl << "ERROR! YOUR INPUT IS NOT VALID! LOOK AT THE EXAMPLE!" << endl;
		return false;
	}	

	return true;
	
} 

/******************************************************************************
 ** Function: choose_path
 ** Description: The current player chooses their path of movement
 ** Parameters: char* currentPiece, char currentPlayer
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
char* choose_path(char* currentPiece, char currentPlayer) {
	char* movement = new char[256];
	
	cout << "Player " << currentPlayer << ", please lay out the path you would like to move by typing the coordinates with spaces between them (Ex: F2 D4 F6) ";
	
	cin.get(movement, 256, '\n');	
	cin.clear();	
	cin.ignore();
	
	return movement;
}

/******************************************************************************
 ** Function: valid_path
 ** Description: Checks if the chosen movement is valid
 ** Parameters: char** board, char currentPlayer, char* currentPiece, char* movement, int rows
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool valid_path(char** board, char currentPlayer, char* currentPiece, char* movement, int rows) {
	int index = 0;
	int currentPieceRow = get_row(currentPiece), currentPieceCol = (currentPiece[0] - 65);
	
	do {
		//Update where the currentMove is to
		char* currentMove = get_currentMove(movement, &index);
		int moveToRow = get_row(currentMove), moveToCol = (currentMove[0] - 65);
		
		//Check if the player is not moving diagnoally
		if (abs(((moveToRow - 48) - (currentPieceRow - 48))) != abs(((moveToCol - 64) - (currentPieceCol - 64)))) {
			cout << endl << "ERROR! YOUR INPUT IS NOT VALID! LOOK AT THE EXAMPLE!" << endl;
			return false;
		}

		//Check if the player is moving backward
		if (currentPlayer == 'O' && (currentPieceRow - moveToRow > 0) && board[currentPieceRow][currentPieceCol] != 'O') {
			cout << endl << "CANNOT MOVE THAT PIECE BACKWARDS! ALSO, TURN ENDS AFTER BEING KINGED!" << endl;
			return false;	
		}	
		else if (currentPlayer == 'X' && (currentPieceRow - moveToRow < 0) && board[currentPieceRow][currentPieceCol] != 'X') {
			cout << endl << "CANNOT MOVE THAT PIECE BACKWARDS! ALSO, TURN ENDS AFTER BEING KINGED!" << endl;
			return false;
		}
		
		//Check if the player is moving further than 2 spaces
		if (abs(moveToRow - currentPieceRow) > 2) {
			cout << endl << "ERROR! YOUR INPUT IS NOT VALID! LOOK AT THE EXAMPLE!" << endl;
			return false;
		}

		//Check if the player tried to jump one space when attacking
		if (abs(moveToRow - currentPieceRow) == 1 && strlen(movement) > 3) {
			cout << endl << "ERROR! YOUR INPUT IS NOT VALID! LOOK AT THE EXAMPLE!" << endl;
			return false;
		}

		//Check if the player tried to jump two spaces without capturing a piece
		if (abs(moveToRow - currentPieceRow) == 2) {
			if (currentPlayer == 'O') {
				if (board[(moveToRow + currentPieceRow)/2][(moveToCol + currentPieceCol)/2] != 'x' && board[(moveToRow + currentPieceRow)/2][(moveToCol + currentPieceCol)/2] != 'X') {
					cout << endl << "YOU CAN ONLY JUMP TWO SPACES IF YOU ARE CAPTURING A PIECE" << endl;
					return false;
				}
			}
			else {
				if (board[(moveToRow + currentPieceRow)/2][(moveToCol + currentPieceCol)/2] != 'o' && board[(moveToRow + currentPieceRow)/2][(moveToCol + currentPieceCol)/2] != 'O') {	
					cout << endl << "YOU CAN ONLY JUMP TWO SPACES IF YOU ARE CAPTURING A PIECE" << endl;
					return false;
				}
			}
		}
		
		//Check if the player is trying to jump onto another piece
		if (board[moveToRow][moveToCol] != ' ') {
			cout << endl << "YOU CANNOT JUMP ONTOP OF PIECES!" << endl;
			return false;
		}

		//Increase index
		index++;

		//Change where the currentPiece is
		currentPieceRow = moveToRow;
		currentPieceCol = moveToCol;				
		
	} while (index < strlen(movement));
	
	//If all tests are passed, it is a valid move
	return true;
}

/******************************************************************************
 ** Function: path_possible
 ** Description: Checks if a path is possible for a piece
 ** Parameters: char** board, char currentPlayer, int currentPieceRow, int currentPieceCol, int moveToRow, int moveToCol
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool path_possible(char** board, char currentPlayer, int currentPieceRow, int currentPieceCol, int moveToRow, int moveToCol) {
	//Check if the player is moving backward
	if (currentPlayer == 'O' && (currentPieceRow - moveToRow > 0) && board[currentPieceRow][currentPieceCol] != 'O') {
		return false;	
	}	
	else if (currentPlayer == 'X' && (currentPieceRow - moveToRow < 0) && board[currentPieceRow][currentPieceCol] != 'X') {
		return false;
	}
		
	//Check if the player tried to jump two spaces without capturing a piece
	if (abs(moveToRow - currentPieceRow) == 2) {
		if (currentPlayer == 'O') {
			if (board[(moveToRow + currentPieceRow)/2][(moveToCol + currentPieceCol)/2] != 'x' && board[(moveToRow + currentPieceRow)/2][(moveToCol + currentPieceCol)/2] != 'X') {
				return false;
			}
		}
		else {
			if (board[(moveToRow + currentPieceRow)/2][(moveToCol + currentPieceCol)/2] != 'o' && board[(moveToRow + currentPieceRow)/2][(moveToCol + currentPieceCol)/2] != 'O') {	
				return false;
			}
		}
	}
		
	//Check if the player is trying to jump onto another piece
	if (board[moveToRow][moveToCol] != ' ') {
		return false;
	}
	
	//If all tests are passed, it is a valid move
	return true;
}

/******************************************************************************
 ** Function: valid_path_format
 ** Description: Make sure the path is formatted correctly
 ** Parameters: char* movement, int rows
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
bool valid_path_format(char* movement, int rows) {
	int index = 0;
	
	//Check the entire movement path
	do {
		//Update where the currentMove is to
		char* currentMove = get_currentMove(movement, &index);
		
		//Check that the currentMove was formatted correctly
		if (!valid_piece_format(currentMove, rows)) {		
			cout << endl << "ERROR! YOUR INPUT IS NOT VALID! LOOK AT THE EXAMPLE!" << endl;
			return false;
		}
	
		//Increase index
		index++;
	} while (index < strlen(movement));
	
	//If all tests are passed, it is a valid format
	return true;

	
}

/******************************************************************************
 ** Function: move
 ** Description: Moves the pieces on the board according to what the user wants while capturing
 ** Parameters: char** board, char* currentPiece, char* movement, int rows, char currentPlayer, int* xsCaptured, int* osCaptured
 ** Pre-Conditions: currentPiece and movement must contain values that wont seg fault board
 ** Post-Conditions: Board should be altered according to the movements the user wanted
*****************************************************************************/
void move(char** board, char* currentPiece, char* movement, int rows, char currentPlayer, int* xsCaptured, int* osCaptured) {
	int index = 0;
	int currentPieceRow = get_row(currentPiece), currentPieceCol = (currentPiece[0] - 65);
	bool attack;

	//Keep on moving until the whole path has been followed
	do {
		//Update where the currentMove is to
		char* currentMove = get_currentMove(movement, &index);
		int moveToRow = get_row(currentMove), moveToCol = (currentMove[0] - 65);
		
		//If the player is attacking, make attack true
		if (abs(moveToRow - currentPieceRow) == 2) {
			attack = true;
		}
		else {
			attack = false;	
		}	

						
		//Move the piece to the next movement spot
		board[moveToRow][moveToCol] = board[currentPieceRow][currentPieceCol];
			
		//Make the spot that the piece was at blank
		board[currentPieceRow][currentPieceCol] = ' ';
	
		//Only do this if the player is attacking
		if (attack) {		
			//Make the spot where the enemy was blank
			board[(moveToRow + currentPieceRow)/2][(moveToCol + currentPieceCol)/2] = ' ';

			//Increase the appropriate capture counter
			if (currentPlayer == 'O') {
				*xsCaptured += 1;
			}
			else {
				*osCaptured += 1;
			}
		}	

		//Change where the currentPiece is
		currentPieceRow = moveToRow;
		currentPieceCol = moveToCol;	
	
		//Increase index
		index++;

		//Check if the moved piece needs to be kinged
		king(board, currentPieceRow, currentPieceCol, currentPlayer, rows);
					
		//Print the board
		print_board(board, rows, rows, *xsCaptured, *osCaptured);
		
		//Delete the memory reserved for currentMove
		delete [] currentMove;
	} while (index < strlen(movement));
	
	
}

/******************************************************************************
 ** Function: king
 ** Description: Check if a piece should be kinged
 ** Parameters: char** board, char* currentPiece, char currentPlayer, int rows
 ** Pre-Conditions: None
 ** Post-Conditions: Board may have kings on it
*****************************************************************************/
void king(char** board, int currentPieceRow, int currentPieceCol, char currentPlayer, int rows) {
	//Check if a piece should be kinged
	if (currentPlayer == 'O' && currentPieceRow == rows - 1) {
		board[currentPieceRow][currentPieceCol] = 'O';
	}
	else if (currentPlayer == 'X' && currentPieceRow == 0) {
		board[currentPieceRow][currentPieceCol] = 'X';
	}
}

/******************************************************************************
 ** Function: get_currentMove
 ** Description: Get the next move out of the movement c-string
 ** Parameters: char* movement
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
char* get_currentMove(char* movement, int* i) {
	int j = *i;
	char* currentMove = new char;
	*currentMove = '\0';
	
	//Get the next move out of the movement c-string	
	for (; j < strlen(movement); j++) {
		if (movement[j] != ' ') {	
			add_one_char(&currentMove, movement[j]);	
			
			
		}	
		else {
			break;
		}
	
	}
	
	//Update the tracking index
	*i = j;
	
	return currentMove;
}

/******************************************************************************
 ** Function: get_row
 ** Description: Calculate the row value
 ** Parameters: char* str
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int get_row(char* str) {
	int total = 0;
	
	//Calculate the numebr if it is greater than 9
	if (str[2] >= '0' && str[2] <= '9') {
		total = ((str[1] - 48) * 10);
		total += (str[2] - 48);
	}
	//Calculate the number if it is less than 10
	else {
		total = (str[1] - 48);	
	}

	//Subtract 1 so that total is actually an index value
	total--;
	
	return total;
}

/******************************************************************************
 ** Function: init_arr
 ** Description: Initializes a 2D array on the heap
 ** Parameters: char** arr, int rows, int cols
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
char** init_arr(int rows, int cols) {
	char** arr;
	arr = new char*[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new char[cols];
	}

	return arr;
}

/******************************************************************************
 ** Function: pop_arr
 ** Description: Populates a 2D array
 ** Parameters: char** arr, int rows, int cols
 ** Pre-Conditions: Rows and columns are not greater than the length of the array
 ** Post-Conditions: Board should be filled with X's, O's, and Spaces
*****************************************************************************/
void pop_arr(char** board, int rows, int cols) {
	//Fill everything with spaces
	for (int i = 0; i < rows; i++) {	
		for (int j = 0; j < cols; j++) {	
			board[i][j] = ' ';
		}
	}
	
	
	//O pop
	for (int i = 0; i < (rows/2 - 1); i++) {	
		for (int j = 0; j < cols; j+=2) {	
			if ((i % 2 == 0) && j == 0) {
				j = 1;
			}
			board[i][j] = 'o';
		}
	}


	//X pop
	for (int i = rows - 1; i > (rows/2); i--) {	
		for (int j = 0; j < cols; j+=2) {	
			if ((i % 2 == 0) && j == 0) {
				j = 1;
			}
			board[i][j] = 'x';
		}
	}
}

/******************************************************************************
 ** Function: del_arr
 ** Description: Deletes memory on the heap
 ** Parameters: char** arr, int rows
 ** Pre-Conditions: Rows is the length of the array
 ** Post-Conditions: Delete memory on the heap
*****************************************************************************/
void del_arr(char** arr, int rows) {
	for (int i = 0; i < rows; i++) {
		delete [] arr[i];
	}
	delete [] arr;
}

/******************************************************************************
 ** Function: get_input
 ** Description: Gets input from the user to store in a c-style string
 ** Parameters: None
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
char* get_input() {
	char* str = new char;
	*str = '\0';
	cout << "Command Line Args not entered correctly, please enter how big you would like your board to be (Enter 8, 10, or 12)" << endl;
	while (cin.peek() != '\n') {
		add_one_char(&str, cin.get());
	}
	cin.ignore();
	cin.clear();
	
	return str;
}

/******************************************************************************
 ** Function: add_one_char
 ** Description: Adds a character to the end of a c-style string
 ** Parameters: char** str, char c
 ** Pre-Conditions: None
 ** Post-Conditions: str should have a character ended to the end of it
*****************************************************************************/
void add_one_char(char** str, char c) {
	char* temp = new char[strlen(*str) + 2];
	for (int i = 0; i < strlen(*str); i ++) {
		temp[i] = (*str)[i];
	}
	temp[strlen(*str)] = c;
	temp[strlen(*str) + 1] = '\0';
	
	delete [] (*str);

	(*str) = new char[strlen(temp) + 1];
	strcpy((*str), temp);
	delete [] temp;
}

/******************************************************************************
 ** Function: is_int
 ** Description: Indicates if a given string is an integer
 ** Parameters: string num
 ** Pre-Conditions: Determined what num is
 ** Post-Conditions: Return true or false
*****************************************************************************/
bool is_int (char* num) {
	//Check every character of num
	for (int i = 0; i < strlen(num); i++) {
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
int get_int(char* prompt) {
	bool trueInt;
	int returnInt = 0;
	bool negative = false;
		
	//Keep checking if prompt is a valid integer until it is
	do {
		trueInt = is_int(prompt);
		if (trueInt == false) {
			cout << "That is not a valid integer! Please input a valid integer: ";
			prompt = get_input();
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
	for (; i < strlen(prompt); i++) {
		returnInt += ((prompt[i] - 48) * (pow(10, strlen(prompt) - (i + 1))));
	}

	//Turn the int negative if needed
	if (negative == true) {
		returnInt *= -1;
	}

	return returnInt;
}

