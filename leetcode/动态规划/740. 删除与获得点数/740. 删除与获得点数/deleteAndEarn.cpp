#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		if (!nums.size()) return 0;
		if (nums.size() == 1) return nums[0];
		int len = nums.size();
		int max_num = nums[0];
		for (int i = 0; i < len; i++) {
			max_num = max(max_num, nums[i]);
		}
		// cnt 记录下不同元素的个数
		vector<int> cnt(max_num + 1, 0);
		for (auto i : nums) {
			cnt[i]++;
		}
		vector<int> dp(max_num + 1, 0);
		dp[1] = cnt[1] * 1; 
		// dp[2] = max(dp[1], cnt[2] * 2);
		for (int i = 2; i < max_num + 1; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2]+i*cnt[i]);
		}
		return dp[max_num];

	}
};

int main() {
	Solution solution;
	vector<int>nums = { 2, 2, 3, 3, 3, 4 };
	cout << solution.deleteAndEarn(nums) << endl;
	system("pause");
}