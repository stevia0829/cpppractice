#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
//
//int n, m, s;
//int dis[100010], vis[100010];
//vector<pii> g[100010];
priority_queue<pii, vector<pii>, greater<pii> > q;

// d[k][i][j]=min(d[k-1][i][j],d[k-1][i][k],d[k-1][k][j])

int g[110][110], n, m;
int main()
{
	cin >> n >> m;
	int u, v, w;
	memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	for (int i = 1; i <= n; i++) {
		g[i][i] = 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d%c", g[i][j], (j == n) ? '\n' : ' ');
		}
	}
	system("pause");
	return 0;
}