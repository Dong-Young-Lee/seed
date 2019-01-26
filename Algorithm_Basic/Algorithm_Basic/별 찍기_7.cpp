#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k < (i * 2) + 1; k++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n - 2; i > -1; i--) {
		for (int j = 0; j < n - i - 1; j++) {
			printf(" ");
		}
		for (int k = 0; k < (i * 2) + 1; k++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}