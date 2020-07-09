#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int pre = 0, res = nums[0];
		for (int &i : nums)
		{
			pre = max(pre + i, i);
			res = max(res, pre);
		
		}
		return res;
	}
};

int main(){
	vector<int> nums = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	Solution solution;
	int a=solution.maxSubArray(nums);
	cout << "½á¹ûÎª£º " << a << endl;
	system("pause");
}