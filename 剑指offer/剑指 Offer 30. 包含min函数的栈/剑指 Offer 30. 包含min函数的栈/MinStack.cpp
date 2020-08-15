#include<iostream>
#include<stack>
#include<pair>

using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	//最小栈 
	 // stack中存放pair<int,int> first为val second为min_val
	stack<pair<int, int>> min_stack;
	int min_val;
	MinStack() {
		min_val = INT_MAX;


	}

	void push(int x) {
		if (x <= min_val) {
			min_val = x;
		}
		min_stack.push({ x,min_val });
	}

	void pop() {
		if (!min_stack.empty()) {
			min_stack.pop();

		}
		if (min_stack.empty()) {
			min_val = INT_MAX;
		}
		else
		{
			min_val = min_stack.top().second;
		}
	}

	int top() {
		return min_stack.top().first;
	}

	int min() {
		return min_stack.top().second;
	}
};

int main() {

}