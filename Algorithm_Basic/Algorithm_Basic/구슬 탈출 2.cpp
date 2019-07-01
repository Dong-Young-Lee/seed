#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 10;

int n, m;
char map[10][10];
char map_copy[10][10];
vector<int> numbers;
int used_numbers;

int red_flag;
int blue_flag;
int ans = 11;

void copy_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = map_copy[i][j];
		}
	}
}

void tilt(int dir) {
	if (dir == 0) { // up
		for (int i = 1; i < m - 1; i++) { // i : column
			for (int j = 2; j < n - 1; j++) { // j : row
				if (map[j][i] == 'R' || map[j][i] == 'B') {
					int empty = 0;
					for (int k = 1; k < j; k++) {
						if (map[j - k][i] == '.') {
							empty++;
						}
						else if (map[j - k][i] == 'O') {
							if (map[j][i] == 'R') {
								red_flag = 1;
								map[j][i] = '.';
								break;
							}
							else {
								blue_flag = 1;
								map[j][i] = '.';
								break;
							}
						}
						else {
							break;
						}
					}

					if (empty > 0) {
						map[j - empty][i] = map[j][i];
						map[j][i] = '.';
					}

				}
			}
		}
	}
	else if (dir == 1) { // down
		for (int i = 1; i < m - 1; i++) { // i : column
			for (int j = n - 3; j > 0; j--) { // j : row
				if (map[j][i] == 'R' || map[j][i] == 'B') {
					int empty = 0;
					for (int k = 1; k < n - j - 1; k++) {
						if (map[j + k][i] == '.') {
							empty++;
						}
						else if (map[j + k][i] == 'O') {
							if (map[j][i] == 'R') {
								red_flag = 1;
								map[j][i] = '.';
								break;
							}
							else {
								blue_flag = 1;
								map[j][i] = '.';
								break;
							}
						}
						else {
							break;
						}
					}

					if (empty > 0) {
						map[j + empty][i] = map[j][i];
						map[j][i] = '.';
					}

				}
			}
		}
	}
	else if (dir == 2) { // left
		for (int i = 1; i < n - 1; i++) { // i : row
			for (int j = 2; j < m - 1; j++) { // j : column
				if (map[i][j] == 'R' || map[i][j] == 'B') {
					int empty = 0;
					for (int k = 1; k < j; k++) {
						if (map[i][j - k] == '.') {
							empty++;
						}
						else if (map[i][j - k] == 'O') {
							if (map[i][j] == 'R') {
								red_flag = 1;
								map[i][j] = '.';
								break;
							}
							else {
								blue_flag = 1;
								map[i][j] = '.';
								break;
							}
						}
						else {
							break;
						}
					}

					if (empty > 0) {
						map[i][j - empty] = map[i][j];
						map[i][j] = '.';
					}

				}
			}
		}
	}
	else { // right
	for (int i = 1; i < n - 1; i++) { // i : row
		for (int j = m - 3; j > 0; j--) { // j : column
			if (map[i][j] == 'R' || map[i][j] == 'B') {
				int empty = 0;
				for (int k = 1; k < m - j - 1; k++) {
					if (map[i][j + k] == '.') {
						empty++;
					}
					else if (map[i][j + k] == 'O') {
						if (map[i][j] == 'R') {
							red_flag = 1;
							map[i][j] = '.';
							break;
						}
						else {
							blue_flag = 1;
							map[i][j] = '.';
							break;
						}
					}
					else {
						break;
					}
				}

				if (empty > 0) {
					map[i][j + empty] = map[i][j];
					map[i][j] = '.';
				}

			}
		}
	}
	}
}

void func() {
	if (used_numbers == MAX) {		
		red_flag = 0;
		blue_flag = 0;

		copy_map();

		for (int i = 0; i < MAX; i++) {
			// tilt
			tilt(numbers[i]);
			if (red_flag && !blue_flag) {
				if (ans > i) {
					ans = i + 1;
					return;
				}
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (used_numbers > 0) {
			int i_reverse;
			if (i == 0) {
				i_reverse = 1;
			}
			else if (i == 1) {
				i_reverse = 0;
			}
			else if (i == 2) {
				i_reverse = 3;
			}
			else {
				i_reverse = 2;
			}
			if (i != numbers[used_numbers - 1] && i_reverse != numbers[used_numbers - 1]) {
				numbers.push_back(i);
				used_numbers++;
				func();
				numbers.pop_back();
				used_numbers--;
			}
		}
		else {
			numbers.push_back(i);
			used_numbers++;
			func();
			numbers.pop_back();
			used_numbers--;
		}
	}
}

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	scanf("%d %d", &n, &m);
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%c", &map_copy[i][j]);
		}
		getchar();
	}

	func();

	if (ans == 11) {
		printf("-1");
	}
	else {
		printf("%d", ans);
	}

	return 0;
}