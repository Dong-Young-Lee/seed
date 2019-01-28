#include <iostream>
#include <string>
using namespace std;

int queue[10001];
int g_begin = 0;
int g_end = 0;

int empty() {
	if (g_begin == g_end) {
		return 1;
	}
	else {
		return 0;
	}
}

void push(int value) {
	queue[g_end] = value;
	g_end += 1;
}

int pop() {
	if (empty()) {
		return -1;
	}
	else {
		g_begin += 1;
		return queue[g_begin-1];
	}
}

int size() {
	return g_end - g_begin;
}

int front() {
	if (empty()) {
		return -1;
	}
	else {
		return queue[g_begin];
	}
}

int back() {
	if (empty()) {
		return -1;
	}
	else {
		return queue[g_end - 1];
	}
}

int main(void) {
	int n;
	cin >> n;
	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int value;
			cin >> value;
			push(value);
		}
		else if (cmd == "pop") {
			cout << pop() << '\n';
		}
		else if (cmd == "size") {
			cout << size() << '\n';
		}
		else if (cmd == "empty") {
			cout << empty() << '\n';
		}
		else if (cmd == "front") {
			cout << front() << '\n';
		}
		else if (cmd == "back") {
			cout << back() << '\n';
		}
	}

	return 0;

}