#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void) {
	int t;
	scanf("%d", &t);
	int a, b;
	int n = 1;
	while (t--) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", n++, a, b, a + b);
	}
	return 0;
}