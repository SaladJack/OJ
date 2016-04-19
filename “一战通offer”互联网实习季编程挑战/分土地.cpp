class Partition {
public:
int difNumCount(vector<int> a, vector<int> b, int n){
	int count = 0;
	for (int i = 0; i < n; i++)
	if (a[i] != b[i]) count++;
	return count;
}
    vector<int> getPartition(const vector<vector<int> >& land, int n, int m) {
        // write code here
        vector<int> res;
	int _n = n;
	while (_n--){
		res.push_back(1);//全部初始化为1
	}
	int pos = 0;
	int minAns = INT_MAX;
	for (int i = -1; i < n; i++){
		if (i != -1)
			res[i] = 0;
		int _minAns = 0;
		for (int j = 0; j < m; j++)
		{
			_minAns += difNumCount(land[j], res, n);
		}
		if (_minAns < minAns)
		{
			minAns = _minAns;
			pos = i;
		}
	}
	vector<int> ans;
	ans.push_back(pos + 1);
	ans.push_back(pos + 2);
        return ans;
    }
};