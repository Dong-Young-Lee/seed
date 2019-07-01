#include <iostream>
using namespace std;

typedef struct {
	int x;
	int y;
	int dir;
}robot_info;

typedef struct {
	int rb_num;
	char inst;
	int iter;
}inst_info;

int max_x, max_y, robot_num, inst_num;
robot_info robot[101];
inst_info inst_list[100];

int d_x[4] = { 0, 1, 0, -1 };
int d_y[4] = { 1, 0, -1, 0 };

int valid = 1;

int main(void) {
	cin >> max_x >> max_y;
	cin >> robot_num >> inst_num;
	for (int i = 1; i <= robot_num; i++) {
		char dir;
		cin >> robot[i].x >> robot[i].y >> dir;
		if (dir == 'N') {
			robot[i].dir = 0;
		}
		else if (dir == 'E') {
			robot[i].dir = 1;
		}
		else if (dir == 'S') {
			robot[i].dir = 2;
		}
		else if (dir == 'W') {
			robot[i].dir = 3;
		}
	}

	for (int i = 0; i < inst_num; i++) {
		cin >> inst_list[i].rb_num >> inst_list[i].inst >> inst_list[i].iter;
	}

	for (int i = 0; i < inst_num; i++) {
		inst_info cur_inst = inst_list[i];
		for (int j = 0; j < cur_inst.iter; j++) {
			if (cur_inst.inst == 'L') {
				int left_dir = (robot[cur_inst.rb_num].dir + 3) % 4;
				robot[cur_inst.rb_num].dir = left_dir;
			}
			else if (cur_inst.inst == 'R') {
				int right_dir = (robot[cur_inst.rb_num].dir + 1) % 4;
				robot[cur_inst.rb_num].dir = right_dir;
			}
			else if (cur_inst.inst == 'F') {
				int next_x = robot[cur_inst.rb_num].x + d_x[robot[cur_inst.rb_num].dir];
				int next_y = robot[cur_inst.rb_num].y + d_y[robot[cur_inst.rb_num].dir];
				if (next_x >= 1 && next_x <= max_x && next_y >= 1 && next_y <= max_y) {
					int ok = 1;
					for (int k = 1; k <= robot_num; k++) {
						if (next_x == robot[k].x && next_y == robot[k].y) {
							cout << "Robot " << cur_inst.rb_num << " crashes into robot " << k << "\n";
							valid = 0;
							ok = 0;
							break;
						}
					}
					if (ok) {
						robot[cur_inst.rb_num].x = next_x;
						robot[cur_inst.rb_num].y = next_y;
					}
					else {
						break;
					}
				}
				else {
					cout << "Robot " << cur_inst.rb_num << " crashes into the wall\n";
					valid = 0;
					break;
				}
			}
		}
		if (!valid) break;
	}

	if (valid) cout << "OK\n";

	return 0;
}