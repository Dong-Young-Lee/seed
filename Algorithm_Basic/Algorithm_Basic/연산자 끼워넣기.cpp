/*
1 : +
2 : -
3 : *
4 : /
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	vector<int> op_num(4);
	for (int i = 0; i < 4; i++) {
		cin >> op_num[i];
	}
	vector<int> op(n - 1, 0);
	for (int i = 0; i < n - 1; i++) {
		if (op_num[0] > 0) {
			op[i] = 1;
			op_num[0]--;
			continue;
		}
		else if (op_num[1] > 0) {
			op[i] = 2;
			op_num[1] --;
		}
		else if (op_num[2] > 0) {
			op[i] = 3;
			op_num[2] --;
		}
		else if (op_num[3] > 0) {
			op[i] = 4;
			op_num[3] --;
		}
	}

	int min = numeric_limits<int>::max();
	int max = numeric_limits<int>::min();

	do {
		
		int res = input[0];
		for (int i = 0; i < n - 1; i++) {
			if (op[i] == 1) {
				res += input[i + 1];
			}
			else if (op[i] == 2) {
				res -= input[i + 1];
			}
			else if (op[i] == 3) {
				res *= input[i + 1];
			}
			else if (op[i] == 4) {
				res /= input[i + 1];
			}
		}

		if (min > res) {
			min = res;
		}
		if (max < res) {
			max = res;
		}
	} while (next_permutation(op.begin(), op.end()));

	cout << max << '\n' << min;

	return 0;
}