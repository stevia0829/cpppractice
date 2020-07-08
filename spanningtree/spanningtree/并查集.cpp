#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
int father[100005],depth[100005];
// 建立标记数组
void init() {
	for (int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
}


//int find(int x) //非递归
//{
//	while (father[x]!=x)
//	{
//		x = father[x];
//	}
//	return x;
//}

int find(int x) //递归
{
	if (father[x] != x)
		return find(father[x]);
	else
		return x;
}
// x y是否都属于同一集合
bool judge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y)
	{
		return true;
	}
	else
		return false;
}

// 合并
void union1(int x, int y) //注意union 是c++的关键字 不能随便用
{
	x = find(x);
	y = find(y);
	father[y] = x;
}

// 优化
int find(int x)
{
	if (father[x] != x)
	{
		father[x] = find(father[x]);
	}
	return father[x];
}
// 非递归写法  速度更快
//int find(int x) {
//	int r = x, q;
//	while (r!=father[r])
//	{
//		q = father[x];
//		father[x] = r;
//		x = q;
//	}
//	return r;
//}
// 复杂度稳定

// 按秩合并（启发式合并）
void init()
{
	int i;
	for (i = 1; i <= n; i++) {
		father[i] = i;
		depth[i] = 0;
	
	}
}

void union1(int x, int y)
{
	int fx = find(x), fy = find(y);
	if (depth[fx] > depth[fy])
		father[fy] = fx;
	else
	{
		father[fx] = fy;
		if (depth[fx] == depth[fy])
			depth[fy]++;
	}
}