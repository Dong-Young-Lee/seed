#include <iostream>
using namespace std;

const int MAX = 8;

int n;
int is_used[MAX];
int numbers[MAX];
int used_numbers;

void solve() {
	if (used_numbers == n) {
		for (int i = 0; i < n; i++) {
			cout << numbers[i] + 1 << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (is_used[i] == 0) {
			is_used[i] = 1;
			numbers[used_numbers] = i;
			used_numbers++;
			solve();
			is_used[i] = 0;
			used_numbers--;
		}
	}
}

int main(void) {
	cin >> n;
	solve();
	return 0;
}