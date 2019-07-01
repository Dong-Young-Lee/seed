#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
}info;

const int MAX = 20;

int test_case, T;
int n, m;

info house[MAX * MAX];
int total_house;

int ans;

void find_ans(int row, int col, int dist) {

	int house_num = 0;
	int fee = (dist + 1) * (dist + 1) + dist * dist;

	for (int i = 0; i < total_house; i++) {
		int row_dist = row - house[i].row;
		if (row_dist < 0) row_dist = -row_dist;
		int col_dist = col - house[i].col;
		if (col_dist < 0) col_dist = -col_dist;
		int sum_dist = row_dist + col_dist;
		if (sum_dist <= dist) {
			house_num++;
		}
	}

	int res = house_num * m - fee;
	if (res >= 0) {
		if (ans < house_num) {
			ans = house_num;
		}
	}
}

void solve() {
	int distance = 2 * n - 2;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < distance; k++) {
				find_ans(i, j, k);
			}
		}
	}
	
}

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		ans = 0;
		total_house = 0;

		cin >> n >> m;
		int input;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> input;
				if (input == 1) {
					house[total_house++] = { i, j };
				}
			}
		}

		solve();
		
		cout << "#" << test_case << " " << ans << "\n";
	}

	return 0;
}

