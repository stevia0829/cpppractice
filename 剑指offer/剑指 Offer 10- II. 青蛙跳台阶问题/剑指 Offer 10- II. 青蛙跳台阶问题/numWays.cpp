#include<iostream>

using namespace std;

//这个题目等价于斐波那契数列
class Solution {
public:
	int numWays(int n) {
		int num[2] = { 1,1 };
		int flag = 0;
		while (flag<n)
		{
			num[flag & 1] = (num[0] + num[1])% 1000000007;
			flag++;
		}
		return num[n & 1];
	}
};

int main() {
	int n = 7;
	Solution solution;
	cout << solution.numWays(n) << endl;
	system("pause");
}