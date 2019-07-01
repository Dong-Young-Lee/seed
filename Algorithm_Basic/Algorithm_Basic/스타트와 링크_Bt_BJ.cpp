// 나중에 다시
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector< vector<int> > matrix(20, vector<int>(20));
int n;

vector<int> start;
vector<int> link;

int func(int index) {
	// base condition
	if (index == n) {
		if (start.size() != n / 2) return -1;
		if (link.size() != n / 2) return -1;

		int start_score = 0;
		int link_score = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j)continue;
				start_score += matrix[start[i]][start[j]];
				link_score += matrix[link[i]][link[j]];
			}
		}
		int diff = start_score - link_score;
		if (diff < 0) diff = -diff;
		return diff;
	}

	// Backtracking
	if (start.size() > n / 2) return -1;
	if (link.size() > n / 2) return -1;

	int ans = -1;
	start.push_back(index);
	int temp_1 = func(index + 1);
	if (ans == -1 || (temp_1 != -1 && ans > temp_1)) {
		ans = temp_1;
	}
	start.pop_back();

	link.push_back(index);
	int temp_2 = func(index + 1);
	if (ans == -1 || (temp_2 != -1 && ans > temp_2)) {
		ans = temp_2;
	}
	link.pop_back();

	return ans;
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << func(0);



	return 0;
}