#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class CQueue {
	stack<int> stack1, stack2;
public:
	CQueue() {
		stack<int>().swap(stack1);
		stack<int>().swap(stack2);
	}
	// 直接与空栈交换速度更快
	//CQueue() {
	//	while (!stack1.empty()) {
	//		stack1.pop();
	//	}
	//	while (!stack2.empty()) {
	//		stack2.pop();
	//	}
	//}

	void appendTail(int value) {
		stack1.push(value);
	}

	int deleteHead() {
		// 如果第二个栈为空
		if (stack2.empty()) {
			while (!stack1.empty()) {
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.empty()) {
			return -1;
		}
		else {
			int deleteItem = stack2.top();
			stack2.pop();
			return deleteItem;
		}
	}
};


int main()
{
	CQueue* test = new CQueue;
	test->appendTail(1);
	test->appendTail(2);
	int param_2 = test->deleteHead();
	int param_3 = test->deleteHead();
	cout << param_2 <<" "<<param_3<< endl;
	system("pause");
}