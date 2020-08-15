#include<iostream>
#include<vector>


using namespace std;


class Solution {
public:
	vector<int> printNumbers(int n) {
		vector<int> res;
		if (n == 0) return res;
		//打印到数组中
		for (int i = 1, max = pow(10, n); i < max; i++)
		{
			res.push_back(i);
		}
		return res;
	}
};


int main() {
	int n = 2;
	Solution solution;
	vector<int> res = solution.printNumbers(n);
	for (auto i : res)
	{
		cout << i << ' ';
		if (i % 10 == 0)
			cout << endl;
	}
	system("pause");

}