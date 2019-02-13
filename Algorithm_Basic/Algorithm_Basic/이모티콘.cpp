#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

int s;
// graph[i][j]
// �̸�Ƽ�� i���� ����� ���� �ʿ��� �ð� && ���� Ŭ�������� �̸�Ƽ�� ���� j
// i : ȭ�鿡 �ִ� �̸�Ƽ���� ����
// j : Ŭ�����忡 ����� �̸�Ƽ���� ����
vector< vector<int> > graph(2001, vector<int>(2001, -1));
queue< pair<int, int> > q;

void bfs() {
	q.push(make_pair(1, 0));
	graph[1][0] = 0;
	
	while (!q.empty()) {
		int cur_screen_cnt = q.front().first;
		int cur_clip_cnt = q.front().second;
		q.pop();

		// 1. ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 ����
		int next_clip_cnt = cur_screen_cnt;
		if (graph[cur_screen_cnt][next_clip_cnt] == -1) {
			q.push(make_pair(cur_screen_cnt, next_clip_cnt));
			graph[cur_screen_cnt][next_clip_cnt] = graph[cur_screen_cnt][cur_clip_cnt] + 1;
			if (cur_screen_cnt == s) {
				break;
			}
		}

		// 2. Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ�����
		int next_screen_cnt = cur_screen_cnt + cur_clip_cnt;
		if (next_screen_cnt <= 2000 && cur_clip_cnt != 0 && graph[next_screen_cnt][cur_clip_cnt] == -1) {
			q.push(make_pair(next_screen_cnt, cur_clip_cnt));
			graph[next_screen_cnt][cur_clip_cnt] = graph[cur_screen_cnt][cur_clip_cnt] + 1;
			if (next_screen_cnt == s) {
				break;
			}
		}

		// 3. ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� ����
		int next_delete_screen = cur_screen_cnt - 1;
		if (next_delete_screen >= 0 && graph[next_delete_screen][cur_clip_cnt] == -1) {
			q.push(make_pair(next_delete_screen, cur_clip_cnt));
			graph[next_delete_screen][cur_clip_cnt] = graph[cur_screen_cnt][cur_clip_cnt] + 1;
			if (next_delete_screen == s) {
				break;
			}
		}

	}
}

int main(void) {
	cin >> s;
	
	bfs();

	int min_time = numeric_limits<int>::max();
	for (int i = 0; i <= 2000; i++) {
		if (graph[s][i] != -1) {
			if (min_time > graph[s][i]) {
				min_time = graph[s][i];
			}
		}
	}
	cout << min_time;
	return 0;
}