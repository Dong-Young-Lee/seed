#include <iostream>
#include <vector>
using namespace std;

int k;
int selected_set[12];
vector<int> numbers;
int visited[12];
int used_numbers;

void func() {
	if (used_numbers == 6) {
		for (int i = 1; i <= 6; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < k; i++) {
		if (visited[i] == 0) {
			if (selected_set[i] > numbers[used_numbers]) {
				visited[i] = 1;
				numbers.push_back(selected_set[i]);
				used_numbers++;
				func();
				visited[i] = 0;
				numbers.pop_back();
				used_numbers--;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	numbers.push_back(0);
	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++) {
			cin >> selected_set[i];
		}
		func();
		cout << '\n';
	}
	return 0;

}