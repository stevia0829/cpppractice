#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
	 vector<int> reversePrint(ListNode* head) {
		 // 方法1 reverse法
		 vector<int> res;
		 while (head)
		 {
			 res.push_back(head->val);
			 head = head->next;
		 }
		 reverse(res.begin(), res.end());
		 return res;
	 }
 };
 //方法2：入栈法
/*
stack<int> s;
//入栈
while(head){
	s.push(head->val);
	head = head->next;
}
//出栈
while(!s.empty()){
	res.push_back(s.top());
	s.pop();
}
return res;
*/

//方法3：递归
/*
if(head == nullptr)
	return res;
reversePrint(head->next);
res.push_back(head->val);
return res;
*/

//方法4：改变链表结构
 ListNode *pre = nullptr;
 ListNode *next = head;
 ListNode *cur = head;
 while (cur) {
	 next = cur->next;//保存当前结点的下一个节点
	 cur->next = pre;//当前结点指向前一个节点，反向改变指针
	 pre = cur;//更新前一个节点
	 cur = next;//更新当前结点
 }
 while (pre) {//上一个while循环结束后，pre指向新的链表头
	 res.push_back(pre->val);
	 pre = pre->next;
 }
 return res;
	}
};

作者：wangxiaole
链接：https ://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/solution/csan-chong-jie-fa-reversefan-zhuan-fa-dui-zhan-fa-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


 int main() {
	 vector<int> num = { 1,3,2 };
	 ListNode *head,*tail, *p;;
	 head = (ListNode*)malloc(sizeof(ListNode));
	 tail = head;
	 for (auto i : num)
	 {
		 p = (ListNode*)malloc(sizeof(ListNode));
		 p->val = i;
		 tail->next = p;
		 tail = p;
		 tail->next = NULL;
	 }
	 	 p = head->next;
	 while (p)
	 {
		 printf("%d", p->val);
		 p = p->next;
		 if (p)
			 printf(" ");
		 else
			 printf("\n");
	 }

	 Solution solution;
	 vector<int>result=solution.reversePrint(head->next);
	 for (auto j : result)
	 {
		 cout << j << ' ';
	 }
	 cout << endl;
	 system("pause");
 

 }

 //两种构造函数

 //#include <stdio.h>
//#include <stdlib.h>
// typedef struct LNode
// {
//	 int data;
//	 struct LNode *next;
// }LNode;
// //输入函数
// LNode *input(int n)
// {
//	 LNode *head, *tail, *p;
//	 head = (LNode*)malloc(sizeof(LNode));
//	 tail = head;
//	 for (int i = 0; i < n; i++)
//	 {
//		 p = (LNode*)malloc(sizeof(LNode));
//		 scanf("%d", &p->data);
//		 tail->next = p;
//		 tail = p;
//		 tail->next = NULL;
//	 }
//	 return head;
// }
// void output(LNode *head)
// {
//	 LNode *p;
//	 p = head->next;
//	 while (p)
//	 {
//		 printf("%d", p->data);
//		 p = p->next;
//		 if (p)
//			 printf(" ");
//		 else
//			 printf("\n");
//	 }
// }
// int main()
// {
//	 LNode *head;
//	 int n;
//	 scanf("%d", &n);
//	 head = input(n);
//	 output(head);
//	 return 0;