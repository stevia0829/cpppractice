#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<string>  

using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map <string, vector<string> > m;
		for (string&s : strs)
		{
			string t = s;
			sort(t.begin(), t.end());
			m[t].push_back(s);
		}
		for (auto& n : m)
		{
			res.push_back(n.second);
		}
		return res;
	}
};

int main() {
	vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
	Solution solution;
	vector<vector<string>> res=solution.groupAnagrams(strs);
	for (auto i : res) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	system("pause");
}
