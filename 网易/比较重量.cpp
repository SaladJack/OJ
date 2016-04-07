#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
using namespace std;
/*
比较重量
小明陪小红去看钻石，他们从一堆钻石中随机抽取两颗并比较她们的重量。这些钻石的重量各不相同。在他们们比较了一段时间后，它们看中了两颗钻石g1和g2。现在请你根据之前比较的信息判断这两颗钻石的哪颗更重。
给定两颗钻石的编号g1,g2，编号从1开始，同时给定关系数组vector,其中元素为一些二元组，第一个元素为一次比较中较重的钻石的编号，第二个元素为较轻的钻石的编号。最后给定之前的比较次数n。请返回这两颗钻石的关系，若g1更重返回1，g2更重返回-1，无法判断返回0。输入数据保证合法，不会有矛盾情况出现。
测试样例：
2,3,[[1,2],[2,4],[1,3],[4,3]],4
返回: 1
*/
//广度优先搜索，添加一个标记，
//注意要用到map来保存邻接链表，因为编号可能不连续，而导致数组越界
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