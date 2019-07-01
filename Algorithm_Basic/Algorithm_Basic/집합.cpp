#include <iostream>
#include <string>
using namespace std;

int s = 0;
int al = 21;

void add(int x) {
	s = s | (1 << x);
}

void remove(int x) {
	s = s & ~(1 << x);
}

void check(int x) {
	int c = s & (1 << x);
	if (c == 0) {
		cout << 0 << '\n';
	}
	else {
		cout << 1 << '\n';
	}
}

void toggle(int x) {
	s = s ^ (1 << x);
}

void all() {
	s = (1 << al) - 1;
}

void empty() {
	s = 0;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int m;
	cin >> m;
	while (m--) {
		string input;
		cin >> input;
		if (input == "add") {
			int x;
			cin >> x;
			add(x);
		}
		else if (input == "remove") {
			int x;
			cin >> x;
			remove(x);
		}
		else if (input == "check") {
			int x;
			cin >> x;
			check(x);
		}
		else if (input == "toggle") {
			int x;
			cin >> x;
			toggle(x);
		}
		else if (input == "all") {
			all();
		}
		else if (input == "empty") {
			empty();
		}
	}
	return 0;
}