#include <iostream>

using namespace std;

int stairCombo(int steps) {
	if (steps == 1) {
		return 1;
	}
	else if (steps == 2) {
		return 2;
	}
	else {
		return stairCombo(steps - 1) + stairCombo(steps - 2);
	}
}


int main() {
	int steps = 0;
	
	cout << "How many steps are there? ";
	cin >> steps;

	cout << "The stairs can be climbed in " << stairCombo(steps) << " different ways!" << endl;
}

