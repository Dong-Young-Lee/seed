#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, ans;
vector<int> time(100001, -1);
queue<int> q;

void bfs() {
	q.push(n);
	time[n] = 0;
	
	while (!q.empty()) {
		int cur_pos = q.front();
		q.pop();
		
		int back_pos = cur_pos - 1;
		if (back_pos >= 0 && time[back_pos] == -1) {
			q.push(back_pos);
			time[back_pos] = time[cur_pos] + 1;
			if (back_pos == k) {
				ans = time[back_pos];
				return;
			}
		}

		int front_pos = cur_pos + 1;
		if (front_pos <= 100000 && time[front_pos] == -1) {
			q.push(front_pos);
			time[front_pos] = time[cur_pos] + 1;
			if (front_pos == k) {
				ans = time[front_pos];
				return;
			}
		}
		int tele_pos = cur_pos * 2;
		if (tele_pos <= 100000 && time[tele_pos] == -1) {
			q.push(tele_pos);
			time[tele_pos] = time[cur_pos] + 1;
			if (tele_pos == k) {
				ans = time[tele_pos];
				return;
			}
		}
	}
}

int main(void) {
	cin >> n >> k;
	bfs();
	cout << ans;

	return 0;
}