#include <iostream>
using namespace std;

int numbers[20];
int used_numbers;
int n;
int ans;
int visited[1001];

void repet_comb() {
	if (used_numbers == n) {
		int sum = 0;
		for (int i = 0; i < used_numbers; i++) {
			if (numbers[i] == 0) {
				sum += 1;
			}
			else if (numbers[i] == 1) {
				sum += 5;
			}
			else if (numbers[i] == 2) {
				sum += 10;
			}
			else {
				sum += 50;
			}
		}
		if (visited[sum] == 0) {
			visited[sum] = 1;
			ans++;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (used_numbers > 0) {
			if (i >= numbers[used_numbers - 1]) {
				numbers[used_numbers] = i;
				used_numbers++;
				repet_comb();
				used_numbers--;
			}
		}
		else {
			numbers[used_numbers] = i;
			used_numbers++;
			repet_comb();
			used_numbers--;
		}
	}
}
int main(void) {
	cin >> n;
	repet_comb();
	cout << ans;
	return 0;
}