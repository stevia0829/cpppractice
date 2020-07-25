#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		if (nums.size() == 0) return res;
		int len = nums.size();
		dfs(res, nums, 0, len);
	}
	void dfs(vector<vector<int>> &res, vector<int> &path, int start, int len) {
		if (start == len) {
			res.emplace_back(path);
			return;
		}

		for (int i = 0; i < len; i++) {
			if (path[i] != path[start])
			{
				swap(path[i], path[start]);
				dfs(res, path, start + 1, len);
				swap(path[i], path[start]);
			}
		}
		
	}
};

int main(){
	vector<int> nums = { 1,2,3 };
	Solution solution;
	int len = nums.size();
	vector<vector<int>> answer = solution.permuteUnique(nums);
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