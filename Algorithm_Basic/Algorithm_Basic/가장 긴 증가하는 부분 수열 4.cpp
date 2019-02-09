// bottom-up
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> d(1001, -1);
vector<int> seq(1001);
vector<int> pre(1001, -1);

void print_seq(int p) {
	if (p == -1) {
		return;
	}

	print_seq(pre[p]);

	cout << seq[p] << ' ';
}

int main(void) {
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> seq[i];
	}

	// 1. 초기값 저장
	d[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (seq[i] > seq[j] && d[j] >= d[i]) {
				d[i] = d[j] + 1;
				pre[i] = j;
			}
		}
	}

	int ans = d[0];
	int position = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < d[i]) {
			ans = d[i];
			position = i;
		}
	}

	cout << ans << '\n';
	print_seq(position);

	return 0;

}