#include<iostream>
#include<vector>
#include<stdlib.h>
#include <algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
map<pii, int> mp;
vector<int> ans;
int n,m;
vector<int> a[10];
queue<int> q;
bool vis[12];
int dis[12];

void display() {
	for (int i = 0; i<ans.size(); i++)
	{
		printf("%5d", ans[i]);
	}
	putchar('\n');
	return;
}

void dfs1(int num) 
{

	if (num == n + 1)
	{
		display();
		return;
	}
	for (int i=1; i <= n; i++) {
		if (!vis[i]) {              //(vis[i]==0)效果类似
			ans.push_back(i);
			vis[i] = 1;
			dfs1(num + 1);
			ans.pop_back();
			vis[i] = 0;
		}
	}
	return;
}

void dfs2(int now) {
	vis[now] = 1;
	for (auto to : a[now]) {
		if (!vis[to]) {
			dfs2(to);
		}
	}
	return;
}

void bfs(int st) {
	q.push(st);
	memset(dis, 0x3f, sizeof(dis));//初始化为正无穷
	dis[st] = 0;
	vis[st] = 1;
	while (!q.empty()){
		int now = q.front(); q.pop();
		for (auto to : a[now]) {
			if (!vis[to]) {
				dis[to] = min(dis[to], dis[now]+1);
				q.push(to);
				vis[to] = 1;
			}
		}
	}
	return;
}

int main()
{
	//cin >> n;
	//dfs1(1);

	// pair 和map 的用法
	//pii p = {1,1};
	//p.first = 1; p.second = 1; 效果与上一步相同
	//mp[p] = 1;
	//cout << mp[p] << endl;

	// 利用next_permutation 写dfs
	//for (int i = 1; i <= n ; i++) {
	//	ans.push_back(i);
	//}
	//do
	//{
	//	display();
	//} while (next_permutation(ans.begin(),ans.end()));

	// 类似于python 的lamda函数
	//a[1].push_back(1);
	//a[1].push_back(2);
	//a[1].push_back(3);
	//a[1].push_back(4);
	//for (auto t : a[1]) {  //auto 自动识别数据类型
	//	printf("%d", t);
	//
	//}
	cin >> n >> m;
	int u, v;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	bfs(1);
	for (int i = 1; i <= n; i++) {
		printf("%d%c",vis[i],(i==n)? '\n':' ');
	}
	//cin.get();
	//cin.get();
	system("pause");
	return 0;
}
/*
7 6
1 2
2 4
1 3
2 5
3 7
3 6
*/
//DFS

//int check(参数)
//{
//	if (满足条件)
//		return 1;
//	return 0;
//}
//
//void dfs(int step)
//{
//	判断边界
//	{
//		相应操作
//	}
//		尝试每一种可能
//	{
//		   满足check条件
//		   标记
//		   继续下一步dfs(step + 1)
//		   恢复初始状态（回溯的时候要用到）
//	}
//}

/*
树的直径（最远两个节点的距离）通过两个dfs 就可以求
1.任取一个节点  求与其最远的节点
2.找到这个最远的节点 再求一次dfs 求与这个节点最远的节点 距离就是最远路径
*/
