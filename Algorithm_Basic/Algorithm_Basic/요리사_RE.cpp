#include <iostream>
using namespace std;

const int MAX = 16;

int test_case, T;
int n;
int half_n;

int map[MAX][MAX];

int is_used[MAX];
int numbers[MAX / 2];
int used_numbers;

int numbers_2[MAX / 2];

int ans;

void calculation() {
	int food_one = 0;
	int food_two = 0;

	for (int i = 0; i < half_n - 1; i++) {
		for (int j = i + 1; j < half_n; j++) {
			food_one += (map[numbers[i]][numbers[j]] + map[numbers[j]][numbers[i]]);
			food_two += (map[numbers_2[i]][numbers_2[j]] + map[numbers_2[j]][numbers_2[i]]);
		}
	}
	
	int diff = food_one - food_two;
	if (diff < 0) diff = -diff;
	if (ans > diff) {
		ans = diff;
	}
}

void combination_half() {
	if (used_numbers == half_n - 1) {
		int index = 0;
		for (int i = 1; i < n; i++) {
			if (is_used[i] == 0) {
				numbers_2[index] = i;
				index++;
			}
		}
		
		calculation();

		return;
	}

	for (int i = 1; i < n; i++) {
		if (used_numbers > 0) {
			if (i > numbers[used_numbers - 1]) {
				if (is_used[i] == 0) {
					is_used[i] = 1;
					numbers[used_numbers] = i;
					used_numbers++;
					combination_half();
					used_numbers--;
					is_used[i] = 0;
				}
			}
		}
		else {
			if (is_used[i] == 0) {
				is_used[i] = 1;
				numbers[used_numbers] = i;
				used_numbers++;
				combination_half();
				used_numbers--;
				is_used[i] = 0;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		is_used[0] = 1;
		ans = 2147483647;
		cin >> n;
		half_n = n / 2;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		combination_half();

		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}