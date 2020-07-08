#pragma once
#include<iostream>
using namespace std;
#define maxn 100
class Solution {
public:
	int numTrees(int n) {
		int G[maxn] = {0};
		G[0] = 1;
		G[1] = 1;
		for (int i=2; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				G[i]+= G[j-1] * G[i - j];	
			}
		}
		return G[n];
	}
};