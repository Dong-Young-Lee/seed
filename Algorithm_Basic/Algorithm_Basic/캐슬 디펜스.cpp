#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 15;
int n, m, d;

int is_used[MAX];
int numbers[3];
int used_numbers;

queue< pair<pair<int, int>, int> > q;
queue< pair<pair<int, int>, int> > q_copyed;

int enermy_num;
int ans;
int cnt;

void copy_q() {
	while (!q.empty()) {
		q.pop();
	}

	int q_copyed_size = q_copyed.size();
	for (int i = 0; i < q_copyed_size; i++) {
		q.push(q_copyed.front());
		q_copyed.push(q_copyed.front());
		q_copyed.pop();
	}
	enermy_num =  q_copyed_size;
}

void enermy_move() {
	int q_size = q.size();
	for (int i = 0; i < q_size; i++) {
		pair<pair<int, int>, int> cur = q.front();
		q.pop();
		if (cur.second == n - 1) {
			enermy_num--;
		}
		else {
			q.push(make_pair(make_pair(-1, cur.first.second), cur.second+1));
		}
	}
}

void attack() {
	queue< pair<pair<int, int>, int> > dead_q;
	for (int i = 0; i < 3; i++) {
		int row = n;
		int col = numbers[i];

		vector < pair<pair<int, int>, int> > dist_v;

		int q_size = q.size();
		for (int j = 0; j < q_size; j++) {
			pair<pair<int, int>, int> cur = q.front();
			q.push(q.front());
			q.pop();
			
			int dist_row = row - cur.second;
			if (dist_row < 0) dist_row = -dist_row;
			int dist_col = col - cur.first.second;
			if (dist_col < 0) dist_col = -dist_col;
			int dist = dist_row + dist_col;

			if (dist <= d) {
				dist_v.push_back(make_pair(make_pair(dist, cur.first.second), cur.second));
			}
		}

		if (!dist_v.empty()) {
			sort(dist_v.begin(), dist_v.end());
			dead_q.push(dist_v[0]);
		}
	}

	int dead_size = dead_q.size();
	for (int i = 0; i < dead_size; i++) {
		pair<pair<int, int>, int> dead_cur = dead_q.front();
		dead_q.pop();

		int q_size = q.size();
		for (int j = 0; j < q_size; j++) {
			pair<pair<int, int>, int> cur = q.front();
			q.pop();
			if (dead_cur.second == cur.second && dead_cur.first.second == cur.first.second) {
				cnt++;
				enermy_num--;
			}
			else {
				q.push(cur);
			}
		}
	}

}

void comb() {
	if (used_numbers == 3) {
		copy_q();
		cnt = 0;

		while (true) {
			if (enermy_num == 0) {
				break;
			}
			else {
				if (cnt + enermy_num < ans) {
					break;
				}
			}
			attack();
			enermy_move();
		}

		if (ans < cnt) {
			ans = cnt;
		}

		return;
	}
	for (int i = 0; i < m; i++) {
		if (used_numbers > 0) {
			if (i > numbers[used_numbers - 1]) {
				if (is_used[i] == 0) {
					is_used[i] = 1;
					numbers[used_numbers] = i;
					used_numbers++;
					comb();
					is_used[i] = 0;
					used_numbers--;
				}
			}
		}
		else {
			if (is_used[i] == 0) {
				is_used[i] = 1;
				numbers[used_numbers] = i;
				used_numbers++;
				comb();
				is_used[i] = 0;
				used_numbers--;
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			if (input == 1) {
				q_copyed.push(make_pair(make_pair(-1, j), i));
			}
		}
	}
	
	comb();

	cout << ans;
	
	return 0;
}