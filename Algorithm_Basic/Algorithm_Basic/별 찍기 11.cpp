#include <iostream>
using namespace std;


int n;
bool star[3072][6143];

void func(int n, int row, int col) {
	// base condition
	if (n == 3) {
		star[row][col + 2] = true;

		star[row + 1][col + 1] = true;
		star[row + 1][col + 3] = true;

		star[row + 2][col] = true;
		star[row + 2][col + 1] = true;
		star[row + 2][col + 2] = true;
		star[row + 2][col + 3] = true;
		star[row + 2][col + 4] = true;
		return;
	}

	func(n / 2, row, col + n - n / 2);
	func(n / 2, row + n / 2, col);
	func(n / 2, row + n / 2, col + n);
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int init_col = n * 2 - 1;
	func(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < init_col; j++) {
			if (star[i][j]) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}