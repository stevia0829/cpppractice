#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

int n, m, s;
int dis[100010], vis[100010];
vector<pii> g[100010];
priority_queue<pii, vector<pii>, greater<pii> > q;

void dijk()
{
	q.push(make_pair(0, s));
	dis[s] = 0;
	while (!q.empty())
	{
		int now = q.top.second(); q.pop();
		if (vis[now]) {
			continue;
		}
		vis[now] = 1;
		for (auto to : g[now])
		{
			int v = to.second, w = to.first;
			if (dis[now] + w < dis[v])
			{
				dis[v] = dis[now] + w;
				q.push({ dis[v],w });
			}
		}

	}
	return;
}

int main()
{
	cin >> n >> m >> s;
	int u, v, w;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ w,v });
	}
	memset(dis, 0x3f, sizeof(dis));
	dijk();
	for (int i = 1; i <= n; i++) {
		printf("%d%c",dis[i],(i==n)?'\n':' ');
	}
	system("pause");
	return 0;
}