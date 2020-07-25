#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
	// dfs
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> res;
		if (nums.size() == 0) return res;
		backtrack(res, nums, 0, len);
		return res;
	}
	void backtrack(vector<vector<int>> &res, vector<int> &path, int first, int len) {
		if (first == len) {
			res.emplace_back(path);
			return;
		}
		for (int i = first; i < len; i++) {
			// 动态维护数组
			swap(path[i], path[first]);
			// 继续递归填下一个数
			backtrack(res, path, first + 1, len);
			// 撤销操作
			swap(path[i], path[first]);
		}
	}
};

int main() {
	vector<int> nums = { 1,2,3 };
	Solution solution;
	int len = nums.size();
	vector<vector<int>> answer = solution.permute(nums);
	int row = answer.size();
	int col = answer[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << answer[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}