#include<iostream>
#include<vector>
#include<queue>


using namespace std;

//DFS

class Solution {
public:
	int getx(int x) {
		int res = 0;
		for (; x; x /= 10) {
			res += x % 10;
		}
		return res;
	}
	int movingCount(int m, int n, int k) {
		if (!k) return 1;
		queue<pair<int, int>> Q;
		// 向右和向下的方向数组
		int dx[2] = { 0, 1 };
		int dy[2] = { 1, 0 };
		// dfs 以及 bfs中都会用到的
		vector<vector<int> > vis(m, vector<int>(n, 0));
		Q.push(make_pair(0, 0));
		vis[0][0] = 1;
		int ans = 1;
		while (!Q.empty())
		{
			auto curr = Q.front();
			Q.pop();
			int x = curr.first;
			int y = curr.second;

			for (int i = 0; i < 2; ++i) {
				int tx = dx[i] + x;
				int ty = dy[i] + y;
				if (tx < 0 || tx >= m || ty < 0 || ty >= n || vis[tx][ty] || getx(tx) + getx(ty) > k) continue;
				Q.push(make_pair(tx, ty));
				vis[tx][ty] = 1;
				ans++;
			}
		}
		return ans;
	}
		
};



//BFS





int main() {
	int m = 56, n = 37, k = 10;
	Solution solution;
	cout << solution.movingCount(m, n, k) << endl;
	system("pause");
}