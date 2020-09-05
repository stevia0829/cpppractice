#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return new TreeNode(head->val);
		// 第一步找链表中点
		ListNode* pre = head;
		ListNode* p = pre->next;
		ListNode* q = p->next;
		while (q!=NULL && q->next!=NULL)
		{
			pre = pre->next;
			p = p->next;
			q = q->next->next;
		}
		// 得到的p即为中点,将其分开
		pre->next = NULL;
		TreeNode* root = new TreeNode(p->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(p->next);
		return root;
	}
	
};