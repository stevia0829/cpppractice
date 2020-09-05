#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root)
			return 0;
		int left = minDepth(root->left), right = minDepth(root->right);
		return (left && right) ? 1 + min(left, right) : 1 + left + right;
		//在三目运算符左侧的条件下(left && right)，
		//实际上1+left+right执行时该结点最多存在一个子树(1 + left + 0 || 1 + right + 0)
		//或者为叶子结点(1 + 0 + 0)。可以代入[1]、[1,null,2]两种树方便理解

	}
};

int main() {

}