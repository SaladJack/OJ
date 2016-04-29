#include<iostream>
#include<string>
#include<vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
�Ѻ�Ա��С��������ü�����������Σ���ĳ��С������һ����Ϸ�ű��ݣ����ʵı��ݽ��������ų����ʹ��������ǰ�������ۣ�С�����������˽⵽�� ��Ϸ���������һ���½�Ŀ������޺�����������Ϸ��Ա���޺����ݡ����ǵ���ȫ���أ�Ҫ����޺������У�վ��ĳ���˼��ϵ���Ӧ�üȱ��Լ����ֱ��Լ��ݣ�����ȡ� �ų���Ҫ���ν�Ŀ�е��޺���������ߣ����������ڶ࣬����ͷ����ΰ�����Ա�����⡣С�������������ܼ򵥣�����ͳ���˲�������޺������ݵ�������Ա��������أ����Һܿ��ҵ�������޺�������Ա���С� ����������Ҳ�õ�������һ��������ر�
���ҳ����Ե���������޺����ĸ߶ȣ���ݱ�����Ϸ��Ա���α��Ϊ1��N��
*/
int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<pair<int, int> > v;
		int t, a, b;
		while (n--) {
			scanf("%d%d%d", &t, &a, &b);
			v.push_back(pair<int, int>(a, b));
		}//printf("%d      *********\n", v.size());
		sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
			if (a.first != b.first) return a.first < b.first;
			else return a.second >= b.second;
		});
		//printf("%d      *********\n", v.size());
		//for (int i=0; i<v.size(); ++i) cout << v[i].first << " " << v[i].second << endl;
		std::vector<int> dp(v.size(), 1);
		int ans = 0;
		for (int i = 1; i < (int)v.size(); ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (v[i].second >= v[j].second) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
