#include "Solution.h"
#include<iostream>
#include<stdlib.h>
#include<algorithm>

using namespace std;
int n,result;
int main()
{
	cin >> n;
	Solution solution;
	result=solution.numTrees(n);
	cout << result << endl;
	system("pause");
}


