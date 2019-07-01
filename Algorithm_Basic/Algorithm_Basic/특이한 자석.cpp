#include <iostream>
#include <stack>
using namespace std;

typedef struct {
	int wheel_num;
	int clock;
}info;

const int MAX = 4;

int test_case, T;
int k;

int wheel[MAX][8];
stack<info> st;

int ans;

void calc_score() {
	int score = 1;
	for (int i = 0; i < MAX; i++) {
		if (wheel[i][0] == 1) {
			ans += score;
		}
		score <<= 1;
	}
}

void rotate(int wheel_num, int clock) {
	if (clock == 1) {
		int next_top = wheel[wheel_num][7];
		for (int i = 7; i > 0; i--) {
			wheel[wheel_num][i] = wheel[wheel_num][i - 1];
		}
		wheel[wheel_num][0] = next_top;
	}
	else {
		int next_top = wheel[wheel_num][0];
		for (int i = 0; i < 7; i++) {
			wheel[wheel_num][i] = wheel[wheel_num][i + 1];
		}
		wheel[wheel_num][7] = next_top;
	}
}

void determine_rotate(int wheel_num, int clock) {
	st.push({ wheel_num, clock });

	int flag = 0;
	for (int i = wheel_num; i > 0; i--) {
		int cur_left_cog = wheel[i][6];
		int left_right_cog = wheel[i - 1][2];
		
		if (cur_left_cog != left_right_cog) {
			int next_clock;
			if (flag % 2 == 0) {
				next_clock = -clock;
			}
			else {
				next_clock = clock;
			}
			st.push({ i - 1, next_clock });
		}
		else {
			break;
		}
		flag++;
	}

	flag = 0;
	for (int i = wheel_num; i < MAX - 1; i++) {
		int cur_right_cog = wheel[i][2];
		int right_left_cog = wheel[i + 1][6];

		if (cur_right_cog != right_left_cog) {
			int next_clock;
			if (flag % 2 == 0) {
				next_clock = -clock;
			}
			else {
				next_clock = clock;
			}

			st.push({ i + 1, next_clock });
		}
		else {
			break;
		}
		flag++;
	}
}

void solve() {
	for (int i = 0; i < k; i++) {
		int wheel_num, clock;
		cin >> wheel_num >> clock;
		wheel_num--;

		determine_rotate(wheel_num, clock);

		while (!st.empty()) {
			rotate(st.top().wheel_num, st.top().clock);
			st.pop();
		}
	}
	calc_score();
}

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		ans = 0;

		cin >> k;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> wheel[i][j];
			}
		}

		solve();

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;
}