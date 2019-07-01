#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(void) {
	int n;
	int m;
	cin >> n >> m;

	queue< pair<int, int> > q;
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		q.push(make_pair(num, num));
	}

	int ans = 0;
	while (m != 0) {
		if (q.front().second == 1) { // <연산 1>
			n--;
			m--;
			q.pop();
			for (int i = 0; i < m; i++) {
				q.push(make_pair(q.front().first, q.front().second - 1));
				q.pop();
			}
		}
		else {
			int op2 = q.front().second - 1;
			int op3 = n - q.front().second + 1;
			int next_op;
			if (op3 < op2) {
				next_op = 3;
			}
			else {
				next_op = 2;
			}

			if (next_op == 2) { // <연산 2>
				ans += op2;
				for (int i = 0; i < m; i++) {
					int next_index = q.front().second - op2;
					if (next_index <= 0) {
						next_index += n;
					}
					q.push(make_pair(q.front().first, next_index));
					q.pop();
				}
			}
			else { // <연산 3>
				ans += op3;
				for (int i = 0; i < m; i++) {
					int next_index = q.front().second + op3;
					if (next_index >= n + 1) {
						next_index -= n;
					}
					q.push(make_pair(q.front().first, next_index));
					q.pop();
				}
			} 
		}
	}
	cout << ans;
	return 0;
}