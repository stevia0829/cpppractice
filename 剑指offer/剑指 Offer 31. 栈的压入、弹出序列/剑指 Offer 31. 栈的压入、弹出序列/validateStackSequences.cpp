#include<stack>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int> st;
		int i = 0;
		for (auto num : pushed) {
			st.push(num);
			while (!st.empty() && st.top()==popped[i])  // ÅÐ¶ÏÖ´ÐÐpopµÄÊ±¿Ì
			{
				st.pop();
				i++;
			}
		}
		return st.empty();
	}
};


int main(){
	vector<int> pushed = { 1,2,3,4,5 };
	vector<int> popped = { 4,5,3,2,1 };
	Solution solution;
	cout << solution.validateStackSequences(pushed, popped) << endl;
	system("pause");
}