#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int deg[100005]; //deg[i] 表示i的入度
int vis[100005];
vector<int> g[100005];
queue<int> q;
int T, n, m, u, v;

bool toposort() {
	int num = 0;    // num是已经排好序的点的个数
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		num++;
		for (auto to : g[num]) {
			if (vis[to]) { continue; }
			else {
				deg[to]--;
				if (!deg[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}

	}
	if (num == n) { return true; }
	else { return false; }

}

int main() {
	cin >> T;
	while (T--) {
		memset(deg,0,sizeof(deg));
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= 10000; i++) {
			g[i].clear();
		}
		while (!q.empty()) {
			q.pop();
		}
		//以上是初始化
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> u >> v;
			g[u].push_back(v);
			deg[v]++;
		}
		for (int i = 1; i < n; i++) {
			if (!deg[i]) {
				vis[i] = 1;
				q.push(i);
			}
		}
		if (toposort()) {
			puts("correct");
		}
		else {
			puts("wrong");
		}
	}
	system("pause");
	return 0;
}

/*
while 队列非空
取队首点P
访问P的所有相邻点Q，将其入度减一
若Q此时入度为0 Q入列
*/