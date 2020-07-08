#pragma once
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
	int largest1BorderedSquare(vector<vector<int>>& grid) {
		if (grid.empty()) return 0;
		int max_len = 0, m = grid.size(), n = grid[0].size();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j]) {
					int cur_len = max_len;
					while (i + cur_len < m && j + cur_len < n) {
						bool flag1 = true;
						for (int temp_i = i, temp_j = j; temp_i < i + cur_len + 1 && temp_j < j + cur_len + 1; temp_i++, temp_j++) {
							if (grid[temp_i][j] * grid[i][temp_j] != 1) {
								flag1 = false;
								break;
							}
						}
						if (!flag1) break;

						bool flag2 = true;
						for (int temp_i = i + cur_len, _i = temp_i, temp_j = j + cur_len, _j = temp_j; temp_i > i && temp_j > j; temp_i--, temp_j--) {
							if (grid[temp_i][_j] * grid[_i][temp_j] != 1) {
								flag2 = false;
								cur_len++;
								break;
							}
						}
						if (!flag2) continue;
						max_len = ++cur_len;
					}
				}
			}
		}
		return max_len * max_len;
	}
};