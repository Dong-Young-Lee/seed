#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;

int visited[MAX];

int n, k;

void bfs(int pos) {
	queue<int> q;
	q.push(pos);
	visited[pos] = 1;
	
	while (!q.empty()) {
		int cur_pos = q.front();
		q.pop();

		if (cur_pos == k) {
			cout << visited[cur_pos] - 1;
			return;
		}

		int left_pos = cur_pos - 1;
		if (left_pos >= 0 && !visited[left_pos]) {
			visited[left_pos] = visited[cur_pos] + 1;
			q.push(left_pos);
		}

		int right_pos = cur_pos + 1;
		if (right_pos <= 100000 && !visited[right_pos]) {
			visited[right_pos] = visited[cur_pos] + 1;
			q.push(right_pos);
		}

		int tele_pos = 2 * cur_pos;
		if (tele_pos <= 100000 && !visited[tele_pos]) {
			visited[tele_pos] = visited[cur_pos] + 1;
			q.push(tele_pos);
		}
	}
}

int main(void) {
	cin >> n >> k;
	if (n == k) {
		cout << 0;
		return 0;
	}

	bfs(n);

	return 0;
}