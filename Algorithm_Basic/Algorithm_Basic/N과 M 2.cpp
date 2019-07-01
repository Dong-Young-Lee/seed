#include <iostream>
#include <vector>
using namespace std;

bool isused[9];
vector<int> numbers;
int used_numbers;

int n, m;

void func() {
	// base condition
	if (used_numbers == m) {
		for (int i = 1; i <= m; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			if (i > numbers[used_numbers]) {
				isused[i] = true;
				numbers.push_back(i);
				used_numbers++;
				func();
				isused[i] = false;
				numbers.pop_back();
				used_numbers--;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;

	numbers.push_back(0);
	func();

	return 0;
}