#include <iostream>
#include <vector>
using namespace std;

vector<int> time(16, -1);
vector<int> price(16, -1);

vector<int> pay_vec;

void solve(int max_days, int now_price, int now_days) {
	// 1. down 불가
	if (now_days > max_days) {
		pay_vec.push_back(now_price);
		return;
	}

	// top-down
	
	// 1. 현재 날짜에서 상담한다.
	if (now_days + time[now_days] <= max_days + 1) {
		solve(max_days, now_price + price[now_days], now_days + time[now_days]);
	}
	// 2. 현재 날짜에서 상담하지 않는다.
	solve(max_days, now_price, now_days + 1);
}

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> time[i] >> price[i];
	}

	solve(n, 0, 1);

	int max = 0;
	for (int i = 0; i < pay_vec.size(); i++) {
		if (max < pay_vec[i]) {
			max = pay_vec[i];
		}
	}

	cout << max;
	return 0;
}