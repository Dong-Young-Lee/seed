#include <iostream>
#include <string>
#include <stack>
using namespace std;

void verify_vps(string ps) {
	int ps_size = ps.size();
	if (ps_size % 2 == 1) {
		cout << "NO\n";
	}
	else {
		stack<char> stack;
		for (int i = 0; i < ps_size; i++) {
			if (ps[i] == '(') {
				stack.push(ps[i]);
			}
			else {
				if (stack.empty()) {
					cout << "NO\n";
					return;
				}
				else {
					stack.pop();
				}
			}
		}
		cout << (stack.empty() ? "YES\n" : "NO\n");
	}
}

int main(void) {
	int t;
	cin >> t;
	
	while (t--) {
		string ps;
		cin >> ps;
		verify_vps(ps);
	}

	return 0;

}