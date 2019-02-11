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
	sort(input.begin(), input.end());
	int max = numeric_limits<int>::min();
	int sum;
	do {
		sum = 0;
		for (int i = 2; i <= n; i++) {
			int temp = input[i - 2] - input[i - 1];
			if (temp < 0) {
				temp *= -1;
			}
			sum += temp;
		}
		if (max < sum) {
			max = sum;
		}

	} while (next_permutation(input.begin(), input.end()));

	cout << max;

	return 0;
}