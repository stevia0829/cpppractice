#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
	void rotate(vector<vector<int>> &matrix) {
		int n = matrix.size();
		if (n == 0) { return; }
		for (int i = 0; i < int(n/2); i++) {
			for (int j = i; j < int(n-i-1); j++) {
				rotate4(matrix,i,j,n);
			}
		}
	}


private:
	void rotate4(vector<vector<int>> &matrix, int i, int j,int n) {
		swap(matrix[i][j], matrix[j][n - 1 - i]);
		swap(matrix[i][j], matrix[n-1-i][n - 1- j]);
		swap(matrix[i][j], matrix[n - 1 - j][i]);

	}

};

int main() {
	Solution solution;
	vector<vector<int>> matrix = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
	solution.rotate(matrix);
	int row = matrix.size();
	int col = matrix[0].size();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
}
