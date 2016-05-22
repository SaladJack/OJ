#include<iostream>
#include<algorithm>
#include<cstring>
double dp[3000050];
#include<iomanip>
using namespace std;
/*
Description

现有一笔经费可以报销一定额度的发票。允许报销的发票类型包括买图书（A类）、文具（B类）、差旅（C类），要求每张发票的总额不得超过1000元，每张发票上，单项物品的价值不得超过600元。现请你编写程序，在给出的一堆发票中找出可以报销的、不超过给定额度的最大报销额。

Input

测试输入包含若干测试用例。每个测试用例的第1行包含两个正数 Q 和 N，其中 Q 是给定的报销额度，N（<=30）是发票张数。随后是 N 行输入，每行的格式为： m Type_1:price_1 Type_2:price_2 ... Type_m:price_m 其中正整数 m 是这张发票上所开物品的件数，Type_i 和 price_i 是第 i 项物品的种类和价值。物品种类用一个大写英文字母表示。当N为0时，全部输入结束，相应的结果不要输出。

Output

对每个测试用例输出1行，即可以报销的最大数额，精确到小数点后2位。
*/
int main()
{
    int n;
    double q;
    char name;
    char mark;
    double price;
    int m;
    while(cin>>q>>n)
    {
        if(n==0)
            break;
        int temp=n;
        double sum[31];
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        int book=0;
        int i=0;
        while(n--)
        {
            cin>>m;
            double a=0,b=0,c=0;
            while(m--)
            {
                cin>>name>>mark>>price;
                if(name!='A'&&name!='B'&&name!='C')
                    book++;
                if(name=='A')
                    a=a+price;
                if(name=='B')
                    b=b+price;
                if(name=='C')
                    c=c+price;
            }
            sum[i]=sum[i]+a+b+c;
            if((a+b+c>1000)||(book>0)||(a>600)||(b>600)||(c>600))//只要有一个不是指定报销三种其中一个或发票总额超过1000元或单项超过600，则该发票不得报销
                sum[i]=0;
            sum[i]=sum[i]*100;
            i++;
        }
        for(int i=0;i<temp;i++)
        {
            for(int j=(int)(q*100);j>=(int)sum[i];j--)
            {
                dp[j]=max(dp[j],dp[j-(int)sum[i]]+sum[i]);
            }
        }
        cout<<std::fixed<<setprecision(2)<<dp[(int)(q*100)]/100<<endl;
    }
    return 0;
}
