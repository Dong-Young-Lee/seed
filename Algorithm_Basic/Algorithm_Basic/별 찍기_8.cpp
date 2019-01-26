#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void) {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n + 1; i++) {
		int j = 0;
		for (j = 0; j < i; j++) {
			printf("*");
		}
		for (int k = 0; k < (n*2) - (j * 2); k++) {
			printf(" ");
		}
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n-1; i > 0; i--) {
		int j = 0;
		for (j = 0; j < i; j++) {
			printf("*");
		}
		for (int k = 0; k < (n * 2) - (j * 2); k++) {
			printf(" ");
		}
		for (j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;

}