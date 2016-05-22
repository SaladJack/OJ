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

���Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��� �����Ӵ�������˼�壬���ַ���������������ʵ��Ӵ��� ����һ��ֻ��СдӢ���ַ�a,b,c��x,y,z��ɵ��ַ����������������Ļ����Ӵ��ĳ��ȡ�

Input

��������������������ÿ�������������һ����СдӢ���ַ�a,b,c��x,y,z��ɵ��ַ������ַ����ĳ��Ȳ�����200000��

Output

����ÿ��������������һ����������ʾ��������������ַ������������ĵ�������Ӵ��ĳ��ȡ�

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
			p1 = FromeCenter(i, i, n);//��λ��iΪ���ĵ�������ַ���
			if (p1 > max)
				max = p1;

			p2 = FromeCenter(i, i + 1, n);//��i��i+1֮���λ��Ϊ���ĵ�������ַ���
			if (p2 > max)
				max = p2;
		}
		printf("%d\n", max);
		memset(a, 0, sizeof(a));
	}
	return 0;
}