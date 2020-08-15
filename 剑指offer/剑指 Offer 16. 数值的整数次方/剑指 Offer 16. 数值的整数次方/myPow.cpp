#include<iostream>

using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		double res = 1.0;
		for (int i = n; i !=0; i/=2) {
			if (i % 2 != 0) {
				res *= x;
			}
			x *= x;
		}
		return n < 0 ? 1 / res : res;
	}
};

int main() {
	double x = 2.0;
	int n = 5;
	Solution solution;
	cout << solution.myPow(x, n) << endl;
	system("pause");
}