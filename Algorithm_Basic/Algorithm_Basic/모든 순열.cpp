#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector<int> input(n);
	for (int i = 0; i < n; i++) {
		input[i] = i + 1;
	}

	do {
		for (int i = 0; i < n; i++) {
			cout << input[i] << ' ';
		}
		cout << '\n';
	} while (next_permutation(input.begin(), input.end()));
	
	return 0;
}