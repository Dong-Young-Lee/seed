#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int result[5000];
int r_idx = 0;

void init(int n) {
	for (int i = 1; i < n + 1; i++) {
		q.push(i);
	}
}

void print_res() {
	cout << "<";
	for (int i = 0; i < r_idx; i++) {
		cout << result[i] << ", ";
	}
	cout << q.front() << ">";
}

int main(void) {
	int n, m;
	cin >> n >> m;

	init(n);

	while (q.size() != 1) {
		int m2 = m - 1;
		while (m2--) {
			q.push(q.front());
			q.pop();
		}
		result[r_idx++] = q.front();
		q.pop();
	}

	print_res();

	return 0;

}