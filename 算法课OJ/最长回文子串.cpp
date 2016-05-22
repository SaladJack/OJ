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
using namespace std;
/*
Description

回文串就是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。 回文子串，顾名思义，即字符串中满足回文性质的子串。 给出一个只由小写英文字符a,b,c…x,y,z组成的字符串，请输出其中最长的回文子串的长度。

Input

输入包含多个测试用例，每组测试用例输入一行由小写英文字符a,b,c…x,y,z组成的字符串，字符串的长度不大于200000。

Output

对于每组测试用例，输出一个整数，表示该组测试用例的字符串中所包含的的最长回文子串的长度。

*/
char a[200010];
int FromeCenter(int l, int r, int n)
{
	while (l >= 0 && r <= n - 1 && a[l] == a[r])
	{
		l--; r++;
	}
	return ((r - 1) - (l + 1) + 1);
}
int main()
{
	int i, j, n, m, max, p1, p2;
	while (scanf("%s", a) != EOF)
	{
		n = strlen(a);
		max = 0;
		for (i = 0; i < n; i++)
		{
			p1 = FromeCenter(i, i, n);//以位置i为中心的最长回文字符串
			if (p1 > max)
				max = p1;

			p2 = FromeCenter(i, i + 1, n);//以i和i+1之间的位置为中心的最长回文字符串
			if (p2 > max)
				max = p2;
		}
		printf("%d\n", max);
		memset(a, 0, sizeof(a));
	}
	return 0;
}