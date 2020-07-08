#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
int father[100005], depth[100005];

// 有点问题
struct Edge
{
	int from, to, value;
	// from  和 to是两端点 value 是边权
	bool operater < (const Edge& rhs)const
	{
		return value < rhs.value;
	}
};

int find(int x)
{
	if (father[x] != x)
	{
		father[x] = find(father[x]);
	}
	return father[x];
}
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

int Kruskal(Edge* edges, int m)
{//edges是边集，m是边集的大小
	sort(edges, edges + m);//按权从小到大排序
	int ret = 0;//生成权
	for(int i=1;i<m;i++)
	{
		if (find(edges[i].from == find(edges[i].to)))
			continue;//已经在同一联通块中
		ret += edges[i].value;// 将边权加入生成权
		union1(edges[i].from, edges[i].to);// 合并联通快
	}
	return ret;
}

