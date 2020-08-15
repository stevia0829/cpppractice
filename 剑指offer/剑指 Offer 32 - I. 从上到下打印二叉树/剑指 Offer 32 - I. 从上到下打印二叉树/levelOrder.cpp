#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		vector<int> res;
		queue<TreeNode* > q;
		q.push(root);

	}
};

