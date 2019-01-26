#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void) {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		int j = 0;
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (int k = 0; k < ((n-1) * 2) - ((j * 2) -1); k++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = n-2; i > -1; i--) {
		int j = 0;
		for (j = 0; j < i; j++) {
			printf(" ");
		}
		for (int k = 0; k < ((n-1) * 2) - ((j * 2) -1); k++) {
			printf("*");
		}
		printf("\n");
	}
	
	return 0;

}