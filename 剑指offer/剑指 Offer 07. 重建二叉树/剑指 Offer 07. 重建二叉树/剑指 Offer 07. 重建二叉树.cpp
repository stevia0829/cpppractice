#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<string>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
	 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 //class Solution {
 //private:
	//unordered_map<int, int> indexmap;

 //public:
	// TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	//	 if (preorder.size() == 0)
	//	 {
	//		 return NULL;
	//	 }	
	//	 
	//	 int length = preorder.size();
	//	 for (int i = 1; i < length; i++)
	//	 {
	//		 indexmap.insert(make_pair(inorder[i], i));
	//	 }
	//	 return recursion(preorder, inorder, 0, length - 1, 0, length - 1);

	//	 // TreeNode root=buildTree(vector<int>& preorder)
	// }
	// TreeNode *recursion(vector<int>& preorder, vector<int>& inorder,int preorder_start, int preorder_end, int inorder_start, int inorder_end) // 根节点先序下标，左子树中序起始下标，右子树中序结束下标
	// {
	//	 if (preorder_start > preorder_end) return NULL;
	//	 int rootVal = preorder[preorder_start];
	//	 TreeNode *root = new TreeNode(rootVal);
	//	 int root_index = indexmap.find(rootVal)->second; // 对应值相对应的索引值   indexmap[rootval] 提取索引值对应的元素
	//	 int leftNodes = root_index - inorder_start, rightNodes = inorder_end - root_index;
	//	 root->left =recursion(preorder, inorder,preorder_start + 1, preorder_start + leftNodes, inorder_start, root_index - 1);
	//	 root->right = recursion(preorder, inorder, preorder_end - rightNodes + 1, preorder_end, root_index + 1, inorder_end);
	//	 return root;
	// }

 //};

 class Solution {
 public:
	 TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		 int len = inorder.size();
		 preorder1.assign(preorder.begin(), preorder.end());//拷贝
		 for (int i = 0; i < len; i++) {
			 m.insert(make_pair(inorder[i], i));   //中序遍历数组插入哈希map 查找为o(1)
		 }
		 return recursion(0, 0, len - 1);
	 }
	 TreeNode *recursion(int pre_root, int in_left, int in_right) { //根节点先序下标，左子树中序起始下标，右子树中序结束下标
		 if (in_left > in_right) return NULL;
		 TreeNode *root = new TreeNode(preorder1[pre_root]);
		 int temp = m.find(preorder1[pre_root])->second;  //当前根节点的中序下标
		 root->left = recursion(pre_root + 1, in_left, temp - 1);
		 root->right = recursion(temp - in_left + 1 + pre_root, temp + 1, in_right);//右子树根节点的前序下标=左子树节点数+pre_root 左子树节点数=temp-in_left+1
		 return root;
	 }

 private:
	 unordered_map<int, int> m;
	 vector<int> preorder1;
 };
  //打印二叉树
 //void TreePrint(TreeNode* root)
 //{
	// queue<TreeNode *> q;
	// q.push(root);
	// while (!q.empty()) {
	//	 vector<TreeNode*> cache;
	//	 //取出队列中位于同一行的结点 放到cache中 
	//	 while (!q.empty()) { cache.push_back(q.front()); q.pop(); }
	//	 string line = "                           ";
	//	 for (int i = 0; i < cache.size(); i++)
	//	 {
	//		 TreeNode* p = cache[i];
	//		 //遍历同一行的结点 按照它们在中序序列的位置 修改在line中的位置 
	//		 if (p)
	//		 {
	//			 line[midT.find(p->val)] = p->val;
	//			 //将结点的左右孩子入队 
	//			 if (p->left) q.push(p->left);
	//			 if (p->right) q.push(p->right);
	//		 }
	//	 }
	//	 //输出之前修改的line 
	//	 cout << line << endl;
	// }
 //}
 void print_tree(TreeNode* root)
 {

 }

 int main()
 {
	 Solution solution;
	 //vector<int> preoder = { 3,9,20,15,7 };
	 //vector<int> inoder = { 9,3,15,20,7 };
     vector<int> preoder = {1,2 };
	 vector<int> inoder = { 1,2};
	 solution.buildTree(preoder,inoder);
	
 }