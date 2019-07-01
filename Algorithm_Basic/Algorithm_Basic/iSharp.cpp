#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	string input;
	getline(cin, input);
	
	vector<char> first;
	int input_size = input.size();
	for (int i = 0; i < input_size; i++) {
		if (input[i] == ' ') {
			for (int j = 0; j < i; j++) {
				first.push_back(input[j]);
			}
			break;
		}
	}

	vector<int> start_pos;
	vector<int> end_pos;
	for (int i = 0; i < input_size; i++) {
		if (input[i] == ',' || input[i] == ';') {
			end_pos.push_back(i);
		}
		else if (input[i] == ' ') {
			start_pos.push_back(i);
		}
	}

	int start_size = start_pos.size();
	int first_size = first.size();
	for(int i=0; i<start_size; i++) {
		for (int j = 0; j < first_size; j++) {
			cout << first[j];
		}
		for (int j = end_pos[i] - 1; j >= start_pos[i] + 1; j--) {
			if ((input[j] >= 'a' && input[j] <= 'z') || (input[j] >= 'A' && input[j] <= 'Z')) {
				for (int k = start_pos[i]; k <= j; k++) {
					cout << input[k];
				}
				cout << ';' << '\n';
				break;
			}
			else if (input[j] == '[') {
				cout << ']';
			}
			else if (input[j] == ']') {
				cout << '[';
			}
			else {
				cout << input[j];
			}
		}
	}

	return 0;
}