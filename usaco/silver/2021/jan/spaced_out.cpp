#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	vector<vector<int>> grid;
	int a;
	for (int i=0;i<n;i++) {
		grid.push_back({});
		for (int j=0;j<n;j++) {
			cin >> a; grid[i].push_back(a);
		}
	}
	long ans_row = 0;
	long ans_col = 0;

	long sum_1_row = 0;
	long sum_2_row = 0;
	long sum_1_col = 0;
	long sum_2_col = 0;

	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			sum_1_row += grid[i][j];
			swap(sum_1_row, sum_2_row);
			sum_1_col += grid[j][i];
			swap(sum_1_col, sum_2_col);
		}
		ans_row += max(sum_1_row, sum_2_row);
		ans_col += max(sum_1_col, sum_2_col);
		sum_1_row = 0; sum_2_row = 0;
		sum_1_col = 0; sum_2_col = 0;
	}
	cout << max(ans_row, ans_col);
}
