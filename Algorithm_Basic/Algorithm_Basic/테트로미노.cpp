/*

< Brute Force >

회전 및 대칭 포함 경우의 수
2, 1, 8, 4, 4 : 19가지

모든 경우의 수를 비교해서 구한다.

< Time Complexity >

n * m * 19 : 500 * 500 * 20 = 5,000,000 (5백만)

*/
#include <iostream>
#include <vector>
using namespace std;

vector< vector<int> > input(500, vector<int>(500));

int main(void) {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j < m - 3) { // 1-1
				if (max < input[i][j] + input[i][j + 1] + input[i][j + 2] + input[i][j + 3]) {
					max = input[i][j] + input[i][j + 1] + input[i][j + 2] + input[i][j + 3];
				}
			}
			if (i < n - 3) { // 1-2
				if (max < input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i + 3][j]) {
					max = input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i + 3][j];
				}
			}
			if (i < n - 1 && j < m - 1) { // 2-1
				if (max < input[i][j] + input[i + 1][j] + input[i][j + 1] + input[i + 1][j + 1]) {
					max = input[i][j] + input[i + 1][j] + input[i][j + 1] + input[i + 1][j + 1];
				}
			}
			if (i < n - 2 && j < m - 1) { // 3-1
				if (max < input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i + 2][j + 1]) {
					max = input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i + 2][j + 1];
				}
			}
			if (i < n - 1 && j < m - 2) { // 3-2
				if (max < input[i][j] + input[i + 1][j] + input[i][j + 1] + input[i][j + 2]) {
					max = input[i][j] + input[i + 1][j] + input[i][j + 1] + input[i][j + 2];
				}
			}
			if (i < n - 2 && j < m - 1) { // 3-3
				if (max < input[i][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i + 2][j + 1]) {
					max = input[i][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i + 2][j + 1];
				}
			}
			if (i < n - 1 && j < m - 2) { // 3-4
				if (max < input[i + 1][j] + input[i + 1][j + 1] + input[i + 1][j + 2] + input[i][j + 2]) {
					max = input[i + 1][j] + input[i + 1][j + 1] + input[i + 1][j + 2] + input[i][j + 2];
				}
			}
			if (i < n - 2 && j < m - 1) { // 3-5
				if (max < input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i][j + 1]) {
					max = input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i][j + 1];
				}
			}
			if (i < n - 1 && j < m - 2) { // 3-6
				if (max < input[i][j] + input[i + 1][j] + input[i + 1][j + 1] + input[i + 1][j + 2]) {
					max = input[i][j] + input[i + 1][j] + input[i + 1][j + 1] + input[i + 1][j + 2];
				}
			}
			if (i < n - 2 && j < m - 1) { // 3-7
				if (max < input[i + 2][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i + 2][j + 1]) {
					max = input[i + 2][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i + 2][j + 1];
				}
			}
			if (i < n - 1 && j < m - 2) { // 3-8
				if (max < input[i][j] + input[i][j + 1] + input[i][j + 2] + input[i + 1][j + 2]) {
					max = input[i][j] + input[i][j + 1] + input[i][j + 2] + input[i + 1][j + 2];
				}
			}
			if (i < n - 2 && j < m - 1) { // 4-1
				if (max < input[i][j] + input[i + 1][j] + input[i + 1][j + 1] + input[i + 2][j + 1]) {
					max = input[i][j] + input[i + 1][j] + input[i + 1][j + 1] + input[i + 2][j + 1];
				}
			}
			if (i < n - 2 && j < m - 1) { // 4-2
				if (max < input[i + 1][j] + input[i + 2][j] + input[i][j + 1] + input[i + 1][j + 1]) {
					max = input[i + 1][j] + input[i + 2][j] + input[i][j + 1] + input[i + 1][j + 1];
				}
			}
			if (i < n - 1 && j < m - 2) { // 4-3
				if (max < input[i + 1][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i][j + 2]) {
					max = input[i + 1][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i][j + 2];
				}
			}
			if (i < n - 1 && j < m - 2) { // 4-4
				if (max < input[i][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i + 1][j + 2]) {
					max = input[i][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i + 1][j + 2];
				}
			}
			if (i < n - 1 && j < m - 2) { // 5-1
				if (max < input[i][j] + input[i][j + 1] + input[i][j + 2] + input[i + 1][j + 1]) {
					max = input[i][j] + input[i][j + 1] + input[i][j + 2] + input[i + 1][j + 1];
				}
			}
			if (i < n - 1 && j < m - 2) { // 5-2
				if (max < input[i + 1][j] + input[i + 1][j + 1] + input[i + 1][j + 2] + input[i][j + 1]) {
					max = input[i + 1][j] + input[i + 1][j + 1] + input[i + 1][j + 2] + input[i][j + 1];
				}
			}
			if (i < n - 2 && j < m - 1) { // 5-3
				if (max < input[i + 1][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i + 2][j + 1]) {
					max = input[i + 1][j] + input[i][j + 1] + input[i + 1][j + 1] + input[i + 2][j + 1];
				}
			}
			if (i < n - 2 && j < m - 1) { // 5-4
				if (max < input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i + 1][j + 1]) {
					max = input[i][j] + input[i + 1][j] + input[i + 2][j] + input[i + 1][j + 1];
				}
			}
		}
	}
	cout << max;
	return 0;
}