#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

int n;
char op[10][10];
int numbers[10];
int used_numbers;

int ans_flag;

int is_valid() {
	for (int i = 0; i < used_numbers; i++) {
		int sum = 0;
		for (int j = i; j < used_numbers; j++) {
			sum += numbers[j];
			if (op[i][j] == '-') {
				if (sum >= 0) {
					return 0;
				}
			}
			else if (op[i][j] == '+') {
				if (sum <= 0) {
					return 0;
				}
			}
			else {
				if (sum != 0) {
					return 0;
				}
			}
		}
	}
	return 1;
}

void perm() {
	if (ans_flag) return;
	if (used_numbers == n) {
		for (int i = 0; i < n; i++) {
			printf("%d ", numbers[i]);
		}
		ans_flag = 1;
		return;
	}

	for (int i = -10; i <= 10; i++) {
		numbers[used_numbers] = i;
		used_numbers++;
		if (is_valid()) {
			perm();
			used_numbers--;
		}
		else {
			used_numbers--;
		}
	}
}

void print_op() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c ", op[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			scanf("%c", &op[i][j]);
		}
	}

	perm();
	return 0;
}