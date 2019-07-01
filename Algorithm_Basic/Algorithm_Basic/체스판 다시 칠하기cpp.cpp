#include <iostream>
#include <vector>
#include <string>
using namespace std;

int chess_1[8][8] = {
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0}
};

int chess_2[8][8] = {
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 1, 0},
	{0, 1, 0, 1, 0, 1, 0, 1}
};

int m, n;
int main(void) {
	cin >> m >> n;
	cin.ignore();
	vector< vector<int> > board(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		string temp;
		getline(cin, temp);
		for (int j = 0; temp[j]; j++) {
			if (temp[j] == 'W') {
				board[i][j] = 0;
			}
			else {
				board[i][j] = 1;
			}
		}
	}

	int ans = 10000000;

	int diff_r = m - 8;
	int diff_c = n - 8;

	for (int i = 0; i <= diff_r; i++) {
		for (int j = 0; j <= diff_c; j++) {

			int paint_1 = 0;
			int paint_2 = 0;

			for (int a = 0; a < 8; a++) {
				for (int b = 0; b < 8; b++) {
					if (board[a + i][b + j] != chess_1[a][b]) {
						paint_1++;
					}
					if (board[a + i][b + j] != chess_2[a][b]) {
						paint_2++;
					}
				}
			}

			if (ans > paint_1) {
				ans = paint_1;
			}

			if (ans > paint_2) {
				ans = paint_2;
			}

		}
	}


	cout << ans;

	return 0;
}