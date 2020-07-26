#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

using namespace std;

typedef long long ll;

// dynamic programming
//class Solution {
//public:
//	int splitArray(vector<int>& nums, int m) {
//		int n = nums.size();
//		vector<vector<long long>> f(n + 1, vector<long long>(m + 1, LLONG_MAX));
//		vector<long long> sub(n + 1, 0);
//		for (int i = 0; i < n; i++) {
//			sub[i + 1] = sub[i] + nums[i];
//		}
//		f[0][0] = 0;
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= min(i, m); j++) {
//				for (int k = 0; k < i; k++) {
//					f[i][j] = min(f[i][j], max(f[k][j - 1], sub[i] - sub[k]));
//				}
//			}
//		}
//		return (int)f[n][m];
//	}
//};

//二分查找
//「使……最大值尽可能小」是二分搜索题目常见的问法。
class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		//ll low = *max_element(nums.begin(), nums.end());
		//ll high = accumulate(nums.begin(), nums.end(), 0);
		long long low = 0;
		long long high = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			low = max(low, (long long)nums[i]);
			high = high + nums[i];
		}
		while (low<high)
		{
			ll mid=(low+high) / 2;
			if(check(nums, m, mid)) high=mid;
			else low = mid + 1;

		}
		return low;
	}
	
	bool check(vector<int>& nums, int m, int mid) {
		ll sum = 0;
		int cnt = 1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (sum + nums[i] > mid)
			{
				cnt++;
				sum = nums[i];
			}
			else sum += nums[i];
		}
		return cnt <= m;
	}
};

int main() {
	Solution solution;
	/*vector<int> nums = { 1,1,2 };*/
	
	vector<int> nums = { 1,2147483647 };
	cout << solution.splitArray(nums,2)<< endl;
	system("pause");
}