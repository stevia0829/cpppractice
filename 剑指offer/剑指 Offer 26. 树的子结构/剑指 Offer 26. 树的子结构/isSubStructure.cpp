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
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		
		return(A != NULL && B != NULL) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
	}
	bool recur(TreeNode*A, TreeNode* B) {
		if (!B)return true;
		if (!A || A->val != B->val)return false;
		return recur(A->left, B->left) && recur(A->right, B->right);
	}
	// 27 Ìâ´ð°¸
	TreeNode* mirrorTree(TreeNode* root) {
		if (!root) return NULL;
		TreeNode* tmp = root->left;
		root->left = mirrorTree(root->right);
		root->right = mirrorTree(tmp);
		return root;

	}


};


int main() {


}