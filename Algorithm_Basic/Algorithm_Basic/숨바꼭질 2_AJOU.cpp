#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;
int map[MAX];
int n, k;
queue<int> q;

int ans;
int cnt;

void bfs() {
	int time = 1;
	map[n] = time;
	q.push(n);

	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur_pos = q.front();
			q.pop();

			if (cur_pos == k) {
				ans = time - 1;
				cnt++;
			}

			int left_pos = cur_pos - 1;
			if (left_pos >= 0 && (map[left_pos] == 0 || map[left_pos] == time)) {
				map[left_pos] = time;
				q.push(left_pos);
			}

			int right_pos = cur_pos + 1;
			if (right_pos < MAX && (map[right_pos] == 0 || map[right_pos] == time)) {
				map[right_pos] = time;
				q.push(right_pos);
			}

			int tele_pos = cur_pos * 2;
			if (tele_pos < MAX && (map[tele_pos] == 0 || map[tele_pos] == time)) {
				map[tele_pos] = time;
				q.push(tele_pos);
			}
		}
		time++;
		if (ans != 0) return;
	}
}

int main(void) {
	cin >> n >> k;
	if (n == k) {
		cout << 0 << '\n' << 1;
	}
	else {
		bfs();
		cout << ans << '\n' << cnt;
	}
	return 0;
}