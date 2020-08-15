#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (dfs(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
	bool dfs(vector<vector<char>>& board, string word,int i,int j, int k) {
		// k为记录已经走过的样本数目
		if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0 || board[i][j] != word[k]) return false;
		if (k == word.size() - 1) return true;
		char tmp = board[i][j];
		board[i][j] = '/';    //dfs 中的标记
		bool res = dfs(board,word,i+1,j,k+1) || dfs(board,word,i,j+1,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j-1,k+1);
		board[i][j] = tmp;
		return res;
	}
};

int main() {
	vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	string word = "ABCCED";
	Solution solution;
	cout << solution.exist(board, word) << endl;
	system("pause");
}