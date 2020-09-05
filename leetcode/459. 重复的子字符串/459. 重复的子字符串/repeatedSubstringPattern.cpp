#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		if (s.empty()) return false;
		if (s.size() == 1) return true;
		int n = s.size();
		for (int i = 1; i <= n / 2; i++) {
			if (n%i == 0) {
				bool match = true;
				for (int j = i; j < n; j++) {
					if (s[j] != s[j - i]) {
						match = false;
						break;
					}
			    }
				if (match) return true;
			}
		}
		return false;
	}
};

// ×Ö·û´®²éÕÒ
//class Solution {
//public:
//	bool repeatedSubstringPattern(string s) {
//		return (s + s).find(s, 1) != s.size();
//	}
//};

int main() {
	//string s = "abcaabcaabcaabca";
	string s = "abab";
	Solution solution;
	cout << solution.repeatedSubstringPattern(s) << endl;
	system("pause");
}