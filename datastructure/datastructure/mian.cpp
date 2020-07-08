#include<iostream>
#include<queue>

using namespace std;

static const int maxn = 10000;
int cnt;
int maze[5][5] = {
	0,1,0,0,0,
	0,1,0,1,0,
	0,0,0,0,0,
	0,1,1,1,0,
	0,0,0,1,0,
};
//int maxn;
//int stack[maxn];
//struct Edge
//{
//	int to;
//	int next;
//	int val;
//
//}e;
//int head[maxn];
//void add(int u, int v, int w)
//{
//	e[++cnt].to = v;
//	e[cnt].val = w;
//	e[cnt].next = head[u];
//	head[u] = cnt;
//}
int main()
{
	//int l, r;
	//cin >> l >> r;
	//cin.get();

}
//void exgcd(int a, int b, int &x, int &y)
//{.....}
//int china()
//{
//	int ans = 0, lcm = 1, x, y;
//	for (int i = 1; i <= k; ++i)lcm *= b[i];
//	for (int i = 1; i <= k; ++i)
//	{
//		int tp = lcm / b[i];
//		exgcd(tp, b[i], x, y);
//		x = (x%b[i] + b[i]) % lcm;
//		ans = (ans + tp * x*a[i]) % lcm;
//	}
//	return(ans + lcm) % lcm;
//}
void euler()
{
	for (int i = 2; i < maxn; i++)
	{
		if(!E[i])
			for (int j = i; j < maxn; j++) {
				if (!E[j])E[j] = j;
				E[j] = E[j] / i * (i - 1);
			}
	}
}