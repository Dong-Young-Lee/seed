#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	string input;
	cin >> input;
	int size = input.size();
	int res = 0;
	int flag = 1;
	stack<char> st;
	for (int i = 0; i < size; i++) {
		if (input[i] == '(') {
			st.push('(');
			flag = 1;
		}
		else {
			st.pop();
			if (flag == 1) {
				res += st.size();
			}
			else {
				res += 1;
			}
			flag = 0;
		}
	}
	cout << res;
	return 0;
}