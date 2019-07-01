#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <queue>
#include <set>
using namespace std;

int tc, n, k;
queue<char> q;
int side;

set<string, greater<string>> strings;

int ans;

int power_16(int power) {
	int ret = 1;
	for (int i = 0; i < power; i++) {
		ret *= 16;
	}
	return ret;
}

int ret_16_to_10(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else {
		return c - '7';
	}
}

void find_ans() {
	string ans_string;
	int index = 1;
	set<string>::iterator iter;
	for (iter = strings.begin(); iter != strings.end(); iter++) {
		if (index == k) {
			ans_string = *iter;
		}
		index++;
	}
	 
	for (int i = 0; i < side; i++) {
		int power = side - i - 1;
		int mul_num = power_16(power);
		int num_16 = ret_16_to_10(ans_string[i]);
		ans += num_16 * mul_num;
	}

}

void n_rotate() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			string temp;
			for (int k = 0; k < side; k++) {
				temp += q.front();
				q.push(q.front());
				q.pop();
			}
			strings.insert(temp);
		}
		q.push(q.front());
		q.pop();
	}
}

int main(void) {
	scanf("%d\n", &tc);
	for (int t = 1; t <= tc; t++) {
		while (!q.empty()) {
			q.pop();
		}
		strings.clear();
		ans = 0;

		scanf("%d %d\n", &n, &k);

		side = n / 4;

		for (int i = 0; i < n; i++) {
			char c;
			scanf("%c", &c);
			q.push(c);
		}

		n_rotate();
		find_ans();

		printf("#%d %d\n", t, ans);
		
	}
	return 0;
}

