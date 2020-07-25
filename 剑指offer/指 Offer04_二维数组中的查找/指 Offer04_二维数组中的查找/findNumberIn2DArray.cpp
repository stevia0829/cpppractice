#include<iostream>
#include<vector>
#include<algorithm>

using  namespace std;

class Solution {
public:
	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) return false;
		int m = matrix.size();
		int n = matrix[0].size();
		int starti = 0;
		int startj = n - 1;
		while (startj >= 0 && starti < m) {
			if (matrix[starti][startj] == target) return true;
			if (matrix[starti][startj] > target) startj--;
			else if (matrix[starti][startj] < target) starti++;
		}
		return false;
	}
};

int main() {
	vector<vector<int>> matrix = {
		{1,   4,  7, 11, 15},
	{2,   5,  8, 12, 19 },
	{3,   6,  9, 16, 22},
	{10, 13, 14, 17, 24},
	{18, 21, 23, 26, 30},
	};
	Solution solution;
	cout << solution.findNumberIn2DArray(matrix, 31) << endl;
	system("pause");
}