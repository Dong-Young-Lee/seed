#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
	int dir;
	int eng;
}atom;

int n;
int map[4001][4001];

int number_of_atoms;
atom atom_arr[1000];

int d_r[4] = { -1, 1, 0, 0 };
int d_c[4] = { 0, 0, -1, 1 };

int visited[4001][4001];
int collided[4001][4001];
int ans;

void remove_atom(int num) {
	atom_arr[num] = atom_arr[number_of_atoms - 1];
	number_of_atoms--;
}

void solve() {
	int time = 0;
	number_of_atoms = n;
	while (time != 4001) {
		time++;
		if (number_of_atoms == 0) break;
		for (int i = 0; i < number_of_atoms; i++) {
			int cur_row = atom_arr[i].row;
			int cur_col = atom_arr[i].col;
			int cur_dir = atom_arr[i].dir;
			int cur_eng = atom_arr[i].eng;

			visited[cur_row][cur_col]--;

			int next_row = cur_row + d_r[cur_dir];
			int next_col = cur_col + d_c[cur_dir];
			if (next_row == -1 || next_row == 4001 || next_col == -1 || next_col == 4001) {
				remove_atom(i);
				i--;
				continue;
			}

			atom_arr[i].row = next_row;
			atom_arr[i].col = next_col;
			atom_arr[i].dir = cur_dir;
			atom_arr[i].eng = cur_eng;

			visited[next_row][next_col]++;
			if (visited[next_row][next_col] > 1) {
				collided[next_row][next_col] = 1;
			}
		}

		for (int i = 0; i < number_of_atoms; i++) {
			int cur_row = atom_arr[i].row;
			int cur_col = atom_arr[i].col;
			if (collided[cur_row][cur_col]) {
				if (visited[cur_row][cur_col] == 1) {
					collided[cur_row][cur_col] = 0;
				}
				visited[cur_row][cur_col]--;
				ans += atom_arr[i].eng;
				remove_atom(i);
				i--;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			int c, r, d, k;
			cin >> c >> r >> d >> k;
			c += 1000;
			r += 1000;
			c *= 2;
			r *= 2;
			r = 4000 - r;
			atom_arr[i] = {r, c, d, k};
			visited[r][c] = 1;
		}

		ans = 0;
		solve();
		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}