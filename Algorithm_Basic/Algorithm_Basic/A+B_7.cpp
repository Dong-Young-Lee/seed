#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void) {
	int t;
	scanf("%d", &t);
	int t_copy = t;
	int a, b;

	while (t--) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d\n", t_copy - t, a + b);
	}
	return 0;
}