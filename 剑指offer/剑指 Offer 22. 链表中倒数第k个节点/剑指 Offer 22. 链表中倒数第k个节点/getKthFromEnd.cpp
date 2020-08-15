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
		ListNode* res=head;
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
			ListNode *node =new ListNode(i);
			p->next = node;
			p = node;
		}
		res = res->next;
		p->next = NULL;
		return res;
	}
};



int main() {
	Solution solution;
	vector<int> nums = { 1,2,3,4,5 };
	ListNode* res = solution.buildlistnode(nums);
	ListNode* p = res;
	cout << "Ô­Á´±í" << endl;
	while (p) {
		cout << p->val << ' ';
		p=p->next;
	}
	cout << endl;
	ListNode *ans = solution.getKthFromEnd(res,2);
	while (ans) {
		cout << ans->val << ' ';
		ans = ans->next;
	}
	system("pause");
}