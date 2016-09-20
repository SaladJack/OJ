#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <list>
//#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000;
map<int, list<int> > adj;
map<int, bool> visit;
int cnt = 0;
void DFS(int i){
	visit[i] = true;
	++cnt;
	for (list<int> ::iterator it = adj[i].begin(); it != adj[i].end(); ++it) {
		if (visit[*it] == false)
			DFS(*it);
	}
}
int main(){
	int m, k;
	cin >> m;	
	while (m--){
		cin >> k;
		vector<int> vec(k);
		for (int i = 0; i < k; ++i)
			cin >> vec[i];
		for (int i = 0; i < k - 1; ++i)
			for (int j = i + 1; j < k; ++j) {
				adj[vec[i]].push_back(vec[j]);
				adj[vec[j]].push_back(vec[i]);
			}
	}

	DFS(1);
	cout << cnt - 1 << endl;

	/*
	5
	2 3 2
	5 10 13 11 12 14
	2 1 3
	2 99 2
	2 1 4
	*/
}