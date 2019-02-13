#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, k;
// time[i] : i번째 위치로 가는 가장 빠른 시간
vector<int> time(100001, -1);

void bfs() { 
	deque<int> d;
	d.push_back(n);
	time[n] = 0;
	
	while (!d.empty()) {
		int cur_pos = d.front();
		d.pop_front();

		int next_teleport_pos = cur_pos * 2;
		if (next_teleport_pos <= 100000 && time[next_teleport_pos] == -1) {
			d.push_front(next_teleport_pos);
			time[next_teleport_pos] = time[cur_pos];
			if (next_teleport_pos == k) {
				return;
			}
		}

		int next_back_pos = cur_pos - 1;
		if (next_back_pos >= 0 && time[next_back_pos] == -1) {
			d.push_back(next_back_pos);
			time[next_back_pos] = time[cur_pos] + 1;
			if (next_back_pos == k) {
				return;
			}
		}

		int next_front_pos = cur_pos + 1;
		if (next_front_pos <= 100000 && time[next_front_pos] == -1) {
			d.push_back(next_front_pos);
			time[next_front_pos] = time[cur_pos] + 1;
			if (next_front_pos == k) {
				return;
			}
		}

	}
}

int main(void) {
	cin >> n >> k;
	bfs();
	cout << time[k];

	return 0;
}