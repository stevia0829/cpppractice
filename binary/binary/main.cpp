#include<cstdio>
#include<iostream>

using namespace std;

double l, r, mid;
//伪代码
//while (right - left > eps)
//{
//	mid = (right + left) / 2;
//	if (judge(mid)) left = mid;
//	else right = mid;
//
//}
//return mid;
//while (l <= r)
//{
//	int mid = (l + r) >> 1;
//	if (judge(mid0))
//	{
//		ans = mid;
//		l = mid + 1;
//	}
//	else r = mid - 1;
//}
//最小值最大 最大值最小 常用
//三分法
//while (f(lmid) !=max))
//{
//	if (f(lmid) > f(rmid))
//	{
//		lmid = (rmid - l) / 3;
//		rmid = 2 * (rmid - l) / 3;// 即区间变为[l,rmid]
//	}
//	else 
//	{
//		lmid = (r - lmid) / 3;
//		rmid = 2 * (r - lmid) / 3;
//	}
//}

//快速幂
//a^b mod p
// b做二进制拆分
//a^b=a^b1+a^b2+......a^bk;
//复杂度o(logb)

int quickpow(int a, int p, int mod)
{
	int ans = 1; a = a % mod;
	while (p)
	{
		if (p & 1) ans = (ans*a) % mod;
		p >> 1;
		a = (a*a) % mod;
	}
	return ans;
}

// 矩阵快速幂
//eg:fibonaci
//(Fn Fn - 1) = (1 1;1 0)^(n-1)*(F1 F0)
//推广至：Fi=a*Fi-1+b*Fi-2
