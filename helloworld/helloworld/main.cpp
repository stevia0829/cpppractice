#include<iostream>
#include<string>
using namespace std;
//构造函数
struct node
{
	int a;
	node(int _a = 0)
	{
		a = _a;
	}
};

int main()
{
	//int number;

	string line;
	int *b = new int[100];
	delete[] b;
	/*动态开辟内存,基本不太用到*/
	getline(cin, line);
	/*int b[number],不支持动态素组*/
	/*int& a = number;
	int* b = &number;
	函数指针，前者使用时不用加符号
	例如：
	viod swapInt(int& a,int& b)
	{
	   int c=a;
	   a=b;
	   b=c;
	}*/
	/*c++中以函数名+参数列表来区分函数*/
	//int dfs(int u = 1或者 int a,int b=0)
	//{
	//主要用于递归函数 
	//}
	//调用的函数 dfs();dfs(a),dfs(a,b)
	bool boolean = true;
	const char* cString = "Hello";
	string cppstring = "world";
	cout << "hello world!" << endl;

	cout << boolean << endl;
	cout << cString << endl;
	cout << cppstring << endl;
	cout << line << endl;
	cin.get();
	cin.get();
	int a;
	while (cin >> a)
	{
	}

	return 0;
}