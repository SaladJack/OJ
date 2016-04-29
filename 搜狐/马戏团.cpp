#include<iostream>
#include<string>
#include<vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;
/*
搜狐员工小王最近利用假期在外地旅游，在某个小镇碰到一个马戏团表演，精彩的表演结束后发现团长正和大伙在帐篷前激烈讨论，小王打听了下了解到， 马戏团正打算出一个新节目“最高罗汉塔”，即马戏团员叠罗汉表演。考虑到安全因素，要求叠罗汉过程中，站在某个人肩上的人应该既比自己矮又比自己瘦，或相等。 团长想要本次节目中的罗汉塔叠的最高，由于人数众多，正在头疼如何安排人员的问题。小王觉得这个问题很简单，于是统计了参与最高罗汉塔表演的所有团员的身高体重，并且很快找到叠最高罗汉塔的人员序列。 现在你手上也拿到了这样一份身高体重表，
请找出可以叠出的最高罗汉塔的高度，这份表中马戏团员依次编号为1到N。
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
