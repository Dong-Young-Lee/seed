#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int s, n;
int input[10];
char lcd[23][130];

void print_lcd(int num) {
	int r = 2 * s + 3;
	int c = num * (s + 2);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c + num; j++) {
			printf("%c", lcd[i][j]);
		}
		printf("\n");
	}
}

void type_zero(int w_start, int w_end, int h, int m) {
	for (int i = w_start + 1; i < w_end - 1; i++) {
		lcd[0][i] = '-';
	}
}

void type_one(int w_start, int w_end, int h, int m) {
	for (int i = w_start + 1; i < w_end - 1; i++) {
		lcd[m][i] = '-';
	}
}

void type_two(int w_start, int w_end, int h, int m) {
	for (int i = w_start + 1; i < w_end - 1; i++) {
		lcd[h - 1][i] = '-';
	}
}

void type_three(int w_start, int w_end, int h, int m) {
	for (int i = 1; i < m; i++) {
		lcd[i][w_start] = '|';
	}
}

void type_four(int w_start, int w_end, int h, int m) {
	for (int i = 1; i < m; i++) {
		lcd[i][w_end - 1] = '|';
	}
}

void type_five(int w_start, int w_end, int h, int m) {
	for (int i = m + 1; i < h - 1; i++) {
		lcd[i][w_start] = '|';
	}
}

void type_six(int w_start, int w_end, int h, int m) {
	for (int i = m + 1; i < h - 1; i++) {
		lcd[i][w_end - 1] = '|';
	}
}

int main(void) {
	scanf("%d", &s);
	
	int in;
	int index = 0;
	while (scanf("%1d", &in) == 1) {
		input[index++] = in;
	}

	for (int i = 0; i < index; i++) {
		int width_start = i * (s + 2) + i;
		int width_end = width_start + s + 2;
		int height = 2 * s + 3;
		int middle = height / 2;

		if (input[i] == 0) {
			type_zero(width_start, width_end, height, middle);
			type_two(width_start, width_end, height, middle);
			type_three(width_start, width_end, height, middle);
			type_four(width_start, width_end, height, middle);
			type_five(width_start, width_end, height, middle);
			type_six(width_start, width_end, height, middle);
		}
		else if (input[i] == 1) {
			type_four(width_start, width_end, height, middle);
			type_six(width_start, width_end, height, middle);
		}
		else if (input[i] == 2) {
			type_zero(width_start, width_end, height, middle);
			type_one(width_start, width_end, height, middle);
			type_two(width_start, width_end, height, middle);
			type_four(width_start, width_end, height, middle);
			type_five(width_start, width_end, height, middle);
		}
		else if (input[i] == 3) {
			type_zero(width_start, width_end, height, middle);
			type_one(width_start, width_end, height, middle);
			type_two(width_start, width_end, height, middle);
			type_four(width_start, width_end, height, middle);
			type_six(width_start, width_end, height, middle);
		}
		else if (input[i] == 4) {
			type_one(width_start, width_end, height, middle);
			type_three(width_start, width_end, height, middle);
			type_four(width_start, width_end, height, middle);
			type_six(width_start, width_end, height, middle);
		}
		else if (input[i] == 5) {
			type_zero(width_start, width_end, height, middle);
			type_one(width_start, width_end, height, middle);
			type_two(width_start, width_end, height, middle);
			type_three(width_start, width_end, height, middle);
			type_six(width_start, width_end, height, middle);
		}
		else if (input[i] == 6) {
			type_zero(width_start, width_end, height, middle);
			type_one(width_start, width_end, height, middle);
			type_two(width_start, width_end, height, middle);
			type_three(width_start, width_end, height, middle);
			type_five(width_start, width_end, height, middle);
			type_six(width_start, width_end, height, middle);
		}
		else if (input[i] == 7) {
			type_zero(width_start, width_end, height, middle);
			type_four(width_start, width_end, height, middle);
			type_six(width_start, width_end, height, middle);
		}
		else if (input[i] == 8) {
			type_zero(width_start, width_end, height, middle);
			type_one(width_start, width_end, height, middle);
			type_two(width_start, width_end, height, middle);
			type_three(width_start, width_end, height, middle);
			type_four(width_start, width_end, height, middle);
			type_five(width_start, width_end, height, middle);
			type_six(width_start, width_end, height, middle);

		}
		else if (input[i] == 9) {
			type_zero(width_start, width_end, height, middle);
			type_one(width_start, width_end, height, middle);
			type_two(width_start, width_end, height, middle);
			type_three(width_start, width_end, height, middle);
			type_four(width_start, width_end, height, middle);
			type_six(width_start, width_end, height, middle);
		}

	}

	print_lcd(index);

	return 0;
}