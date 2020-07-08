#include<iostream>
#include<string>

using namespace std;

//string s1();
//string s2("hello");
//string s3(4, 'k');//s3="kkkk"
//string s4 ("12345", 1, 3);//s4="234",即“12345”的从下标1开始，长度为3的子串
const static int maxn = 10000;


//+ += append compare substr()求子串 empty() 判断为空
//find: 从前往后查找子串或字符出现的位置
//rfind：从后往前查找子串或字符出现位置
//find_first_of:从前往后查找何处出现另一个字符串中包含的字符。
//s1.find_first_of("abc") 第一次出现“abc”的位置
//find_last_of find_first_not_of find_last_not_of
//replace erase substr push_back(char c)


int tree[maxn][30];//字典树
int tot;
void insert_(char *str)
{
	int len = strlen(str);
	int root = 0;
	for (int i = 0; i < len; i++)
	{
		int id = str[i] - 'a';
		if (!tree[root][id]) tree[root][id] = ++tot;
		root = tree[root][id];

	}
}
int find_(char *str)
{
	int len = strlen(str);
	int root = 0;
	for (int i = 0; i < len; i++)
	{
		int id = str[i] - 'a';
		if (!tree[root][id])return 0;
		root = tree[root][id];
	}
}
int main()
{
	int t, q;
	char s[20];
	cin >> t >> q;
	while (t--)
	{
		cin >> s;
		insert_(s);
	}
	while (q--)
	{
		cin >> s;
		if (find_(s))cout << "yes" << endl;
		else cout << "No" << endl;
		cin.get();
	}
}