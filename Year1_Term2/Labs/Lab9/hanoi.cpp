#include <iostream>

using namespace std;

void init_arr(int **board, int rows, int cols);
void print_arr(int **board, int rows, int cols);
void towers(int disks, int **b, int from_col, int to_col, int spare, int rows);

int main() {
	int rows = 3, cols = 3;
	int **board;
	
	cout << "How many disks would you like? ";
	cin >> rows;
	
	board = new int*[rows];
	for (int i = 0; i < rows; i++) {
		board[i] = new int[cols];
	}

	init_arr(board, rows, cols);
	print_arr(board, rows, cols);

	towers(rows, board, 0, 2, 1, rows); 
	
	for (int i = 0; i < rows; i++) {
		delete [] board[i];
	}
	delete [] board;
}

void towers(int disks, int **b, int from_col, int to_col, int spare, int rows) {
	bool moved = false;
	
	if (disks >= 1) {
		towers(disks-1, b, from_col, spare, to_col, rows);
			
	
		//Move
		for (int from_row = 0; from_row < rows; from_row++) {
			if (b[from_row][from_col] != 0) {
				for (int to_row = rows - 1; to_row >= 0; to_row--) {
					if (b[to_row][to_col] == 0) {
						b[to_row][to_col] = b[from_row][from_col];
						b[from_row][from_col] = 0;	
						moved = true;
						break;
					}	
				} 
			}

			if (moved == true) {
				break;
			}
		}
		
		moved = false;

		print_arr(b, rows, 3);
		towers(disks-1, b, spare, to_col, from_col, rows);
	}
}


void init_arr(int **board, int rows, int cols) {
	for (int i = 0; i < cols; i++) {
		if (i == 0) {
			for (int j = 0; j < rows; j++) {
				board[j][i] = (j+1);
			}
		}
		else {
			for (int j = 0; j < rows; j++) {
				board[j][i] = 0;
			}
		}
	}
}

void print_arr(int **board, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "-----"<< endl;
}
