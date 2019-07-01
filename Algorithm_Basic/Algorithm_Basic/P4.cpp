#include <iostream>
using namespace std;

int building[1000000];
int n;
int rope[1000000];
int ans;
void max_rope() {
	for (int cur = 0; cur < n; cur++) {
		for (int target = cur + 1; target < n; target++) {
			if (building[cur] <= building[target]) {
				rope[cur] = target - cur;
				break;
			}
		}
	}
}

void find_ans() {
	for (int i = 0; i < n; i++) {
		if (ans < rope[i]) {
			ans = rope[i];
		}
	}
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> building[i];
	}

	max_rope();
	find_ans();
	cout << ans;

	return 0;
}