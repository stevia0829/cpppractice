#include<iostream>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int res = 0;
		while (n > 0)
		{
			res += n & 1;
			n >>= 1;
		}
		return res;
	}
};

int main() {
	uint32_t n = 00000000000000000000000000001011;
	Solution solution;
	cout << solution.hammingWeight(n) << endl;
	system("pause");
}