// 백준 해답 풀어보기!
#include <iostream>
using namespace std;


int n;
int status[20][20];

int start;
int link;
int ans = 2147483647;

int stored_numbers[11] = { -1 };
bool is_used[20];
int used_numbers;

void compare(int s, int l) {
	int cmp = s - l;

	if (cmp < 0) cmp *= -1;

	if (ans > cmp) {
		ans = cmp;
	}
}

void func() {
	// base condition
	if (used_numbers == n / 2) {
		start = 0;
		link = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (i == j) continue;
				if (is_used[i] && is_used[j]) {
					start += status[i][j];
					start += status[j][i];
				}
				if (!is_used[i] && !is_used[j]) {
					link += status[i][j];
					link += status[j][i];
				}
			}
		}

		compare(start, link);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!is_used[i] && i > stored_numbers[used_numbers]) {
			used_numbers++;
			stored_numbers[used_numbers] = i;
			is_used[i] = true;
			func();
			used_numbers--;
			is_used[i] = false;
		}
	}


}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> status[i][j];
		}
	}

	func();

	cout << ans;

	return 0;
}