#include<iostream>
#include<vector>

using namespace std;


vector<vector<int> > v(2, vector<int>(4, 1)); 

int main() {
	int row = v.size();
	int col = v[1].size();
	printf("%d\t%d",row,col);
	system("pause");
}



