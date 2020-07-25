#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//“记忆化搜索”
class Solution {
private:
	int  mem[100][100][100];
public:
	int removeBoxes(vector<int>& boxes) {
		int n = boxes.size();
		memset(mem, 0, sizeof(mem));
		return dfs(boxes, 0, n - 1, 0);
	}
	int dfs(vector<int>& boxes, int l, int r, int k) {
		if (l > r) return 0;
		int rr = r;
		int kk = k;

		while (l < r && boxes[r] == boxes[r - 1]) { r--; k++; }
		if (mem[l][r][k] > 0) return mem[l][r][k];
		int &ans = mem[l][r][k];
		ans = dfs(boxes, l, r - 1, 0) + (k + 1)*(k + 1);
		for (int i = l; i < r; i++) {
			if (boxes[i] == boxes[r]) {
				ans = max(ans, dfs(boxes, l, i, k + 1) + dfs(boxes, i + 1, r - 1, 0));
			}
		}

		return ans;
	}
};



int main() {
	vector<int> boxes = { 1, 3, 2, 2, 2, 3, 4, 3, 1 };
	Solution solution;
	int ans = solution.removeBoxes(boxes);
	cout << "结果是： " << ans << endl;
	system("pause");
}