#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

const int MAX = 20;
int n, k;
int sequence[MAX];
int result[MAX];
int numbers;

void print_res() {
	for (int i = 0; i < numbers - 1; i++) {
		printf("%d,", result[i]);
	}
	printf("%d\n", result[numbers - 1]);
}

void copy_res() {
	for (int i = 0; i < numbers; i++) {
		sequence[i] = result[i];
	}
}

int main(void) {
	scanf("%d %d\n", &n, &k);
	numbers = n;
	for (int i = 0; i < n; i++) {
		scanf("%d,", &sequence[i]);
	}
	
	for (int i = 0; i < n; i++) {
		result[i] = sequence[i];
	}
	
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < numbers - 1; j++) {
			result[j] = sequence[j + 1] - sequence[j];
		}
		numbers--;
		copy_res();
	}

	print_res();

	return 0;
}