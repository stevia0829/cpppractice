#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1));
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i) {
			if (p[i - 1] == '*') {
				dp[0][i] = true;
			}
			else {
				break;
			}
		}
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (p[j - 1] == '*') {
					dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
				}
				else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
			}
		}
		return dp[m][n];
	}
};
//class Solution {
//public:
//	bool isMatch(string s, string p) {
//		if (s.size() == 0 && p.size() == 0)
//			return true;
//		else if ((s.size() == 0 && (p!= "*")) || (s.size() != 0 && p.size() == 0))
//			return false;
//		if ((s[0] == p[0]) || (p[0]=='?'))
//		{ 
//			s = s.substr(1), p = p.substr(1); 
//			isMatch(s, p);
//		}
//		else if (p[0] == '*' ) {
//			if (s.size() == 0 && p=="*") return true;
//			else if (s[1] == p[1]) {
//				s = s.substr(1);
//				p = p.substr(1);
//				isMatch(s, p);
//			}
//			    else {
//				      s = s.substr(1);
//				      isMatch(s, p);
//			          }
//
//		}
//		else return false;
//	}
//};

int main() {
	/*string s = "adceb", p = "*a*b";*/
	// string s = "acdcb", p = "a*c?b";
	string s = "aa", p = "*";
	Solution solution;
	cout << solution.isMatch(s, p) << endl;
	//string a = "s";
	//a = a.substr(1);
	//cout<<a.size()<<endl;

	system("pause");
}