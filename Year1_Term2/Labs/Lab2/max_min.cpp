#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long bytes;
	long bits;
	long maxSigned;
	long minSigned;
	long maxUnsigned;
	long minUnsigned;

	cout << "How many bytes: " << endl;
	cin >> bytes;
	bits = bytes * 8;

	maxSigned = (pow(2,bits-1))-1;
	minSigned = pow(-2,bits-1);
	maxUnsigned = (pow(2,bits))-1;
	minUnsigned = 0;
	

	cout << "The maximum value in unsigned binary: " << maxUnsigned  << endl;
	cout << "The minimum value in unsigned binary: "  << minUnsigned << endl;
	cout << endl;

	cout << "The maximum value in signed binary: " << maxSigned << endl;
	cout << "The minimum value in signed binary: " << minSigned << endl;
	cout << endl;

	maxUnsigned++;
	maxSigned++;
	minUnsigned--;
	minSigned--;

	cout << "The maximum value in unsigned binary plus 1: " << maxUnsigned << endl;
	cout << "The minimum value in unsigned binary minus 1: " << minUnsigned << endl;
	cout << endl;

	cout << "The maximum value in signed binary plus 1: " << maxSigned << endl;
	cout << "The minimum value in signed binary minus 1: " <<minSigned << endl;

	return 0;
}
