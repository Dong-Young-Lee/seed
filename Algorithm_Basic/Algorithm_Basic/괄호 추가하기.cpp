#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
using namespace std;

const int MAX = 39;

int n;
char expression[MAX];

int max_len;

int numbers[MAX];
int used_numbers;

int ans = -2147483647;

stack<char> st;
stack<char> st_2;
stack<int> st_3;

int calc_postfix() {
	int size = st.size();
	for (int i = 0; i < size; i++) {
		int cur = st.top();
		if (cur >= '0' && cur <= '9') {
			st_3.push(cur - '0');
		}
		else if (cur == '+' || cur == '-' || cur == '*') {
			int a = st_3.top();
			st_3.pop();
			int b = st_3.top();
			st_3.pop();
			if (cur == '+') {
				st_3.push(a + b);
			}
			else if (cur == '-') {
				st_3.push(b - a);
			}
			else if (cur == '*') {
				st_3.push(a * b);
			}
		}
		st.pop();
	}

	int ret = st_3.top();
	st_3.pop();
	return ret;
}

void make_postfix() {
	for (int i = 0; i <= max_len; i++) {
		char cur = expression[i];
		if (cur >= '0' && cur <= '9') {
			st_2.push(cur);
		}
		else if (cur == '+' || cur == '-' || cur == '*') {
			if (st.empty()) {
				st.push(cur);
			}
			else {
				if (st.top() == '+' || st.top() == '-' || st.top() == '*') {
					st_2.push(st.top());
					st.pop();
					st.push(cur);
				}
				else {
					st.push(cur);
				}
			}
		}
		else if (cur == '(') {
			st.push(cur);
		}
		else if (cur == ')') {
			while (true) {
				if (st.top() == '(') {
					st.pop();
					break;
				}
				st_2.push(st.top());
				st.pop();
			}
		}
	}

	while (!st.empty()) {
		st_2.push(st.top());
		st.pop();
	}

	while (!st_2.empty()) {
		st.push(st_2.top());
		st_2.pop();
	}
}

void comb(int max_paren) {
	if (used_numbers == max_paren) {
		
		//for (int i = 0; i <= max_len; i++) {
		//	printf("%c", expression[i]);
		//}
		//printf("\n");
		

		make_postfix();
		int result = calc_postfix();
		//printf("result : %d\n", result);

		if (ans < result) {
			ans = result;
		}
		return;
	}

	for (int i = 0; i <= max_len - 6; i += 4) {
		if (used_numbers > 0) {
			if (i > numbers[used_numbers - 1]) {
				if (expression[i] == '\0') {
					expression[i] = '(';
					expression[i + 6] = ')';
					numbers[used_numbers] = i + 6;
					used_numbers++;
					comb(max_paren);
					expression[i] = '\0';
					expression[i + 6] = '\0';
					used_numbers--;
				}
			}
		}
		else {
			if (expression[i] == '\0') {
				expression[i] = '(';
				expression[i + 6] = ')';
				numbers[used_numbers] = i + 6;
				used_numbers++;
				comb(max_paren);
				expression[i] = '\0';
				expression[i + 6] = '\0';
				used_numbers--;
			}
		}
	}
}

void solve() {
	int max_paren = (n + 1) / 4;
	for (int i = 0; i <= max_paren; i++) {
		comb(i);
	}
}

int main(void) {
	scanf("%d\n", &n);
	max_len = n * 2;
	for (int i = 1; i < max_len; i += 2) {
		scanf("%c", &expression[i]);
	}

	solve();

	printf("%d", ans);

	return 0;
}