#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct node
{
	ll sum, lazy;
};
#define maxn 100
int n, m;
int a[maxn];
node t[4 * maxn];

void build(int x, int l, int r)
{
	if (l == r)
	{
		t[x].sum = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(2 * x, l, mid);
	build(2 * x + 1, mid + 1, r);
	t[x].sum = t[2 * x].sum + t[2 * x + 1].sum;
}

int lowbit(int x)
{
	return x & (-x);
}
int sum(int x)
{
	int ret = 0;
	while (x) {
		ret += c[x], x -= lowbit(x);
		return ret;

	}
}

//µ¥µãÐÞ¸Ä
void change(int x, int tl, int tr, int p, int k)
{
	if (tl == tr)
	{
		t[x].sum += k;
		return;
	}
	int mid = (tl + tr) >> 1;
	if (p <= mid) change(2 * x, tl, mid, p, k); else change(2 * x + 1, mid + 1, tr, p, k);
	t[x].sum = t[2 * x].sum + t[2 * x + 1].sum;
}

int update(int x, int y, int z)
{
	int i = x;
	while (i <= n)
	{
		int y = y;
		while (j <= m)
		{
			c[i][j] += z;
			j += lowbit(j);
		}
		i += lowbit(i);
	}
}

ll ask(int x, int tl, int tr, int l, int r)
{
	if (tl == 1 && tr == r) return t[x].sum;
	int mid = (tr + tl) >> 1;
	if (r <= mid) return ask(2 * x, tl, mid, l, r);
	if (l > mid) return ask(2 * x + 1, mid + 1, tr, l, r);
	else
	{
		return ask(2 * x, tl, mid, l, mid) + ask(2 * x + 1, mid + 1, tr, mid + 1, r);
	}
}

void change(int x, int tl, int tr, int l, int r)
{
	if (tl == l && tr == r)
	{
		t[x].lazy == k;
		return;
	}
	if (t[x].lazy) update(x, tl, tr);
	int mid = (tr + tl) >> 1;
	if (r <= mid) return change(2 * x, tl, mid, l, r);
	if (l > mid) return change(2 * x + 1, mid + 1, tr, l, r);
	t[x].sum = t[2 * x].sum +(mid-tl+1)*t[2*x].lazy+ t[2 * x + 1].sum+(tr-mid)*t[2*x+1].lazy;
}