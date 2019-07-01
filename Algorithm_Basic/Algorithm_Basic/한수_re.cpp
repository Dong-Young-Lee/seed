#include <iostream>
using namespace std;

int n;
int ans;

int find_digits(int number) {
	int ret = 0;
	while (number != 0) {
		ret++;
		number /= 10;
	}
	return ret;
}

int find_place_number(int number, int place) {
	int cnt = 0;
	while (number != 0) {
		cnt++;
		if (cnt == place) {
			return number %= 10;
		}
		number /= 10;
	}
}

int main(void) {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int digits = find_digits(i);
		if (digits >= 3) {
			int correct_flag = 1;
			int diff = find_place_number(i, 1) - find_place_number(i, 2);
			for (int j = 2; j < digits; j++) {
				int temp_diff = find_place_number(i, j) - find_place_number(i, j + 1);
				if (diff != temp_diff) {
					correct_flag = 0;
					break;
				}
			}
			if (correct_flag) {
				ans++;
			}
		}
		else {
			ans++;
		}
	}
	
	cout << ans;

	return 0;
}