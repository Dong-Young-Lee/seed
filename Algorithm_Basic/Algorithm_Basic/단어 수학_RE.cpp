#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
string input[MAX];

int n;

int is_used[MAX];
int numbers[MAX];
int used_numbers;

int ans;

void convert_to_num() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int size = input[i].size();
		int mul = 1;
		for (int j = size - 1; j >=0; j--) {
			sum += (numbers[input[i][j]-'A'] * mul);
			mul *= 10;
		}
	}

	if (ans < sum) {
		ans = sum;
	}
}

void permutation() {
	if (used_numbers == MAX) {
		convert_to_num();

		return;
	}

	for (int i = 0; i < MAX; i++) {
		if (is_used[i] == 0) {
			is_used[i] = 1;
			numbers[used_numbers] = i;
			used_numbers++;
			permutation();
			used_numbers--;
			is_used[i] = 0;
		}
	}
}

int main(void) {
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, input[i]);
	}
	permutation();

	cout << ans;
	return 0;
}


