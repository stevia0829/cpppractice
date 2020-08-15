#include<iostream>
#include<algorithm>

using namespace std;

//class Solution {
//public:
//	double myPow(double x, int n) {
//		if (n < 0)
//		{
//			x = (1 / x);
//			n = -n;
//		}
//		double quickres = quickpow(x, n);
//		double res=quickres*quickres;
//		if (n % 2 != 0) res = res * x;
//		return res;
//	}
//	double quickpow(double x, int n) {
//		int m = n / 2;
//		double quickres = 1.0;
//		for (int i = 0; i < m; i++)
//		{
//			quickres = quickres * x;
//		}
//		return quickres;
//	}
//};

class Solution {
public:
	double myPow(double x, int n) {
		double res = 1.0;
		for (int i = n; i != 0; i /= 2) {
			if (i % 2 != 0) {
				res *= x;
			}
			x *= x;
		}
		return  n < 0 ? 1 / res : res;
	}
};

int main() {
	Solution solution;
	cout << solution.myPow(2, -2) << endl;
	system("pause");

}