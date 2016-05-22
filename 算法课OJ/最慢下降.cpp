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

小明骑车下山，他想找到一条最长的路径滑行下去。区域由一个二维数组给出。数组的每个数字代表点的高度。下面SampleInput是一个例子，一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。事实上，这是最长的一条。

Input

输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。

Output

输出最长区域的长度。

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