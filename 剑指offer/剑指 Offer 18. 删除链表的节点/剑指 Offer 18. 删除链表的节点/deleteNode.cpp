#include<iostream>
#include<vector>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 //µÝ¹é
class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head) return head;
		if (head->val == val) return head->next;
		head->next = deleteNode(head->next, val);
		return head;
	}
};
 
 // µ¥Ö¸ÕëÉ¨Ãè·¨
//class Solution {
//public:
//	ListNode* deleteNode(ListNode* head, int val) {
//		if (!head) return head;
//		if (head->val == val) return head->next;
//		ListNode* p=head;
//		while (p->next&&p->next->val!=val)
//		{
//			p = p->next;
//		}
//		if (p->next && p->next->val == val)  p->next = p->next->next;
//		return head;
//	}
//};

int main() {

}