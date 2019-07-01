#include <iostream>
#include <vector>
using namespace std;

int n, m;

typedef struct {
	int row;
	int col;
	int dist;
}house;

int house_cnt;
vector<house> house_vec;
int chicken_cnt;
vector< pair<int, int> > chicken_coor;

int isused[13];
int numbers[13];
int used_numbers;

int ans = 1000000;

void find_ans() {
	int chicken_dist = 0;
	for (int i = 0; i < house_cnt; i++) {
		chicken_dist += house_vec[i].dist;
	}

	if (ans > chicken_dist) {
		ans = chicken_dist;
	}

}

void find_dist(int max) {
	for (int i = 0; i < house_cnt; i++) {
		house_vec[i].dist = 200;
		for (int j = 0; j < max; j++) {
			int row_dist = house_vec[i].row - chicken_coor[numbers[j]].first;
			if (row_dist < 0) row_dist = -row_dist;
			int col_dist = house_vec[i].col - chicken_coor[numbers[j]].second;
			if (col_dist < 0) col_dist = -col_dist;
			int dist = row_dist + col_dist;
			if (house_vec[i].dist > dist) {
				house_vec[i].dist = dist;
			}
		}
	}
}

void set_chicken(int max) {
	if (used_numbers == max) {
		find_dist(max);
		find_ans();
		return;
	}
	for (int i = 0; i < chicken_cnt; i++) {
		if (!isused[i]) {
			if (used_numbers > 0) {
				if (i > numbers[used_numbers - 1]) {
					isused[i] = 1;
					numbers[used_numbers] = i;
					used_numbers++;
					set_chicken(max);
					isused[i] = 0;
					used_numbers--;
				}
			}
			else {
				isused[i] = 1;
				numbers[used_numbers] = i;
				used_numbers++;
				set_chicken(max);
				isused[i] = 0;
				used_numbers--;
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			if (input == 1) {
				house_cnt++;
				house_vec.push_back({ i,j, 200 });
			}
			else if (input == 2) {
				chicken_cnt++;
				chicken_coor.push_back(make_pair(i, j));
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		set_chicken(i);
	}
	
	cout << ans;

	return 0;
}