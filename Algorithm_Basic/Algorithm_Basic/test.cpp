#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int main(void) {
	char str[100];
	for (int i = 0; i < 2; i++) {
		scanf(" %[^\n]", str);
		printf("%s\n", str);
	}
	return 0;
}