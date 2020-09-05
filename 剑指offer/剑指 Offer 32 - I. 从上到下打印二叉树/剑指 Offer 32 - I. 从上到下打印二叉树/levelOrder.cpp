#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// 第一问

//class Solution {
//public:
//	vector<int> levelOrder(TreeNode* root) {
//		vector<int> res;
//		if (!root)
//			return res;
//		queue<TreeNode* > q;
//		q.push(root);
//		while (q.size()) {   // 试试可以直接用q
//			TreeNode* node = q.front();
//			q.pop();
//			res.push_back(node->val);
//			if (node->left) q.push(node->left);
//			if (node->right) q.push(node->right);
//		}
//		return res;
//	}
//};

// 第二问 需要分层

//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> res;
//		if (!root)
//			return res;
//		queue<TreeNode* > q;
//		q.push(root);
//		int i = 0;
//		while (q.size()) {   // 试试可以直接用q
//			int tmp = q.size();
//			res.push_back(vector<int>());
//			for(;tmp--;q.pop()){   // 也可以把q.pop()放在后面，for(int tmp=q.size;tmp>0;tmp--)
//				TreeNode* node = q.front();
//				res[i].push_back(node->val);
//				if (node->left) q.push(node->left);
//				if (node->right) q.push(node->right);
//			}
//			i++;
//		}
//		return res;
//	}
//};

// 别人的第二问
//class Solution {
//public:
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		if (root == NULL) return vector<vector<int>>();
//		queue<TreeNode *> queue;
//		vector<vector<int>> res;
//		int cnt = 0;
//		queue.push(root);
//		while (!queue.empty()) {
//			res.push_back(vector<int>());
//			for (int i = queue.size(); i > 0; --i) {
//				root = queue.front();
//				queue.pop();
//				res[cnt].push_back(root->val);
//				if (root->left != NULL) queue.push(root->left);
//				if (root->right != NULL) queue.push(root->right);
//			}
//			++cnt;
//		}
//		return res;
//	}
//};


// 第三问
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		queue<TreeNode* > q;
		q.push(root);
		int i = 0;
		while (q.size()) {   // 试试可以直接用q
			int tmp = q.size();
			res.push_back(vector<int>());
			for (; tmp--; q.pop()) {   // 也可以把q.pop()放在后面，for(int tmp=q.size;tmp>0;tmp--)
				TreeNode* node = q.front();
				res[i].push_back(node->val);
				//if (i % 2 != 0 && res[i].size()>1) {
				//	swap(res[i][0], res[i].back());
				//}
				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);

			}
			i++;
		}
		for (int i = 0; i < res.size(); i++) {  // 相对for(int i=1;i<reverse.size();i+=2) 速度更快
			if (i % 2 != 0) {
				reverse(res[i].begin(),res[i].end());
			}

		}
		return res;
	}
};
// test
int main() {
	int le = 1, ri = 1;
	ri += le | ri;

	cout << ri << endl;

	vector<int> tmp = { 1,2,3,4,5 };
	reverse(tmp.begin(), tmp.end());
	for (auto i : tmp) {
		cout << i << ' ';
	}
	cout << endl;
	system("pause");
}


