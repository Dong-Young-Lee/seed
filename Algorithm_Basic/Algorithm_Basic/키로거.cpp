#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> s_left;
stack<char> s_right;
int main(void) {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		int str_size = str.length();
		for (int i = 0; i < str_size; i++) {
			if (str[i] == '<') {
				if (!s_left.empty()) {
					s_right.push(s_left.top());
					s_left.pop();
				}
			}
			else if (str[i] == '>') {
				if (!s_right.empty()) {
					s_left.push(s_right.top());
					s_right.pop();
				}
			}
			else if (str[i] == '-') {
				if (!s_left.empty()) {
					s_left.pop();
				}
			}
			else {
				s_left.push(str[i]);
			}
		}
		while (!s_left.empty()) {
			s_right.push(s_left.top());
			s_left.pop();
		}
		string ans;
		while (!s_right.empty()) {
			ans += s_right.top();
			s_right.pop();
		}
		cout << ans << '\n';
	}
	return 0;
}