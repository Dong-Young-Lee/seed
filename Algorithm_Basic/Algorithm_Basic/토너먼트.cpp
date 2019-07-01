#include <iostream>
#include <queue>
using namespace std;

int n, kim, lim;
queue<bool> q;
int r;

int main(void) {
	cin >> n >> kim >> lim;
	for (int i = 1; i <= n; i++) {
		if (i == kim || i == lim) {
			q.push(true);
		}
		else {
			q.push(false);
		}
	}

	bool ans_print = false;
	while (true) {
		r++;

		bool odd = false;
		if (q.size() % 2 != 0) {
			odd = true;
		}

		int size = q.size() / 2;
		for (int i = 0; i < size; i++) {
			bool a = q.front();
			q.pop();
			bool b = q.front();
			q.pop();

			if (a && b) {
				cout << r;
				ans_print = true;
				break;
			}
			else if (a) {
				q.push(a);
			}
			else {
				q.push(b);
			}
		}
		
		if (ans_print) {
			break;
		}

		if (odd) {
			bool last = q.front();
			q.pop();
			q.push(last);
		}
	}
	return 0;
}