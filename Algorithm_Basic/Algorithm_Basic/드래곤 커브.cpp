#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int n;
vector< vector<bool> > matrix(101, vector<bool>(101, false));

int d_r[4] = { 0, -1, 0, 1 };
int d_c[4] = { 1, 0, -1, 0 };

int main(void) {
	cin >> n;
	while (n--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		deque<int> dq;
		queue<int> q;
		
		int cnt = 1;
		dq.push_back(d);
		while (g--) {
			for (int i = 0; i < cnt; i++) {
				int next_d = dq.front() + 1;
				next_d %= 4;
				q.push(next_d);
				dq.push_back(dq.front());
				dq.pop_front();
			}
			while (!q.empty()) {
				dq.push_front(q.front());
				q.pop();
			}
			cnt *= 2;
		}

		int next_row = y;
		int next_col = x;
		matrix[next_row][next_col] = true;
		while (!dq.empty()) {
			int next_d = dq.back();
			dq.pop_back();
			next_row += d_r[next_d];
			next_col += d_c[next_d];
			matrix[next_row][next_col] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (matrix[i][j] && matrix[i + 1][j] && matrix[i][j + 1] && matrix[i + 1][j + 1]) {
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}