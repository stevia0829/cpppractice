#include<vector>
#include<iostream>

using namespace std;

class Solution {
private:
	static constexpr int directions[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int row = matrix.size(), col = matrix[0].size();
		if (row == 0 || col == 0) return {};
		vector<vector<bool>> vis(row, vector<bool>(col));
		int total = row * col;
		vector<int> res(total);

		int i = 0, j = 0;
		int directionIndex = 0;
		for (int k = 0; k < total; k++) {
			res[k] = matrix[i][j];
			vis[i][j] = true;
			int nextrow = i + directions[directionIndex][0], nextcol = j + directions[directionIndex][1];
			if (nextrow<0 || nextrow>=row || nextcol<0 || nextcol>=col || vis[nextrow][nextcol]) {
				directionIndex = (directionIndex + 1) % 4;
			}
			i += directions[directionIndex][0];
			j += directions[directionIndex][1];

		}
		return res;
	}
};

int main() {
	Solution solution;
	vector<vector<int>> nums = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<int> res = solution.spiralOrder(nums);
	for (auto i : res) {
		cout << i << ' ';
	}
	cout << endl;
	system("pause");
}