#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

int s;
// graph[i][j]
// 이모티콘 i개를 만들기 위해 필요한 시간 && 현재 클립보드의 이모티콘 개수 j
// i : 화면에 있는 이모티콘의 개수
// j : 클립보드에 복사된 이모티콘의 개수
vector< vector<int> > graph(2001, vector<int>(2001, -1));
queue< pair<int, int> > q;

void bfs() {
	q.push(make_pair(1, 0));
	graph[1][0] = 0;
	
	while (!q.empty()) {
		int cur_screen_cnt = q.front().first;
		int cur_clip_cnt = q.front().second;
		q.pop();

		// 1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
		int next_clip_cnt = cur_screen_cnt;
		if (graph[cur_screen_cnt][next_clip_cnt] == -1) {
			q.push(make_pair(cur_screen_cnt, next_clip_cnt));
			graph[cur_screen_cnt][next_clip_cnt] = graph[cur_screen_cnt][cur_clip_cnt] + 1;
			if (cur_screen_cnt == s) {
				break;
			}
		}

		// 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣음
		int next_screen_cnt = cur_screen_cnt + cur_clip_cnt;
		if (next_screen_cnt <= 2000 && cur_clip_cnt != 0 && graph[next_screen_cnt][cur_clip_cnt] == -1) {
			q.push(make_pair(next_screen_cnt, cur_clip_cnt));
			graph[next_screen_cnt][cur_clip_cnt] = graph[cur_screen_cnt][cur_clip_cnt] + 1;
			if (next_screen_cnt == s) {
				break;
			}
		}

		// 3. 화면에 있는 이모티콘 중 하나를 삭제
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