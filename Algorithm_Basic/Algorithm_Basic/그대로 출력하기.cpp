#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main() {
	char s[110];
	while (scanf(" %[^\n]", s) == 1) {
		printf("%s\n", s);
	}
	return 0;
}
