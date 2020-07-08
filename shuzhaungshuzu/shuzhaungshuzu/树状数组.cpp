#include<iostream>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int c[100005];
int n,m;
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

int change(int i, int k)
{
	while (i<=n)
	{
		c[i] += k, i += lowbit(i);
	}
}

int update(int x, int y, int z)
{
	int i = x;
	while (i<=n)
	{
		int y = y;
		while (j<=m)
		{
			c[i][j] += z;
			j += lowbit(j);
		}
		i += lowbit(i);
	}
}
//sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]

int sum2(int x, int y)
{
	int res = 0, i = x;
	while (i>0)
	{
		int j = y;
		while (j>0)
		{
			res += c[i][j];
			j -= lowbit(j);
		}
		i -= lowbit(i);
	}
	return res;
}