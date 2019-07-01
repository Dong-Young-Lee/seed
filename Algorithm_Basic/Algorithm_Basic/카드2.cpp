#include <iostream>
#include <queue>
using namespace std;

int main(void) {
	int n;
	cin >> n;

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	if (n == 1) {
		cout << 1;
		return 0;
	}

	while (true) {
		q.pop();
		if (q.size() == 1) {
			cout << q.front();
			break;
		}
		q.push(q.front());
		q.pop();
	}

	return 0;
}