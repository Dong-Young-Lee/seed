// �ٽ� �ϱ�

/*
1. �Ұ����� ���
2. ������ ã�� ���
3. ���� ��� ȣ��
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool check(int l, string password) {
	int ja = 0, mo = 0;
	for (int i = 0; i < l; i++) {
		if (password[i] == 'a' ||
			password[i] == 'e' ||
			password[i] == 'i' ||
			password[i] == 'o' ||
			password[i] == 'u') {
			mo++;
		}
		else {
			ja++;
		}
	}
	if (ja >= 2 && mo >= 1) return true;
	else return false;
}

void solve(int l, int c, vector<char> &input, int count , string password) {
	// 1. �Ұ����� ���
	if (count > l) {
		return;
	}

	
	// 2. ���� ã�� ���
	if (count == l) {
		if (check(l, password)) {
			cout << password << '\n';
		}
		return;
	}

	// 3. ���� ��� ȣ��
	solve(l, c, input, count + 1, password + input[count]);
}

int main(void) {
	int l, c;
	cin >> l >> c;
	vector<char> input(c);
	
	for (int i = 0; i < c; i++) {
		cin >> input[i];
	}
	sort(input.begin(), input.end());

	solve(l, c, input, 0, "");

	return 0;
}