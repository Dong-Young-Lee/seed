#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;
int map[MAX];
int n, k;
queue<int> q;

int ans;

void bfs() {
	map[n] = 1;
	q.push(n);

	while(!q.empty()) {
		if (ans != 0) return;

		int cur_pos = q.front();
		q.pop();

		if (cur_pos == k) {
			ans = map[cur_pos] - 1;
			cout << ans;
			return;
		}

		int left_pos = cur_pos - 1;
		if (left_pos >= 0 && map[left_pos] == 0) {
			map[left_pos] = map[cur_pos] + 1;
			q.push(left_pos);
		}
		
		int right_pos = cur_pos + 1;
		if (right_pos < MAX && map[right_pos] == 0) {
			map[right_pos] = map[cur_pos] + 1;
			q.push(right_pos);
		}

		int tele_pos = cur_pos * 2;
		if (tele_pos < MAX && map[tele_pos] == 0) {
			map[tele_pos] = map[cur_pos] + 1;
			q.push(tele_pos);
		}
	}
}

int main(void) {
	cin >> n >> k;
	if (n == k) {
		cout << 0;
	}
	else {
		bfs();
	}
	return 0;
}