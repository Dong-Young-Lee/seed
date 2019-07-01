#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

const int VORTEX_SIZE = 10001;
const int BASE = 5000;
int vortex[VORTEX_SIZE][VORTEX_SIZE];


// 북 서 남 동
int d_r[4] = { -1, 0, 1, 0 };
int d_c[4] = { 0, -1, 0, 1 };

int max_number;
int max_digits;

int find_digits(int number) {
	int digits = 1;
	int divisor = 10;
	while (number / divisor) {
		divisor *= 10;
		digits++;
	}
	return digits;
}

int main(void) {
	int r1, c1, r2, c2;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

	vortex[BASE][BASE] = 1;
	vortex[BASE][BASE + 1] = 2;

	int cnt = 100000000;
	int cur_row = BASE;
	int cur_col = BASE + 1;
	int direction = 0;
	while (cnt--) {
		int prev_num = vortex[cur_row][cur_col];
		int left = (direction + 1) % 4;
		int left_row = cur_row + d_r[left];
		int left_col = cur_col + d_c[left];
		if (vortex[left_row][left_col] == 0) { // 왼쪽에 없으면
			cur_row = left_row;
			cur_col = left_col;
			vortex[cur_row][cur_col] = prev_num + 1;
			direction = left;
		}
		else { // 왼쪽에 있으면
			cur_row += d_r[direction];
			cur_col += d_c[direction];
			vortex[cur_row][cur_col] = prev_num + 1;
		}
	}

	for (int i = BASE + r1; i <= BASE + r2; i++) {
		for (int j = BASE + c1; j <= BASE + c2; j++) {
			if (max_number < vortex[i][j]) {
				max_number = vortex[i][j];
			}
		}
	}
	max_digits = find_digits(max_number);

	for (int i = BASE + r1; i <= BASE + r2; i++) {
		for (int j = BASE + c1; j <= BASE + c2; j++) {
			int diff_digits = max_digits - find_digits(vortex[i][j]);
			for (int i = 0; i < diff_digits; i++) {
				printf(" ");
			}
			printf("%d ", vortex[i][j]);
		}
		printf("\n");
	}

	return 0;
}