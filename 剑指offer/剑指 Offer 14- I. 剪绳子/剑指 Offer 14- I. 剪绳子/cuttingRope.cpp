#include<iostream>

using namespace std;

class Solution {
public:
	int cuttingRope(int n) {
		int tmp=n, res=1;
		if (n == 2) 
			return 1;
		else if(n == 3) 
			return 2;
		while (tmp>0)
		{
			if (tmp >= 3 && tmp!=4 )
			{
				tmp -= 3;
				res *= 3;
			}
			else if (tmp == 4) { //4²ð·ÖÎª2*2
				tmp -= 4;
				res *= 4;
			}
			else if (tmp > 1 ) { 
				tmp -= 2;
				res *= 2;
			}
			else if(tmp == 1){
				tmp -= 1;
			}
		}
		return res;
	}
};

int main() {
	int n =8;
	Solution solution;
	cout << solution.cuttingRope(n) << endl;
	system("pause");
}