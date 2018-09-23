#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using namespace std;

int fib_iter(int nthFib) {
	int fib1 = 0, fib2 = 1, fibFinal = 0;
	
	if (nthFib == 0) {
		return 0;
	}
	else if (nthFib == 1) {
		return 1;
	}
	else {
		for (int i = 1; i < nthFib; i++) {
			fibFinal = fib1 + fib2;
			fib1 = fib2;
			fib2 = fibFinal;
		}
	}

	return fibFinal;
}

int fib_recurs(int nthFib) {
	int fibFinal = 0;

	if (nthFib == 0) {
		return 0;
	}
	else if (nthFib == 1) {
		return 1 + fib_recurs(nthFib - 1);
	}

	return fibFinal = fib_recurs(nthFib - 1) + fib_recurs(nthFib - 2); 
}

void iterTiming(int input) {
	typedef struct timeval time;
	time stop, start;

	gettimeofday(&start, NULL);
	cout << "Iterative Result: " << fib_iter(input) << endl;

	gettimeofday (&stop, NULL);

	cout << "Iterative Timing: " << endl;

	if (stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
	cout << endl;
}

void recursTiming(int input) {
	typedef struct timeval time;
	time stop, start;

	gettimeofday(&start, NULL);
	cout << "Recursive result: " << fib_recurs(input) << endl;

	gettimeofday (&stop, NULL);

	cout << "Recursive Timing: " << endl;

	if (stop.tv_sec > start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;
	cout << endl;
}

int main() {
	int input;

	cout << "What fibonacci number would you like to calculate? ";
	cin >> input;

	iterTiming(input);
	recursTiming(input);
}
