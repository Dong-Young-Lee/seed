#include <iostream>
#include <deque>
#include <memory.h>
using namespace std;

const int MAX = 100001;

int map[MAX];
int n, k;
deque<int> dq;

int ans;

void bfs() {
	dq.push_back(n);
	map[n] = 0;

	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop_front();

		if (cur == k) {
			ans = map[cur];
			return;
		}

		int tele_pos = cur * 2;
		if (tele_pos < MAX) {
			if (map[tele_pos] == -1) {
				map[tele_pos] = map[cur];
				dq.push_front(tele_pos);
			}
		}

		int left_pos = cur - 1;
		if (left_pos >= 0) {
			if (map[left_pos] == -1) {
				map[left_pos] = map[cur] + 1;
				dq.push_back(left_pos);
			}
		}

		int right_pos = cur + 1;
		if (right_pos < MAX) {
			if (map[right_pos] == -1) {
				map[right_pos] = map[cur] + 1;
				dq.push_back(right_pos);
			}
		}
	}
}

int main(void) {
	cin >> n >> k;
	memset(map, -1, sizeof(map));
	bfs();
	cout << ans;

	return 0;
}