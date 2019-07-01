#include <iostream>
using namespace std;

const int MAX = 12;

int test_case, T;

int ticket[4];
int plan[MAX];

int numbers[MAX];
int used_numbers;

int ans;

void find_min_fee() {
	int sum = 0;
	int two_num = 0;
	for (int i = 0; i < 12; i++) {
		if (numbers[i] == 0) {
			sum += plan[i] * ticket[0];
		}
		else if (numbers[i] == 1) {
			sum += ticket[1];
		}
		else {
			two_num++;
		}
	}

	if (two_num > 0) {
		int two_ticket_num = 0;
		if (two_num / 3 > 0) {
			sum += ticket[2] * (two_num / 3);
			if (two_num % 3 > 0) {
				sum += ticket[2];
			}
		}
		else {
			sum += ticket[2];
		}
	}

	if (ans > sum) {
		ans = sum;
	}
}

void make_cases() {
	if (used_numbers == MAX) {
		/*
		for (int i = 0; i < MAX; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		*/
		find_min_fee();
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (i == 2) {
			if (used_numbers == MAX - 2) {
				for (int j = 0; j < 2; j++) {
					numbers[used_numbers] = i;
					used_numbers++;
				}
				make_cases();
				for (int j = 0; j < 2; j++) {
					used_numbers--;
				}
			}
			else if (used_numbers == MAX - 1) {
				numbers[used_numbers] = i;
				used_numbers++;
				make_cases();
				used_numbers--;
			}
			else {
				for (int j = 0; j < 3; j++) {
					numbers[used_numbers] = i;
					used_numbers++;
				}
				make_cases();
				for (int j = 0; j < 3; j++) {
					used_numbers--;
				}
			}

		}
		else {
			numbers[used_numbers] = i;
			used_numbers++;
			make_cases();
			used_numbers--;
		}
	}
}

int main(int argc, char** argv) {
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		for (int i = 0; i < 4; i++) {
			cin >> ticket[i];
		}
		for (int i = 0; i < 12; i++) {
			cin >> plan[i];
		}

		ans = ticket[3];
		make_cases();

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}