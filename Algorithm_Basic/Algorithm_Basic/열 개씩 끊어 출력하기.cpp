#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void) {
	char str[111];
	while (scanf("%10s", str) == 1) {
		printf("%s\n", str);
	}
	return 0;
}