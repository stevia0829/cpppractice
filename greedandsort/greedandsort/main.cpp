#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm> 
using namespace std;
int m, n, j, i, ans;
priority_queue<int, vector<int>, greater<int> >q;
int main()
{
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> m;
		q.push(m);
	}
	for (i = 1; i < n; i++)
	{
		int p1 = q.top(); q.pop();
		int p2 = q.top(); q.pop();
		ans += p1 + p2;
		q.push(p1 + p2);

	}
	cout << "answer is:"<<ans << endl;
	//cin.get();
	cin.get();
	return 0;
}
// 结构体排序
struct student 
{
	char name[5];
	int score;
}stu[100];
bool cmp(student p, student q)
{
	return p.score > q.score;
};
//sort(stu + 1, stu + 1 + n, cmp);
//vector 排序 sort(v.begin(),v.end(),cmp)
//priority_queue push 自动排序
//nth_element(a+l,a+k,a+r) 使a中[l,r)区间内第k小处于第k位