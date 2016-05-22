#include <iostream>
#include <string>
#include <vector>
using namespace std;
 /*
����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
�����Ҫɾ�����ַ�������
*/
int dp(const string s){
    int n = s.length();
    vector<vector<int> > dp(n,vector<int>(n,0));
    if (!n)
    {
        return 0;
    }
 
    for (int i = n-1; i >=0; --i)
    for (int j = i; j < n; ++j)
    {
     if(i==j)
     dp[i][j] = 1;
     else if(j==i+1)
        dp[i][j] = s[i] == s[j]? 2 : 1;
        else {
            if(s[i]==s[j])
                dp[i][j] = dp[i+1][j-1]+2;
            else
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
        }  
    }
    return n-dp[0][n-1];
}
int main(){
    string str;
    while(cin>>str)
        cout<<dp(str)<<endl;
    return 0;
}