#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int x;
	cin >> x;
	vector<int> stick;

	// exception
	if (x == 64) {
		cout << 1;
		return 0;
	}

	stick.push_back(64);

	while (true) {
		// 가지고 있는 막대 중 길이가 가장 짧은 것을 고른다.
		int min_stick = 65;
		int min_stick_index;
		for (int i = 0; i < (int)stick.size(); i++) {
			if (min_stick > stick[i]) {
				min_stick = stick[i];
				min_stick_index = i;
			}
		}

		// 절반으로 자른다.
		int half_min_stick = min_stick / 2;
		
		// 잘려진 막대를 빼내어줌
		vector<int> temp;
		for (int i = 0; i < (int)stick.size() - min_stick_index; i++) {
			temp.push_back(stick.back());
			stick.pop_back();
		}
		temp.pop_back();
		for (int i = 0; i < (int)temp.size(); i++) {
			stick.push_back(temp.back());
			temp.pop_back();
		}

		// 일단 자른 막대1을 넣음
		stick.push_back(half_min_stick);

		// 만약 자른 막대의 절반 중 하나를 버리고, 
		// 남아있는 막대의 길이의 합이 X보다 크거나 같다면,
		// 위에서 자른 막대의 절반 중 하나를 버린다.
		int temp_sum = 0;
		for (int i = 0; i < (int)stick.size(); i++) {
			temp_sum += stick[i];
		}

		// 아니면 자른 막대2를 더 넣어줌
		if (temp_sum < x) {
			stick.push_back(half_min_stick);

		}

		// 정답일 경우 출력
		if (temp_sum == x) {
			cout << stick.size();
			break;
		}
		
	}
	
	return 0;
}