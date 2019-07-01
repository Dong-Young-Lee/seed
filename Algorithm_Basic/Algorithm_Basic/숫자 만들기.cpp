#include <iostream>
using namespace std;

int tc, n;

int numbers[12];
int plus_num;
int minus_num;
int mul_num;
int div_num;

int ans_max;
int ans_min;
int ans_diff;

void dfs(int select, int result) {
	if (select == n - 1) {
		if (result > ans_max) {
			ans_max = result;
		}

		if (result < ans_min) {
			ans_min = result;
		}
		return;
	}

	if (plus_num > 0) {
		plus_num--;
		dfs(select + 1, result + numbers[select + 1]);
		plus_num++;
	}

	if (minus_num > 0) {
		minus_num--;
		dfs(select + 1, result - numbers[select + 1]);
		minus_num++;
	}

	if (mul_num > 0) {
		mul_num--;
		dfs(select + 1, result * numbers[select + 1]);
		mul_num++;
	}

	if (div_num > 0) {
		div_num--;
		dfs(select + 1, result / numbers[select + 1]);
		div_num++;
	}

}

int main(void) {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;

		cin >> plus_num;
		cin >> minus_num;
		cin >> mul_num;
		cin >> div_num;
		for (int i = 0; i < n; i++) {
			cin >> numbers[i];
		}

		ans_max = -100000000;
		ans_min = 100000000;
		
		dfs(0, numbers[0]);

		ans_diff = ans_max - ans_min;
		if (ans_diff < 0) ans_diff = -ans_diff;

		cout << '#' << t << ' ' << ans_diff << '\n';
	}
	return 0;
}