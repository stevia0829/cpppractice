#include<iostream>
#include<vector>
#include<algorithm>
#include <deque>

using namespace std;

class Solution {
	//参考
private:
	vector<vector<int>> res;
	vector<int> sol;
	vector<int> nums;
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		// 剪枝必须前面先排序
		sort(nums.begin(), nums.end());
		this->nums = nums;
		vector<bool> used(nums.size(), false);
		dfs(used);
		return res;
	}
private:
	void dfs(vector<bool> used) {
		if (sol.size() == nums.size()) {
			res.push_back(sol);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			//当前值用过了 或 
			//当前值等于前一个值： 两种情况：
			//1 nums[i-1] 没用过 说明回溯到了同一层 此时接着用num[i] 则会与 同层用num[i-1] 重复
			//2 nums[i-1] 用过了 说明此时在num[i-1]的下一层 相等不会重复
			if (used[i] || (i > 0 && !used[i - 1] && nums[i] == nums[i - 1])) {//用过了
				continue;
			}
			sol.push_back(nums[i]);
			used[i] = true;
			dfs(used);
			sol.pop_back();
			used[i] = false;
		}
	}
};

int main(){
	vector<int> nums = { 1,1,2 };
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