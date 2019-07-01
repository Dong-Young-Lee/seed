//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int man_pos[10][2], man_cnt;
//int stair_pos[2][2], stair_depth[2], stair_cnt;
//int dist[10][2];
//int stair_0[10], stair_1[10];
//bool use[10];
//int ans;
//
//int inline _abs(int a)
//{
//	return (a < 0) ? -a : a;
//}
//
//void dfs(int remain, int cnt_0, int cnt_1)
//{
//	if (remain == 0)
//	{
//		ans = min(ans, max(stair_0[cnt_0 - 1] + stair_depth[0], stair_1[cnt_1 - 1] + stair_depth[1]));
//		return;
//	}
//
//	int mn = 2147483647, mn_id = -1;
//
//	for (int i = 0; i < man_cnt; i++)
//	{
//		if (use[i]) continue;
//
//		if (dist[i][0] < mn)
//		{
//			mn = dist[i][0];
//			mn_id = i;
//		}
//	}
//
//	use[mn_id] = true;
//
//	if (cnt_0 < 3) stair_0[cnt_0] = dist[mn_id][0] + 1;
//	else stair_0[cnt_0] = max(stair_0[cnt_0 - 3] + stair_depth[0], dist[mn_id][0] + 1);
//
//	dfs(remain - 1, cnt_0 + 1, cnt_1);
//
//	use[mn_id] = false;
//
//	mn = 2147483647, mn_id = -1;
//
//	for (int i = 0; i < man_cnt; i++)
//	{
//		if (use[i]) continue;
//
//		if (dist[i][1] < mn)
//		{
//			mn = dist[i][1];
//			mn_id = i;
//		}
//	}
//
//	use[mn_id] = true;
//
//	if (cnt_1 < 3) stair_1[cnt_1] = dist[mn_id][1] + 1;
//	else stair_1[cnt_1] = max(stair_1[cnt_1 - 3] + stair_depth[1], dist[mn_id][1] + 1);
//
//	dfs(remain - 1, cnt_0, cnt_1 + 1);
//
//	use[mn_id] = false;
//}
//
//int main()
//{
//	int T;
//
//	scanf("%d", &T);
//
//	for (int tc = 1; tc <= T; tc++)
//	{
//		man_cnt = 0, stair_cnt = 0, ans = 2147483647;
//
//		scanf("%d", &N);
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0, temp; j < N; j++)
//			{
//				scanf("%d", &temp);
//
//				if (temp == 1)
//				{
//					man_pos[man_cnt][0] = i, man_pos[man_cnt][1] = j;
//					man_cnt++;
//				}
//				else if (temp >= 2)
//				{
//					stair_pos[stair_cnt][0] = i, stair_pos[stair_cnt][1] = j;
//					stair_depth[stair_cnt] = temp;
//					stair_cnt++;
//				}
//			}
//		}
//
//		for (int i = 0; i < man_cnt; i++)
//		{
//			for (int j = 0; j < 2; j++) dist[i][j] = _abs(man_pos[i][0] - stair_pos[j][0]) + _abs(man_pos[i][1] - stair_pos[j][1]);
//		}
//
//		dfs(man_cnt, 0, 0);
//
//		printf("#%d %d\n", tc, ans);
//	}
//	return 0;
//}

//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//
//#define INF 1000
//#define min(a,b) ((a)<(b)? (a):(b))
//int ans;
//int A[15][2], B[15][2];
//char check[15];
//struct stair {
//	int x, y, k;
//}stair[2];
//
//
//typedef struct p {
//	int x, y;
//	int d_a, d_b;
//}p;
//p person[10];
//
//void dfs(int l, int last, int a_cnt, int b_cnt)
//{
//	int max = 0;
//	if (l >= last) {
//		if (a_cnt == 0) max = B[b_cnt - 1][1];
//		else if (b_cnt == 0) max = A[a_cnt - 1][1];
//		else max = (A[a_cnt - 1][1] > B[b_cnt - 1][1] ? A[a_cnt - 1][1] : B[b_cnt - 1][1]);
//		ans = min(ans, max);
//		//  printf("%d %d %d %d\n",a_cnt,b_cnt, max, ans);
//		return;
//	}
//	//A[a_cnt][1] = INF;
//	//B[a_cnt][1] = INF;
//	int idx = 0;
//	int dist = INF;
//	for (int i = 0; i < last; i++) {
//		if ((person[i].d_a <= dist) && !check[i]) {
//			dist = person[i].d_a;
//			A[a_cnt][0] = person[i].d_a;
//			A[a_cnt][1] = person[i].d_a + stair[0].k + 1; //계단입구, 계단끝까지 시간
//			idx = i;
//		}
//	}
//	check[idx] = 1;// 해당인덱스 
//	if (a_cnt >= 3) {
//		if (A[a_cnt - 3][0] == A[a_cnt][0]) A[a_cnt][0] += 1;
//		else if (A[a_cnt - 3][0] > A[a_cnt][0]) A[a_cnt][0] = A[a_cnt - 3][0] + 1;
//		if (A[a_cnt - 3][1] > A[a_cnt][0]) A[a_cnt][1] = A[a_cnt - 3][1] + stair[0].k, A[a_cnt][0] = A[a_cnt - 3][1];
//	}
//	//printf("%d %d\n", A[a_cnt][0], A[a_cnt][1]);
//	dfs(l + 1, last, a_cnt + 1, b_cnt);
//	check[idx] = 0;
//	/////////////////////////////////////////////////////////////////////////////////////////////
//	dist = INF;
//	for (int i = 0; i < last; i++) {
//		if ((person[i].d_b <= dist) && !check[i]) {
//			dist = person[i].d_b;
//			B[b_cnt][0] = person[i].d_b;
//			B[b_cnt][1] = person[i].d_b + stair[1].k + 1; //계단입구, 계단끝까지 시간
//			idx = i;
//		}
//	}
//	check[idx] = 1;
//	if (b_cnt >= 3) {
//		if (B[b_cnt - 3][0] == B[b_cnt][0]) B[b_cnt][0] += 1;
//		else if (B[b_cnt - 3][0] > B[b_cnt][0]) B[b_cnt][0] = B[b_cnt - 3][0] + 1;
//		if (B[b_cnt - 3][1] > B[b_cnt][0]) B[b_cnt][1] = B[b_cnt - 3][1] + stair[1].k, B[b_cnt][0] = B[b_cnt - 3][1];
//	}
//	dfs(l + 1, last, a_cnt, b_cnt + 1);
//	check[idx] = 0;
//}
//int main()
//{
//	int t, T, n;
//	int cnt, r, value;
//	scanf("%d", &T);
//	for (t = 1; t <= T; t++) {
//		scanf("%d", &n);
//		cnt = 0, r = 0;
//		ans = INF;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++) {
//				scanf("%d", &value);
//				if (value == 1) person[cnt].x = i, person[cnt++].y = j;
//				if (value > 1) stair[r].x = i, stair[r].y = j, stair[r++].k = value;
//			}
//		for (int i = 0; i < cnt; i++) {
//			person[i].d_a = abs(person[i].x - stair[0].x) + abs(person[i].y - stair[0].y);
//			person[i].d_b = abs(person[i].x - stair[1].x) + abs(person[i].y - stair[1].y);
//		}
//		dfs(0, cnt, 0, 0);
//		printf("#%d %d\n", t, ans);
//	}
//	return 0;
//}

//#include <iostream>
//#include <deque>
//#include <cstring>
//#include <vector>
//#include <algorithm>
//using namespace std;
//typedef struct st {
//	int time, y, x;
//};
//typedef struct st2 {
//	int dis1, dis2, y, x;
//};
//int T, N;
//int board[12][12], res = 987654321;
//
//vector<st> stair;
//vector<pair<int, int>> person;
//vector<st2> disper;
//int used[12];
//int psize = 0;
//
//void check() {
//	int cnt = 0;
//	vector<int> vec1, vec2;
//	for (int i = 0; i < psize; i++) {
//		if (used[i] == 1)vec1.push_back(abs(person[i].first - stair[0].y) + abs(person[i].second - stair[0].x) + 1);
//		else vec2.push_back(abs(person[i].first - stair[1].y) + abs(person[i].second - stair[1].x) + 1);
//	}
//	sort(vec1.begin(), vec1.end());
//	sort(vec2.begin(), vec2.end());
//	deque<int> deq;
//	int tm1 = 0;
//	if (!vec1.empty()) {
//		auto iter = vec1.begin();
//		while (true) {
//			if (iter == vec1.end() && deq.empty())break;
//			if (!deq.empty()) {
//				int dsize = deq.size();
//				for (int i = 0; i < dsize; i++)  deq[i]++;
//				while (!deq.empty() && deq.front() >= stair[0].time)deq.pop_front();
//			}
//			tm1++;
//			if (iter == vec1.end())continue;
//			while (*iter <= tm1 && deq.size() < 3) {
//				deq.push_back(0);
//				iter++;
//				if (iter == vec1.end())break;
//			}
//		}
//	}
//	int tm2 = 0;
//	if (!vec2.empty()) {
//		auto iter = vec2.begin();
//		while (true) {
//			if (iter == vec2.end() && deq.empty())break;
//			if (!deq.empty()) {
//				int dsize = deq.size();
//				for (int i = 0; i < dsize; i++)  deq[i]++;
//				while (!deq.empty() && deq.front() >= stair[1].time)deq.pop_front();
//			}
//			tm2++;
//			if (iter == vec2.end())continue;
//			while (*iter <= tm2 && deq.size() < 3) {
//				deq.push_back(0);
//				++iter;
//				if (iter == vec2.end())break;
//			}
//		}
//	}
//	if (tm1 < tm2)cnt = tm2;
//	else cnt = tm1;
//	if (res >= cnt) {
//		/*
//		cout << "cnt : " << cnt << "\n";
//		for (int i = 0; i < 10; i++) {
//			cout << used[i] << " ";
//		}
//		cout << "\n";
//		*/
//		res = cnt;
//	}
//}
//
//void go(int idx) {
//	if (idx == person.size()) {
//		check();
//		return;
//	}
//	used[idx] = 1;
//	go(idx + 1);
//	used[idx] = 2;
//	go(idx + 1);
//}
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cin >> T;
//	int nu = 0;
//	while (T--) {
//		cin >> N;
//		res = 987654321;
//		for (int i = 0; i < N; i++) {
//			for (int j = 0; j < N; j++) {
//				cin >> board[i][j];
//				if (board[i][j] == 1)person.push_back({ i,j });
//				else if (board[i][j] > 1)stair.push_back({ board[i][j],i,j });
//			}
//		}
//		psize = person.size();
//		go(0);
//		cout << "#" << ++nu << " " << res << '\n';
//		memset(board, 0, sizeof(board));
//		memset(used, 0, sizeof(used));
//		stair.clear();
//		person.clear();
//		disper.clear();
//	}
//	return 0;
//}


#include <iostream>
using namespace std;

typedef struct {
	int row;
	int col;
	int stair;
	int dist;
	int stat; // 0, 1, 2, 3, 4
	int action;
}p_info;

typedef struct {
	int row;
	int col;
	int num;
}s_info;

const int MAX = 10;
int T, t, n;
int map[MAX][MAX];

s_info stair[2];
int stair_num;

p_info people[MAX];
int people_num;

int numbers[MAX];
int used_numbers;

int ans;

void people_maching() {
	for (int i = 0; i < people_num; i++) {
		people[i].stair = numbers[i];

		int dist_row = people[i].row - stair[people[i].stair].row;
		if (dist_row < 0) dist_row = -dist_row;
		int dist_col = people[i].col - stair[people[i].stair].col;
		if (dist_col < 0) dist_col = -dist_col;
		int dist = dist_row + dist_col;

		people[i].dist = dist;
		people[i].stat = 0;
	}
}

void people_action() {
	int time = 0;

	int zero_cur = 0;
	int one_cur = 0;

	int complete_num = 0;

	while (true) {
		/*
		if (numbers[0] == 0 &&
			numbers[1] == 0 &&
			numbers[2] == 0 &&
			numbers[3] == 0 &&
			numbers[4] == 0 &&
			numbers[5] == 0 &&
			numbers[6] == 0 &&
			numbers[7] == 0 &&
			numbers[8] == 0 &&
			numbers[9] == 0 &&
			time == 11) {
			cout << "test\n";
		}
		*/
		for (int i = 0; i < people_num; i++) {
			if (people[i].stat == 0) { // 계단으로 이동
				people[i].dist--;
				people[i].action = 1;
				if (people[i].dist == 0) {
					people[i].stat = 1;
				}
			}

			if (people[i].stat == 1) { // 계단에서 대기
				if (people[i].stair == 0) {
					if (zero_cur < 3) {
						people[i].stat = 2;
						zero_cur++;
					}
				}
				else if (people[i].stair == 1) {
					if (one_cur < 3) {
						people[i].stat = 2;
						one_cur++;
					}
				}
			}
			else if (people[i].stat == 2 && people[i].action == 0) { // 계단 내려가기
				people[i].dist--;
				people[i].action = 1;
				if (people[i].dist == -(stair[people[i].stair].num + 1)) {
					people[i].stat = 3;
					// 계단 완료
					if (people[i].stair == 0) {
						zero_cur--;
					}
					else if (people[i].stair == 1) {
						one_cur--;
					}
					complete_num++;
					for (int j = 0; j < people_num; j++) {
						if (people[j].action == 0) {
							if (people[j].stat == 1) {
								if (people[j].stair == 0) {
									if (zero_cur < 3) {
										people[j].stat = 2;
										people[j].dist--;
										zero_cur++;
										people[j].action = 1;
									}
								}
								else if (people[j].stair == 1) {
									if (one_cur < 3) {
										people[j].stat = 2;
										people[j].dist--;
										one_cur++;
										people[j].action = 1;
									}
								}
							}
						}
					}
				}
			}

		}

		time++;

		
		if (numbers[0] == 1 &&
			numbers[1] == 1 &&
			numbers[2] == 0 &&
			numbers[3] == 1 &&
			numbers[4] == 1 &&
			numbers[5] == 0 &&
			numbers[6] == 1 &&
			numbers[7] == 1 &&
			numbers[8] == 0 &&
			numbers[9] == 1) {

			cout << "time : " << time << "\n";
			for (int i = 0; i < people_num; i++) {
				cout << i << "번 사람 : 목표(" << people[i].stair << ") " <<
					"거리 : " << people[i].dist << ", 상태 : " << people[i].stat << ", 액션 : " << people[i].action << '\n';
			}
			cout << '\n';

		}
		

		for (int i = 0; i < people_num; i++) {
			people[i].action = 0;
		}

		if (complete_num == people_num) {
			break;
		}
	}

	if (ans > time) {
		ans = time;
		/*
		cout << "time : " << time << "\n";
		for (int i = 0; i < used_numbers; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		*/
	}
}

void make_perm() {
	if (used_numbers == people_num) {
		/*
		for (int i = 0; i < used_numbers; i++) {
			cout << numbers[i] << ' ';
		}
		cout << '\n';
		*/

		people_maching();
		people_action();

		return;
	}
	for (int i = 0; i < 2; i++) {
		numbers[used_numbers] = i;
		used_numbers++;
		make_perm();
		used_numbers--;
	}
}

int main(void) {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		// init
		stair_num = 0;
		people_num = 0;
		ans = 100000000;

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == 1) {
					people[people_num++] = { i, j };
				}
				else if (map[i][j] >= 2 && map[i][j] <= 10) {
					stair[stair_num++] = { i, j, map[i][j] };
				}

			}
		}

		make_perm();

		cout << "#" << t << " " << ans << '\n';
	}
	return 0;
}