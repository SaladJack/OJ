#include<iostream>  
#include<string>  
#include <stdio.h>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
/*
Description

С���ﳵ��ɽ�������ҵ�һ�����·��������ȥ��������һ����ά��������������ÿ�����ִ����ĸ߶ȡ�����SampleInput��һ�����ӣ�һ���˿��Դ�ĳ���㻬���������������ĸ���֮һ�����ҽ����߶ȼ�С��������������У�һ���ɻ��еĻ���Ϊ24-17-16-1����Ȼ25-24-23-...-3-2-1��������ʵ�ϣ��������һ����

Input

����ĵ�һ�б�ʾ���������R������C(1 <= R,C <= 100)��������R�У�ÿ����C������������߶�h��0<=h<=10000��

Output

��������ĳ��ȡ�

*/
using namespace std;
int ans[101][101];
int map[101][101]; 
int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int N, M;
int max(int a, int b)
{
	return a > b ? a : b;
}
int dp(int i, int j) 
{
	if (ans[i][j] > 0) return ans[i][j];

	int t, tempi, tempj;
	int maxn = 0;
	for (t = 0; t < 4; t++)
	{
		tempi = i + dir[t][0];
		tempj = j + dir[t][1];
		if (tempi > 0 && tempi <= N&&tempj > 0 && tempj <= M) 
		{
			if (map[tempi][tempj] < map[i][j]) 
				maxn = max(maxn, dp(tempi, tempj));
		}
	}
	return ans[i][j] = maxn + 1;
}
int main()
{
	while (~scanf("%d%d", &N, &M))
	{
		int answer = 0;
		int i, j;
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		memset(ans, 0, sizeof(ans));
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= M; j++)
			{
				ans[i][j] = dp(i, j);
				answer = max(answer, ans[i][j]);
			}
		}
		printf("%d\n", answer);
	}
	return 0;
}