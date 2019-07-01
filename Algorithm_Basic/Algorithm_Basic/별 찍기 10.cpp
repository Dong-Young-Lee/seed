#include <iostream>
#include <math.h>
using namespace std;

int n;
char star[2187][2187];

void func(int n, int row, int col, int condition) {
	// base condition
	if (n == 1) {
		if (condition == 0) {
			star[row][col] = '*';
		}
		else {
			star[row][col] = ' ';
		}
		return;
	}

	func(n / 3, row, col, condition);
	func(n / 3, row, col + n / 3, condition);
	func(n / 3, row, col + 2 * (n / 3), condition);
	
	func(n / 3, row + n / 3, col, condition);
	func(n / 3, row + n / 3, col + n / 3, condition + 1);
	func(n / 3, row + n / 3, col + 2 * (n / 3), condition);

	func(n / 3, row + 2 * (n / 3), col, condition);
	func(n / 3, row + 2 * (n / 3), col + n / 3, condition);
	func(n / 3, row + 2 * (n / 3), col + 2 * (n / 3), condition);

}

int main(void) {
	cin >> n;

	func(n, 0, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star[i][j];
		}
		cout << '\n';
	}

	return 0;

}