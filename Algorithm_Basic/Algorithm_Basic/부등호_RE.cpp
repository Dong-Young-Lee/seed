#include <iostream>
using namespace std;

const int MAX = 9;

int n;
int input[MAX];

int is_used[MAX + 1];
int numbers[MAX + 1];
int used_numbers;

long long min_ans = 100000000000;
long long max_ans = 0;

int min_ans_arr[MAX + 1];
int max_ans_arr[MAX + 1];

void solve() {
	if (used_numbers == n + 1) {
		/*
		for (int i = 0; i < used_numbers; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		*/
		long long num = 0;
		long long mul = 1;
		for (int i = 0; i < used_numbers; i++) {
			num += numbers[used_numbers - 1 - i] * mul;
			mul *= 10;
		}

		if (min_ans > num) {
			min_ans = num;
			for (int i = 0; i < used_numbers; i++) {
				min_ans_arr[i] = numbers[i];
			}
		}
		if (max_ans < num) {
			max_ans = num;
			for (int i = 0; i < used_numbers; i++) {
				max_ans_arr[i] = numbers[i];
			}
		}

		return;
	}

	for (int i = 0; i < MAX + 1; i++) {
		if (is_used[i] == 0) {
			if (used_numbers > 0) {
				if (input[used_numbers - 1] == 0) {
					if (i > numbers[used_numbers - 1]) {
						is_used[i] = 1;
						numbers[used_numbers] = i;
						used_numbers++;
						solve();
						is_used[i] = 0;
						used_numbers--;
					}
				}
				else {
					if (i < numbers[used_numbers - 1]) {
						is_used[i] = 1;
						numbers[used_numbers] = i;
						used_numbers++;
						solve();
						is_used[i] = 0;
						used_numbers--;
					}
				}
			}
			else {
				is_used[i] = 1;
				numbers[used_numbers] = i;
				used_numbers++;
				solve();
				is_used[i] = 0;
				used_numbers--;
			}
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '<') {
			input[i] = 0;
		}
		else {
			input[i] = 1;
		}
	}

	solve();

	for (int i = 0; i < n + 1; i++) {
		cout << max_ans_arr[i];
	}
	cout << '\n';
	for (int i = 0; i < n + 1; i++) {
		cout << min_ans_arr[i];
	}
	return 0;
}
