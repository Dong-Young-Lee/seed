#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void) {
	int t;
	scanf("%d", &t);
	int a, b;
	char comma;

	while (t--) {
		scanf("%d %c %d", &a, &comma, &b);
		printf("%d\n", a + b);
	}
	return 0;
}