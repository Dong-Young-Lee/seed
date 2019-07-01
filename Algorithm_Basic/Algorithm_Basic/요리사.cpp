#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

const int MAX = 16;

int n;
vector< vector<int> > table(16, vector<int>(MAX));

vector<bool> isused(MAX);
vector<int> stored_numbers;
int used_numbers;
int ans;

void func() {
	// base condition
	if (used_numbers == n / 2 - 1) {
		vector<bool> check(n);
		for (int i = 0; i < n / 2; i++) {
			check[stored_numbers[i]] = true;
		}
		vector<int> unstored_numbers;
		for (int i = 0; i < n; i++) {
			if (!check[i]) {
				unstored_numbers.push_back(i);
			}
		}

		int sum_a = 0;
		int sum_b = 0;

		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				sum_a += table[stored_numbers[i]][stored_numbers[j]];
				sum_a += table[stored_numbers[j]][stored_numbers[i]];
				sum_b += table[unstored_numbers[i]][unstored_numbers[j]];
				sum_b += table[unstored_numbers[j]][unstored_numbers[i]];
			}
		}

		int diff = sum_a - sum_b;
		if (diff < 0) {
			diff = -diff;
		}

		if (ans > diff) {
			ans = diff;
		}

		return;
	}

	for (int i = 1; i < n; i++) {
		if (!isused[i] && i > stored_numbers[used_numbers]) {
			isused[i] = true;
			stored_numbers.push_back(i);
			used_numbers++;
			func();
			isused[i] = false;
			stored_numbers.pop_back();
			used_numbers--;
		}
	}
}

int main(void) {
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> table[i][j];
			}
		}

		for (int i = 0; i < MAX; i++) {
			isused[i] = false;
		}

		while (!stored_numbers.empty()) {
			stored_numbers.pop_back();
		}

		ans = numeric_limits<int>::max();
		stored_numbers.push_back(0);
		func();
		cout << '#' << t << ' ' << ans << '\n';
	}
	return 0;
}