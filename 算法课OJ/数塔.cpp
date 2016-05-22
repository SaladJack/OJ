#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
Description

�ڽ���DP�㷨��ʱ��һ����������Ӿ����������⣬�������������ģ� [ [2], [3,4], [6,5,7], [4,1,8,3] ] ��������ʾ��������Ҫ��Ӷ����ߵ��ײ㣬��ÿһ��ֻ���ߵ����ڵĽ�㣬�򾭹��Ľ�������֮������Ƕ��٣�

Input

�����������Ȱ���һ������C,��ʾ����ʵ���ĸ�����ÿ������ʵ���ĵ�һ����һ������N(1 <= N <= 100)����ʾ�����ĸ߶ȣ���������N�����ֱ�ʾ���������е�i���и�i�������������е�������������[0,99]�ڡ�

Output

����ÿ������ʵ����������ܵõ������ͣ�ÿ��ʵ�������ռһ�С�
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