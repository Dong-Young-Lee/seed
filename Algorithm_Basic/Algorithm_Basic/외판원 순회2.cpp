#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	vector< vector<int> > input(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];
		}
	}
	vector<int> route(n);
	for (int i = 0; i < n; i++) {
		route[i] = i;
	}
	int min = numeric_limits<int>::max();
	int dist;
	int flag = 0;
	do {
		flag = 0;
		dist = 0;
		for (int i = 0; i < n - 1; i++) {
			int temp = input[route[i]][route[i + 1]];
			if (temp == 0) {
				flag = 1;
				break;
			}
			dist += temp;
		}
		int temp = input[route[n - 1]][route[0]];
		if (temp == 0) flag = 1;
		if (flag == 1) continue;
		dist += temp;
		if (min > dist) {
			min = dist;
		}
	} while (next_permutation(route.begin(), route.end()));

	cout << min;

	return 0;
}