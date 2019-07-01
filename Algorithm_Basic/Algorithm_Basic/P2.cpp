#include <iostream>
#include <string>
#include <queue>
using namespace std;

int total_cnt;
string input;

queue<char> alphabet;
queue<char> number;
queue<char> output;

int error;

void init() {
	int input_size = input.size();
	for (int i = 0; i < input_size; i++) {
		if (input[i] >= 'A' && input[i] <= 'Z' || input[i] >= 'a' && input[i] <= 'z') {
			if (input[i] >= 'A' && input[i] <= 'Z') {
				total_cnt++;
			}
			alphabet.push(input[i]);
		}
		else {
			number.push(input[i]);
		}
	}
}

void make_output() {
	queue<char> left;
	queue<char> right;
	for (int i = 0; i < total_cnt; i++) {
		if (alphabet.empty() || number.empty()) {
			error = 1;
			break;
		}

		left.push(alphabet.front());
		alphabet.pop();
		if (!alphabet.empty()) {
			if (alphabet.front() >= 'a' && alphabet.front() <= 'z') {
				left.push(alphabet.front());
				alphabet.pop();
			}
		}

		int cur_right = number.front();
		right.push(cur_right);
		number.pop();

		if (cur_right == '1') {
			if (!number.empty() && number.front() == '0') {
				right.push(number.front());
				number.pop();
			}
			else {
				right.pop();
			}
		}

		while (!left.empty()) {
			output.push(left.front());
			left.pop();
		}
		
		while (!right.empty()) {
			output.push(right.front());
			right.pop();
		}
	}
}

int main(void) {
	cin >> input;
	init();

	make_output();

	if (error) {
		cout << "error";
	}
	else {
		while (!output.empty()) {
			cout << output.front();
			output.pop();
		}
	}

	return 0;
}