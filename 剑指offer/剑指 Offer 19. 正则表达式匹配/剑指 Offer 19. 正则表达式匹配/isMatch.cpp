#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int ls = s.size(), lp = p.size();
		vector<vector<bool>> dp(ls+1, vector<bool>(lp+1,false));
		dp[0][0] = true;
		for (int i = 0; i < ls + 1; i++) {
			for (int j = 1; j < lp + 1; j++) {
				if (p[j - 1] == '*')
				{
					dp[i][j] = (j >= 2) && (dp[i][j - 2] || ((i >0) && dp[i - 1][j] && (p[j - 2] == '.' || p[j - 2] == s[i - 1])));
				}
				else
					dp[i][j] = (i > 0 && (p[j - 1] == s[i - 1] || p[j - 1] == '.')) && dp[i - 1][j - 1];
			}
		}
		return dp.back().back();

	}
};

int main() {
	Solution solution;
	string s = "aa", p = ".*";
	cout << solution.isMatch(s, p) << endl;
	system("pause");
}