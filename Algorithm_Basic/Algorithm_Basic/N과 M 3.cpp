#include <iostream>
#include <vector>
using namespace std;

int n, m;

vector<int> numbers;
int used_numbers;

void func() {
	// base condition
	if (used_numbers == m) {
		for (int i = 0; i < m; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		numbers.push_back(i);
		used_numbers++;
		func();
		numbers.pop_back();
		used_numbers--;
	}
}

int main(void) {
	cin >> n >> m;
	func();

	return 0;
}