#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 20;

typedef struct {
	int row;
	int col;
	int size;
	int eat;
	int time;
}shark;

typedef struct {
	int row;
	int col;
	int size;
	int dist;
}fish;

int n;
int map[MAX][MAX];

shark baby;

int d_r[4] = { -1, 1, 0, 0 };
int d_c[4] = { 0, 0, -1, 1 };

vector<fish> can_eat_fishes;

int end_flag;

void print_map() {
	cout << "time : " << baby.time << " size : " << baby.size << " eat : " << baby.eat << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	
}

void find_distance(int row, int col) {
	queue< pair<int, int> > q;
	int visited[MAX][MAX] = { 0, };
	q.push(make_pair(row, col));
	visited[row][col] = 1;

	int distance = 1;
	while (!q.empty()) {
		int q_size = q.size();
		for (int i = 0; i < q_size; i++) {
			int cur_row = q.front().first;
			int cur_col = q.front().second;
			q.pop();
			if (map[cur_row][cur_col] >= 1 && map[cur_row][cur_col] <= 6 && baby.size > map[cur_row][cur_col]) {
				can_eat_fishes.push_back({ cur_row, cur_col, map[cur_row][cur_col], distance - 2 });
			}

			for (int j = 0; j < 4; j++) {
				int next_row = cur_row + d_r[j];
				int next_col = cur_col + d_c[j];
				if (next_row == -1 || next_row == n || next_col == -1 || next_col == n) continue;
				if (visited[next_row][next_col] == 0 && baby.size >= map[next_row][next_col]) {
					visited[next_row][next_col] = distance;
					q.push(make_pair(next_row, next_col));
				}
			}
		}
		distance++;
	}
}

void find_near_fish() {
	int min_dist_fish = 100;
	int can_eat_fishes_num = can_eat_fishes.size();
	for (int i = 0; i < can_eat_fishes_num; i++) {
		if (min_dist_fish > can_eat_fishes[i].dist) {
			min_dist_fish = can_eat_fishes[i].dist;
		}
	}

	vector<fish> min_dist_fishes;
	for (int i = 0; i < can_eat_fishes_num; i++) {
		if (min_dist_fish == can_eat_fishes[i].dist) {
			min_dist_fishes.push_back(can_eat_fishes[i]);
		}
	}

	int min_row_fish = 20;
	int min_dist_fishes_num = min_dist_fishes.size();
	for (int i = 0; i < min_dist_fishes_num; i++) {
		if (min_row_fish > min_dist_fishes[i].row) {
			min_row_fish = min_dist_fishes[i].row;
		}
	}

	vector<fish> min_row_fishes;
	for (int i = 0; i < min_dist_fishes_num; i++) {
		if (min_row_fish == min_dist_fishes[i].row) {
			min_row_fishes.push_back(min_dist_fishes[i]);
		}
	}
	
	int min_col_fish = 20;
	int min_row_fishes_num = min_row_fishes.size();
	for (int i = 0; i < min_row_fishes_num; i++) {
		if (min_col_fish > min_row_fishes[i].col) {
			min_col_fish = min_row_fishes[i].col;
		}
	}

	vector<fish> min_col_fishes;
	for (int i = 0; i < min_row_fishes_num; i++) {
		if (min_col_fish == min_row_fishes[i].col) {
			min_col_fishes.push_back(min_row_fishes[i]);
		}
	}

	int can_eat = min_col_fishes.size();
	if (can_eat) {
		fish eaten_fish = min_col_fishes[0];
		map[baby.row][baby.col] = 0;
		baby.row = eaten_fish.row;
		baby.col = eaten_fish.col;
		baby.eat++;
		baby.time += eaten_fish.dist + 1;
		map[baby.row][baby.col] = 9;
		if (baby.eat == baby.size) {
			baby.eat = 0;
			baby.size++;
		}
	}
	else {
		end_flag = 1;
	}

	can_eat_fishes.clear();

}


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			map[i][j] = input;
			if (input == 9) {
				baby = { i, j, 2, 0, 0 };
			}
		}
	}

	while (true) {
		find_distance(baby.row, baby.col);
		find_near_fish();
		if (end_flag) {
			break;
		}
	}
	cout << baby.time;

	return 0;
}