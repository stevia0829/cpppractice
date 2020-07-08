#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

vector<pll> g[100005];
ll n, m, s;
ll dis[100005];
bool vis[100005];

queue<ll> q;
void spfa(ll n)
{
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	q.push(s);
	vis[s] =1;

	while (!q.empty())
	{
		ll now = q.front(); q.pop();
		vis[now] = 0;
		for (auto to : g[now])
		{
			ll w = to.second, v = to.first;
			if (dis[now] + w < dis[v])
			{
				dis[v] = dis[now] + w;
				if (vis[v] == 0)
				{
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m >> s;
	ll u, v, w;
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
	}
	spfa(n);
	for (int i = 1;i <= n; i++)
	{
		printf("%lld%c", dis[i], (i == n) ? '\n' : ' ');
	}
	system("pause");
	return 0;
}
}
/*
4 5 1
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
*/
