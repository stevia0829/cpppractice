#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// hash表
//class Solution {
//public:
//	int majorityElement(vector<int>& nums) {
//		//vector<int> cnt(nums.size(), 0);
//		unordered_map<int, int> cnt;
//		for (auto i : nums) {
//			cnt[i]++;
//			if (cnt[i] > nums.size() / 2) return i;
//		}
//		return 0;
//	}
//};

//摩尔投票
//也可以理解成混战极限一换一，不同的两者一旦遇见就同归于尽，最后活下来的值都是相同的，即要求的结果
//时间O(n)，空间O(1)
//class Solution {
//public:
//	int majorityElement(vector<int>& nums) {
//		int res = 0, count = 0;
//		for (int i = 0; i < nums.size(); i++) {
//			if (count == 0) {
//				res = nums[i];
//				count++;
//			}
//			else
//				res == nums[i] ? count++ : count--;
//		}
//		return res;
//	}
//};
// 排序
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};

int main() {
	vector<int> nums = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	Solution solution;
	cout << solution.majorityElement(nums) << endl;
	system("pause");
}
