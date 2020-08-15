#include<iostream>
#include<vector>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* p = head;
		ListNode* res = head;
		int i = 0;
		while (p) {
			p = p->next;
			i++;
			if (i > k) res = res->next;
		}
		return res;
	}
	ListNode* buildlistnode(vector<int> &nums) {
		ListNode* res;
		res = (ListNode *)malloc(sizeof(ListNode));
		ListNode* p = res;
		for (auto i : nums) {
			ListNode *node = new ListNode(i);
			p->next = node;
			p = node;
		}
		res = res->next;//第一项就是开辟空间的
		//p->next = NULL;
		return res;
	}

	// reverse 方法1
	ListNode* reverseList(ListNode* head) {
		ListNode* cur = NULL, *pre = head;
		while (pre != NULL) {
			ListNode* t = pre->next;
			pre->next = cur;
			cur = pre;
			pre = t;
		}
		return cur;
	}

	//递归
	//ListNode* reverseList(ListNode* head) {
	//	if (head == NULL || head->next == NULL) return head;
	//	ListNode* cur = reverseList(head->next);
	//	head->next->next = head;
	//	head->next = NULL;
	//	return cur;
	//}

};



int main() {
	Solution solution;
	vector<int> nums = { 1,2,3,4,5 };
	ListNode* res = solution.buildlistnode(nums);
	ListNode* p = res;
	cout << "原链表" << endl;
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}
	cout << endl;

	ListNode *ans = solution.getKthFromEnd(res, 2);
	while (ans) {
		cout << ans->val << ' ';
		ans = ans->next;
	}
	cout << endl;

	ListNode *ans_rev =solution.reverseList(res) ;
	while (ans_rev) {
		cout << ans_rev->val << ' ';
		ans_rev = ans_rev->next;
	}
	cout << endl;

	system("pause");
}