#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int weight;
	int pos;
}info;

int n, w, l;
queue<info> bridge;
queue<info> truck;
int cur_num;
int cur_weight;
int time;

void solve() {
	// init
	bridge.push({ truck.front().weight, truck.front().pos + 1 });
	cur_num++;
	cur_weight += truck.front().weight;
	truck.pop();
	time++;

	while (!bridge.empty() || !truck.empty()) {
		for (int i = 0; i < cur_num; i++) {
			bridge.push({ bridge.front().weight, bridge.front().pos + 1 });
			bridge.pop();
		}

		if (bridge.front().pos == w + 1) {
			cur_num--;
			cur_weight -= bridge.front().weight;
			bridge.pop();
		}

		if (!truck.empty()) {
			if (truck.front().weight + cur_weight <= l) {
				bridge.push({ truck.front().weight, truck.front().pos + 1 });
				cur_num++;
				cur_weight += truck.front().weight;
				truck.pop();
			}
		}
		time++;
	}
}

int main(void) {
	cin >> n >> w >> l;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		truck.push({ input, 0 });
	}

	solve();
	cout << time;

	return 0;
}