#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>
#include <vector>
using namespace std;

int tc, n;
char input[200];
stack<char> st;
char postfix[200];
stack<int> st_int;

int postfix_size;

int priority(char op) {
	if (op == '+') {
		return 1;
	}
	else if (op == '*') {
		return 2;
	}
	return -1;
}

int make_postfix() {
	int index = 0;
	for (int i = 0; i < n; i++) {
		if (input[i] >= '0' && input[i] <= '9') {
			postfix[index++] = input[i];
		}
		else if (input[i] == '+' || input[i] == '*') {
			if (st.empty()) {
				st.push(input[i]);
			}
			else {
				if (priority(st.top()) >= priority(input[i])) {
					postfix[index++] = st.top();
					st.pop();
					st.push(input[i]);
				}
				else {
					st.push(input[i]);
				}
			}
		}
		else if (input[i] == '(') {
			st.push(input[i]);
		}
		else if (input[i] == ')') {
			while (st.top() != '(') {
				postfix[index++] = st.top();
				st.pop();
			}
			st.pop();
		}
	}

	while (!st.empty()) {
		postfix[index++] = st.top();
		st.pop();
	}

	return index;
}

int calc_postfix() {
	
	for (int i = 0; i < postfix_size; i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			st_int.push(postfix[i] - '0');
		}
		else if (postfix[i] == '+') {
			int a = st_int.top();
			st_int.pop();
			int b = st_int.top();
			st_int.pop();
			st_int.push(a + b);
		}
		else if (postfix[i] == '*') {
			int a = st_int.top();
			st_int.pop();
			int b = st_int.top();
			st_int.pop();
			st_int.push(a * b);
		}
	}

	int ret = st_int.top();
	st_int.pop();
	return ret;
}

int main(void) {
	tc = 10;
	for (int t = 1; t <= tc; t++) {
		scanf("%d\n", &n);
		
		for (int i = 0; i < n; i++) {
			scanf("%c", &input[i]);
		}

		postfix_size = make_postfix();
		printf("#%d %d\n", t, calc_postfix());
	}

	return 0;
}