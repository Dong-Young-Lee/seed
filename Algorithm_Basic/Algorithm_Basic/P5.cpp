#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int c, b, ans;
vector<int> time_vec(200001, -1);
vector<int> brown(200001, -1);
queue<int> q;

void brown_init(int b_pos) {
	int t = 0;
	int dist = 1;
	while (b <= 200000) {
		brown[t] = b;
		b = b + dist;
		dist++;
		t++;
	}
}

void bfs() {
	q.push(c);
	time_vec[c] = 0;

	while (!q.empty()) {
		int cur_pos = q.front();
		q.pop();

		int back_pos = cur_pos - 1;
		if (back_pos >= 0 && time_vec[back_pos] == -1) {
			q.push(back_pos);
			time_vec[back_pos] = time_vec[cur_pos] + 1;
			if (back_pos == brown[time_vec[back_pos]]) {
				ans = time_vec[back_pos];
				return;
			}
		}

		int front_pos = cur_pos + 1;
		if (front_pos <= 200000 && time_vec[front_pos] == -1) {
			q.push(front_pos);
			time_vec[front_pos] = time_vec[cur_pos] + 1;
			if (front_pos == brown[time_vec[front_pos]]) {
				ans = time_vec[front_pos];
				return;
			}
		}
		int tele_pos = cur_pos * 2;
		if (tele_pos <= 200000 && time_vec[tele_pos] == -1) {
			q.push(tele_pos);
			time_vec[tele_pos] = time_vec[cur_pos] + 1;
			if (tele_pos == brown[time_vec[tele_pos]]) {
				ans = time_vec[tele_pos];
				return;
			}
		}
	}
}

int main(void) {
	cin >> b >> c;
	if (b == c) {
		cout << 0;
		return 0;
	}
	brown_init(b);
	bfs();
	if (ans == 0) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	
	return 0;
}