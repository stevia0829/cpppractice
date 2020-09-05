#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	int dx[8] = { -1,0,1,1,1,0,-1,-1 };
	int dy[8] = { -1,-1,-1,0,1,1,1,0 };
public:

	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {

		if (board[click[0]][click[1]] == 'M')
		{
			board[click[0]][click[1]] = 'x';
			return board;
		}
		itBoard(board, click);
		return board;
	}

	void itBoard(vector<vector<char>>& board, vector<int>& click) {
		vector<vector<int>> neibor;
		vector<int> temp = click;
		int cnt = 0;
		int m = board.size();
		int n = board[0].size();
		for (int i = 0; i < 8; i++) {
			if (click[0] + dx[i] < 0 || click[0] + dx[i] >= m || click[1] + dy[i] < 0 || click[1] + dy[i] >= n)
				continue;
			temp[0] = click[0] + dx[i], temp[1] = click[1] + dy[i];
			neibor.push_back(temp);
		}
		for (auto agent : neibor)
		{
			if (board[agent[0]][agent[1]] == 'M' || board[agent[0]][agent[1]] == 'X')
			{
				cnt++;
			}

		}
		if (cnt == 0) {
			board[click[0]][click[1]] = 'B';
			for (auto agent : neibor)
			{
				if (board[agent[0]][agent[1]] != 'E') continue;
				itBoard(board, agent);
			}
		}
		else 
		{
			board[click[0]][click[1]] = cnt + '0';

		}	
	}
};



//class Solution {
//public:
//	int dir_x[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
//	int dir_y[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
//
//	void dfs(vector<vector<char>>& board, int x, int y) {
//		int cnt = 0;
//		for (int i = 0; i < 8; ++i) {
//			int tx = x + dir_x[i];
//			int ty = y + dir_y[i];
//			if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size()) {
//				continue;
//			}
//			// 不用判断 M，因为如果有 M 的话游戏已经结束了
//			cnt += board[tx][ty] == 'M';
//		}
//		if (cnt > 0) {
//			// 规则 3
//			board[x][y] = cnt + '0';
//		}
//		else {
//			// 规则 2
//			board[x][y] = 'B';
//			for (int i = 0; i < 8; ++i) {
//				int tx = x + dir_x[i];
//				int ty = y + dir_y[i];
//				// 这里不需要在存在 B 的时候继续扩展，因为 B 之前被点击的时候已经被扩展过了
//				if (tx < 0 || tx >= board.size() || ty < 0 || ty >= board[0].size() || board[tx][ty] != 'E') {
//					continue;
//				}
//				dfs(board, tx, ty);
//			}
//		}
//	}
//
//	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
//		int x = click[0], y = click[1];
//		if (board[x][y] == 'M') {
//			// 规则 1
//			board[x][y] = 'X';
//		}
//		else {
//			dfs(board, x, y);
//		}
//		return board;
//	}
//};

int main() {

}