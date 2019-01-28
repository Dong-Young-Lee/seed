#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> left_st;
stack<char> right_st;

void init(string input) {
	int size = input.size();
	for (int i = 0; i < size; i++) {
		left_st.push(input[i]);
	}
}

void print_result() {
	while (!left_st.empty()) {
		right_st.push(left_st.top());
		left_st.pop();
	}
	while (!right_st.empty()) {
		cout << right_st.top();
		right_st.pop();
	}
}


int main(void) {
	string input;
	cin >> input;
	init(input);
	int n;
	cin >> n;
	while (n--) {
		char cmd;
		cin >> cmd;
		if (cmd == 'L') {
			if (!left_st.empty()) {
				right_st.push(left_st.top());
				left_st.pop();
			}
		}
		else if (cmd == 'D') {
			if (!right_st.empty()) {
				left_st.push(right_st.top());
				right_st.pop();
			}
		}
		else if (cmd == 'B') {
			if (!left_st.empty()) {
				left_st.pop();
			}
		}
		else if (cmd == 'P') {
			char c;
			cin >> c;
			left_st.push(c);
		}
	}
	print_result();

	return 0;
}