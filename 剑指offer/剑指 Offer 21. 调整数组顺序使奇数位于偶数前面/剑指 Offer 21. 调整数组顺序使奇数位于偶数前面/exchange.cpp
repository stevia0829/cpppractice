#include<iostream>
#include<vector>

using namespace std;
//方法1
//class Solution {
//public:
//	vector<int> exchange(vector<int>& nums) {
//		int len = nums.size();
//		for (int i = 0; i < len - 1; i++) {
//			for (int j = len - 1; j > i; j--) {
//				if (nums[i] % 2 == 0 && nums[j] % 2 != 0) {
//					swap(nums[i], nums[j]);
//				}
//			}
//		}
//		return nums;
//	}
//};

// 方法2
//class Solution {
//public:
//	vector<int> exchange(vector<int>& nums) {
//		int len=nums.size();
//		vector<int> res;
//		int flag = 0;
//		for (auto i : nums)
//		{
//			if (i % 2 == 0) { res.insert(res.end(), i); }
//			else {
//				res.insert(res.begin()+flag, i);
//				flag++;
//			}
//		}
//		return res;
//	}
//};

//方法3
class Solution {
public:
	vector<int> exchange(vector<int>& nums) {
		int left = 0, right = nums.size() - 1;
		while (left < right)
		{
			if (nums[left] % 2 != 0)
			{
				left++;
				continue;
			}
			if (nums[right] % 2 == 0) {
				right--;
				continue;
			}
			swap(nums[left++], nums[right--]);
				
		}
		return nums;
	}
};


int main() {
	vector<int> nums = { 2,16,3,5,13,1,16,1,12,18,11,8,11,11,5,1 };
	Solution solution;
	vector<int> res = solution.exchange(nums);
	for (auto i : res) {
		cout << i << ' ';
	}
	cout << endl;
	system("pause");
}