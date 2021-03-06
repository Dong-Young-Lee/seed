#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int input[8];

int numbers[8];
int visited[8];
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
		if (!visited[i]) {
			visited[i] = 1;
			numbers[used_numbers] = input[i];
			used_numbers++;
			func();
			visited[i] = 0;
			used_numbers--;
		}
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