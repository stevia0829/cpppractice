#include<iostream>
#include<vector>

using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		recur(root, sum);
		return  res;
	}
	void recur(TreeNode* root,int target) {
		if (root == NULL) return;
		path.push_back(root->val);
		target -= root->val;
		if (target == 0 && root->left == NULL && root->right == NULL) {
			res.push_back(path);
		}
		recur(root->left, target);
		recur(root->right, target);
		path.pop_back();
	}
};
