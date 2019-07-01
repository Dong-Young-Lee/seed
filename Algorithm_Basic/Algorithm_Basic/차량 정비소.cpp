#include <iostream>
#include <stack>
#include <queue>
using namespace std;

typedef struct {
	int num;
	int reception;
	int repair;
	int visit_time;
}c_info;

typedef struct {
	int proc_time;
	int time;
	stack<c_info> st;
}d_info;

int test_case, T;
int n, m, k, a, b;
d_info reception_desk[9];
d_info repair_desk[9];

queue<c_info> input_q;
queue<c_info> first_q;
queue<c_info> second_q;
queue<c_info> final_q;

int ans;

int main(void) {
	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		ans = 0;

		cin >> n >> m >> k >> a >> b;
		for (int i = 0; i < n; i++) {
			cin >> reception_desk[i].proc_time;
		}
		for (int i = 0; i < m; i++) {
			cin >> repair_desk[i].proc_time;
		}
		for (int i = 0; i < k; i++) {
			int input;
			cin >> input;
			input_q.push({ -1, -1, -1, input });
		}


		int cur_time = 0;
		int customer_num = 1;
		while (true) {
			// 1
			for (int i = 0; i < m; i++) {
				if (!repair_desk[i].st.empty()) {
					repair_desk[i].time++;
					if (repair_desk[i].time == repair_desk[i].proc_time) {
						final_q.push(repair_desk[i].st.top());
						repair_desk[i].st.pop();
						repair_desk[i].time = 0;
					}
				}
			}

			// 2
			for (int i = 0; i < m; i++) {
				if (!second_q.empty()) {
					if (repair_desk[i].st.empty()) {
						repair_desk[i].st.push({ second_q.front().num, second_q.front().reception, i, -1 });
						second_q.pop();
					}
				}
			}

			// 3
			for (int i = 0; i < n; i++) {
				if (!reception_desk[i].st.empty()) {
					reception_desk[i].time++;
					if (reception_desk[i].time == reception_desk[i].proc_time) {
						second_q.push(reception_desk[i].st.top());
						reception_desk[i].st.pop();
						reception_desk[i].time = 0;
					}
				}
			}

			// 2
			for (int i = 0; i < m; i++) {
				if (!second_q.empty()) {
					if (repair_desk[i].st.empty()) {
						repair_desk[i].st.push({ second_q.front().num, second_q.front().reception, i, -1 });
						second_q.pop();
					}
				}
			}

			// 5
			for (int i = 0; i < n; i++) {
				if (!first_q.empty()) {
					if (reception_desk[i].st.empty()) {
						reception_desk[i].st.push({ first_q.front().num, i, -1, -1 });
						first_q.pop();
					}
				}
			}

			// 4 °í°´ µµÂø : Ã¹ ¹øÂ° ´ë±â
			while (!input_q.empty()) {
				if (input_q.front().visit_time == cur_time) {
					first_q.push({ customer_num, -1, -1, -1, });
					customer_num++;
					input_q.pop();
				}
				else {
					break;
				}
			}


			int final_q_size = final_q.size();
			if (final_q_size == k) {
				while (!final_q.empty()) {
					if (final_q.front().reception == a - 1 && final_q.front().repair == b - 1) {
						ans += final_q.front().num;
					}
					final_q.pop();
				}
				break;
			}

			cur_time++;

		}

		if (ans == 0) {
			cout << "#" << test_case << " " << -1 << "\n";
		}
		else {
			cout << "#" << test_case << " " << ans << "\n";
		}


	}
	return 0;
}