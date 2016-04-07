#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;
/*
�Ƚ�����
С����С��ȥ����ʯ�����Ǵ�һ����ʯ�������ȡ���Ų��Ƚ����ǵ���������Щ��ʯ������������ͬ���������ǱȽ���һ��ʱ������ǿ�����������ʯg1��g2�������������֮ǰ�Ƚϵ���Ϣ�ж���������ʯ���ĿŸ��ء�
����������ʯ�ı��g1,g2����Ŵ�1��ʼ��ͬʱ������ϵ����vector,����Ԫ��ΪһЩ��Ԫ�飬��һ��Ԫ��Ϊһ�αȽ��н��ص���ʯ�ı�ţ��ڶ���Ԫ��Ϊ�������ʯ�ı�š�������֮ǰ�ıȽϴ���n���뷵����������ʯ�Ĺ�ϵ����g1���ط���1��g2���ط���-1���޷��жϷ���0���������ݱ�֤�Ϸ���������ì��������֡�
����������
2,3,[[1,2],[2,4],[1,3],[4,3]],4
����: 1
*/
//����������������һ����ǣ�
//ע��Ҫ�õ�map�������ڽ�������Ϊ��ſ��ܲ�����������������Խ��
class Cmp
{
public:
	int cmp(int g1, int g2, vector<vector<int> > records, int n)
	{
		g1; g2;
		list<int> link;
		map<int, list<int>> adj;
		for (int i = 0; i < n; i++)
		{
			adj[records[i][0]].push_back(records[i][1]);
		}


		if (BFS(g1, g2, adj) == 1)
		{
			return 1;
		}
		else if (BFS(g2, g1, adj) == 1)
		{
			return -1;
		}
		else
			return 0;
	}

	int BFS(int g1, int g2, map<int, list<int>>& adj)
	{
		list<int> index;
		map<int, bool> mark;
		index.push_back(g1);
		mark[g1] = true;
		while (!index.empty())
		{
			int num = index.front();
			mark[num] = true;
			index.pop_front();
			if (num == g2)
			{
				return 1;
			}
			else
			{
				for (list<int>::iterator it = adj[num].begin(); it != adj[num].end(); ++it)
				{
					if (mark[*it] == false)
					{
						index.push_back(*it);
					}
				}
			}
		}
		return 0;
	}
};