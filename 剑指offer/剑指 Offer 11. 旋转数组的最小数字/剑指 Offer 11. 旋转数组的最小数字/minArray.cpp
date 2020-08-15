#include<iostream>
#include<vector>

using namespace std;

//class Solution {
//public:
//	int minArray(vector<int>& numbers) {
//		int res = numbers[0];
//		for (int i = 0; i < numbers.size() - 1; i++)
//		{
//			if (numbers[i] > numbers[i + 1])
//			{
//				res = numbers[i + 1];
//				break;
//			}
//		}
//		return res;
//	}
//};

//¶ş·Ö²éÕÒ

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int low = 0, high = numbers.size()-1;
		while (low<high)
		{
			int mid = (low + high) / 2;
			if (numbers[mid] < numbers[high])
				high = mid;
			else if (numbers[mid] > numbers[high])
				low = mid + 1;
			else high = high - 1;

		}
		return numbers[low];
	}
};

int main() {
	vector<int> numbers = {9,7,6,5,1};
	Solution solution;
	cout << solution.minArray(numbers) << endl;
	system("pause");
}