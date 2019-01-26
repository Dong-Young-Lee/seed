#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void) {
	int n;
	scanf("%d", &n);
	int sum = 0;
	while (n--) {
		int input;
		scanf("%1d", &input);
		while (getchar() != '\n');
		sum += input;
	}
	printf("%d\n", sum);
	return 0;
}