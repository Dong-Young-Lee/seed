#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(void) {
	int left_row_cnt;
	cin >> left_row_cnt;
	string head;
	cin.ignore();
	getline(cin, head);
	
	int left_col_cnt = 1;
	int head_size = head.size();
	for (int i = 0; i < head_size; i++) {
		if (head[i] == ' ') {
			left_col_cnt++;
		}
	}

	vector< vector<string> > left_table(left_row_cnt, vector<string>(left_col_cnt));
	int col_id = 0;
	string temp;
	for (int i = 0; i < head_size; i++) {
		if (head[i] == ' ') {
			left_table[0][col_id] = temp;
			temp.clear();
			col_id++;
		}
		else {
			temp += head[i];
		}
	}
	left_table[0][col_id] = temp;

	for (int i = 1; i < left_row_cnt; i++) {
		for (int j = 0; j < left_col_cnt; j++) {
			cin >> temp;
			left_table[i][j] = temp;
		}
	}

	int right_row_cnt;
	cin >> right_row_cnt;
	cin.ignore();
	getline(cin, head);

	int right_col_cnt = 1;
	head_size = head.size();
	for (int i = 0; i < head_size; i++) {
		if (head[i] == ' ') {
			right_col_cnt++;
		}
	}

	vector< vector<string> > right_table(right_row_cnt, vector<string>(right_col_cnt));
	col_id = 0;
	temp.clear();
	for (int i = 0; i < head_size; i++) {
		if (head[i] == ' ') {
			right_table[0][col_id] = temp;
			temp.clear();
			col_id++;
		}
		else {
			temp += head[i];
		}
	}
	right_table[0][col_id] = temp;

	for (int i = 1; i < right_row_cnt; i++) {
		for (int j = 0; j < right_col_cnt; j++) {
			cin >> temp;
			right_table[i][j] = temp;
		}
	}


	vector< vector<string> > join_table(right_row_cnt, vector<string>(left_col_cnt + right_col_cnt - 1));
	for (int i = 0; i < left_col_cnt; i++) {
		join_table[0][i] = left_table[0][i];
	}
	for (int i = 1; i < right_col_cnt; i++) {
		join_table[0][i+left_col_cnt - 1] = right_table[0][i];
	}


	return 0;
}