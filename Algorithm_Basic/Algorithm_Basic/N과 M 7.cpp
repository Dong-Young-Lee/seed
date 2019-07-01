#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int input[7];

int numbers[7];
int used_numbers;

void func() {
	if (used_numbers == m) {
		for (int i = 0; i < m; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		numbers[used_numbers] = input[i];
		used_numbers++;
		func();
		used_numbers--;
	}
}

int main(void) {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	sort(input, input + n);

	func();

	return 0;
}