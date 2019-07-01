#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, x, y;
int main(void) {
	cin >> a >> b >> c >> x >> y;

	int ans_1 = a * x + b * y;
	int ans_2 = 0;
	int ans_3;

	int max_val;
	int min_val;
	int remain_val;
	if (x >= y) {
		max_val = x;
		min_val = y;
		remain_val = x - y;
		ans_2 += a * remain_val;
	}
	else {
		max_val = y;
		min_val = x;
		remain_val = y - x;
		ans_2 += b * remain_val;
	}

	ans_2 += 2 * c * min_val;
	ans_3 = 2 * c * max_val;

	cout << min(ans_1, min(ans_2, ans_3));

	return 0;
}