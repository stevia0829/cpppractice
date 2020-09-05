#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int currColor = image[sr][sc];
		if (currColor == newColor) return image;
		int dx[4] = { 1,0,0,-1 };
		int dy[4] = { 0,1,-1,0 };
		int rows = image.size();
		int col = image[0].size();
		//bfs
		//vector<vector<int>> vis(rows, vector<int>(col, 0));
		//vis[sr][sc] = 1;
		image[sr][sc] = newColor;
		queue<pair<int, int>> Q;
		Q.emplace(sr, sc);
		//Q.push(make_pair(sr, sc));  emplace 和push 在 queue中一样的
		while (!Q.empty())
		{
			auto curr = Q.front();
			Q.pop();
			int x = curr.first, y = curr.second;
			for (int i = 0; i < 4; i++) {
				int tx = x + dx[i];
				int ty = y + dy[i];
				if (tx >= 0 && tx < rows && ty >= 0 && ty < col && image[tx][ty] == currColor) {
					Q.emplace(tx,ty);
					//Q.push(make_pair(tx, ty));
					//vis[tx][ty] = 1;
					image[tx][ty] = newColor;
				}

			}
		}
		return image;
	}
};

int main() {
	vector<vector<int>> image = { {1,1,1},{1,1,0},{1,0,1} };
	int sr = 1, sc = 1, newColor = 2;
	Solution solution;
	vector<vector<int>> res = solution.floodFill(image, sr, sc, newColor);
	for (auto i : res)
	{
		for (auto j : i) {
			cout << j << ' ';
		}
		cout << endl;
	}
	system("pause");
}