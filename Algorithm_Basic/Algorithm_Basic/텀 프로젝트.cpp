#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int tc;
int n;

void find_cycle(vector< vector<int> > &adj_list, vector<int> &visited, vector<int> &cycle_list, int cur) {

}

int main(void) {
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		cin >> n;
		vector< vector<int> > adj_list(n, vector<int>(0, 0));
		int input;
		for (int i = 0; i < n; i++) {
			cin >> input;
			adj_list[i].push_back(input - 1);
		}

		vector<int> cycle_list(n, 0);
		for (int i = 0; i < n; i++) {
			vector<int> visited(n, 0);
			find_cycle(adj_list, visited, cycle_list, 0);

		}
	}
	return 0;
}