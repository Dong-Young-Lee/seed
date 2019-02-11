#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	if (prev_permutation(input.begin(), input.end())) {
		for (int i = 0; i < n; i++) {
			cout << input[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
	return 0;
}