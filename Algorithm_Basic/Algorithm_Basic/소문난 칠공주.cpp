#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 5;
char map[MAX][MAX];
int check_map[MAX][MAX];
int visited[MAX][MAX];

int is_used[25];
int numbers[7];
int used_numbers;
int som, yun;

int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, 1, 0, -1 };

int len;
int ans;

//void print_map() {
//	for (int i = 0; i < MAX; i++) {
//		for (int j = 0; j < MAX; j++) {
//			printf("%d ", check_map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

void dfs(int row, int col) {
	len++;
	if (len == 7) {
		ans++;
		return;
	}

	visited[row][col] = 1;
	
	for (int i = 0; i < 4; i++) {
		int next_row = row + d_r[i];
		int next_col = col + d_c[i];
		if (next_row >= 0 && next_row < MAX && next_col >= 0 && next_col < MAX) {
			if (visited[next_row][next_col] == 0 && check_map[next_row][next_col] == 1) {
				visited[next_row][next_col] = 1;
				dfs(next_row, next_col);
			}
		}
	}
}

int judge_who(int index) {
	int row = index / MAX;
	int col = index % MAX;
	if (map[row][col] == 'S') {
		return 1;
	}
	else {
		return 0;
	}
}

void modify_map(int draw) {
	if (draw == 1) {
		for (int i = 0; i < 7; i++) {
			int row = numbers[i] / MAX;
			int col = numbers[i] % MAX;
			check_map[row][col] = 1;
		}
	}
	else {
		for (int i = 0; i < 7; i++) {
			int row = numbers[i] / MAX;
			int col = numbers[i] % MAX;
			check_map[row][col] = 0;
			visited[row][col] = 0;
		}
	}
}

void comb() {
	if (yun >= 4) {
		return;
	}

	if (used_numbers == 7) {
		modify_map(1);
		len = 0;
		dfs(numbers[0] / MAX, numbers[0] % MAX);
		modify_map(0);
		return;
	}

	for (int i = 0; i < 25; i++) {
		if (used_numbers > 0) {
			if (i > numbers[used_numbers - 1]) {
				if (is_used[i] == 0) {
					int who = judge_who(i);
					if (who) {
						som++;
					}
					else {
						yun++;
					}
					is_used[i] = 1;
					numbers[used_numbers] = i;
					used_numbers++;
					comb();
					used_numbers--;
					is_used[i] = 0;
					if (who) {
						som--;
					}
					else {
						yun--;
					}
				}
			}
		}
		else {
			if (is_used[i] == 0) {
				int who = judge_who(i);
				if (who) {
					som++;
				}
				else {
					yun++;
				}
				is_used[i] = 1;
				numbers[used_numbers] = i;
				used_numbers++;
				comb();
				used_numbers--;
				is_used[i] = 0;
				if (who) {
					som--;
				}
				else {
					yun--;
				}
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			scanf("%c\n", &map[i][j]);
		}
	}

	comb();

	printf("%d\n", ans);
	return 0;
}