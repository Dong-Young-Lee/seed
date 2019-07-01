#include <iostream>
#include <queue>
using namespace std;

int t, n, m;
int main(void) {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		priority_queue<int, vector<int>, less<int>> pq;
		queue<int> q;
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			pq.push(p);
			q.push(p);
		}
		
		// 인쇄한 문서의 개수
		int cnt = 0;

		while (!pq.empty()) {
			if (pq.top() == q.front()) {
				cnt++;
				pq.pop();
				q.pop();
				if (m == 0) {
					cout << cnt << '\n';
					break;
				}
				else {
					m--;
					if (m == -1) {
						m = pq.size() - 1;
					}
				}
			}
			else {
				q.push(q.front());
				q.pop();
				m--;
				if (m == -1) {
					m = pq.size() - 1;
				}
			}
		}
	}
	return 0;
}