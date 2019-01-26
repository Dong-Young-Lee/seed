#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int t;
	scanf("%d", &t);
	int a, b;
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}