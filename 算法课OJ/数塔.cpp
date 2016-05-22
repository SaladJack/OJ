#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
Description

在讲述DP算法的时候，一个经典的例子就是数塔问题，它是这样描述的： [ [2], [3,4], [6,5,7], [4,1,8,3] ] 有如下所示的数塔，要求从顶层走到底层，若每一步只能走到相邻的结点，则经过的结点的数字之和最大是多少？

Input

输入数据首先包括一个整数C,表示测试实例的个数，每个测试实例的第一行是一个整数N(1 <= N <= 100)，表示数塔的高度，接下来用N行数字表示数塔，其中第i行有个i个整数，且所有的整数均在区间[0,99]内。

Output

对于每个测试实例，输出可能得到的最大和，每个实例的输出占一行。
*/

int main(){
	int T;
	cin >> T;
	while (T--)
	{
		int num;
		cin >> num;
		vector<vector<int> > a(num+1, vector<int>(num+1, 0));
		for (int i = 1; i <= num; ++i)
			for (int j = 1; j <= i;++j)
		{
			cin >> a[i][j];
		}
		vector<vector<int> > dp(num + 1, vector<int>(num + 1, 0));
		int res = 0x80000000;
		for (int i = 1; i <= num; ++i)
			for (int j = 1; j <= i; ++j)
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
				if (i==num)
				{
					res = max(res, dp[i][j]);
				}
			}
		cout << res << endl;
		
	}

}