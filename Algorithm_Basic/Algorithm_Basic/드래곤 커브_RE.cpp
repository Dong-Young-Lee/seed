#include <iostream>
#include <queue>
#include <deque>
using namespace std;

const int MAX = 101;
int map[MAX][MAX];

int n, x, y, d, g;

int d_r[4] = { 0, -1, 0, 1 };
int d_c[4] = { 1, 0, -1, 0 };

deque<int> dq;
queue<int> q;

int ans;

void make_curve() {
	dq.push_back(d);
	while (g--) {
		int dq_size = dq.size();
		while (dq_size--) {
			int next_dir = (dq.front() + 1) % 4;
			q.push(next_dir);
			dq.push_back(dq.front());
			dq.pop_front();
		}
		while (!q.empty()) {
			dq.push_front(q.front());
			q.pop();
		}
	}

	map[y][x] = 1;
	while (!dq.empty()) {
		int dir = dq.back();
		dq.pop_back();
		y += d_r[dir];
		x += d_c[dir];
		map[y][x] = 1;
	}
}

int find_ans() {
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = 0; j < MAX - 1; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				ans++;
			}
		}
	}
	return ans;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		make_curve();
	}
	
	cout << find_ans();

	return 0;
}