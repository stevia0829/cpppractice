#include<iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return recur(root->left, root->right);
	}
	bool recur(TreeNode* L, TreeNode* R) {
		if (!L && !R) return true;
		if (!L || !R || (L->val != R->val)) return false;
		return (recur(L->left, R->right) && recur(L->right, R->left));
	}
};