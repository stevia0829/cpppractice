#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		int steps = 0;
		int Maxposition = 0;
		int end = 0;
		int len = nums.size();
		if (nums.size() == 0) return 0;
		for (int i = 0; i < len - 1; i++) {
			Maxposition = max(Maxposition, i + nums[i]);
			if (i == end) {
				end = Maxposition;
				steps++;
			}
		}
		return steps;
	}
};
int main(){
	vector<int> nums = { 2,3,1,1,4 };
	Solution solution;
	cout << solution.jump(nums) << endl;
	system("pasue");
}