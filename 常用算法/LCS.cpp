string lcs(string a, string b)
{
	int a_len = a.length();
	int b_len = b.length();
	vector<string> temp(b_len+1, "");
	vector<vector<string>> dp(a_len+1,temp);
	for (int i = 1; i < a_len+1; ++i)
		for (int j = 1; j < b_len+1; ++j)
		{
			if (a[i-1] == b[j-1])
				dp[i][j] = dp[i - 1][j - 1] + a[i-1];
			else
				dp[i][j] = dp[i - 1][j].length()>dp[i][j - 1].length() ? dp[i - 1][j] : dp[i][j - 1];
		}
	return dp[a_len][b_len];
}