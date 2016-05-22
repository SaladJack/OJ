#include<iostream>
#include<algorithm>
#include<cstring>
double dp[3000050];
#include<iomanip>
using namespace std;
/*
Description

����һ�ʾ��ѿ��Ա���һ����ȵķ�Ʊ���������ķ�Ʊ���Ͱ�����ͼ�飨A�ࣩ���ľߣ�B�ࣩ�����ã�C�ࣩ��Ҫ��ÿ�ŷ�Ʊ���ܶ�ó���1000Ԫ��ÿ�ŷ�Ʊ�ϣ�������Ʒ�ļ�ֵ���ó���600Ԫ���������д�����ڸ�����һ�ѷ�Ʊ���ҳ����Ա����ġ�������������ȵ�������

Input

��������������ɲ���������ÿ�����������ĵ�1�а����������� Q �� N������ Q �Ǹ����ı�����ȣ�N��<=30���Ƿ�Ʊ����������� N �����룬ÿ�еĸ�ʽΪ�� m Type_1:price_1 Type_2:price_2 ... Type_m:price_m ���������� m �����ŷ�Ʊ��������Ʒ�ļ�����Type_i �� price_i �ǵ� i ����Ʒ������ͼ�ֵ����Ʒ������һ����дӢ����ĸ��ʾ����NΪ0ʱ��ȫ�������������Ӧ�Ľ����Ҫ�����

Output

��ÿ�������������1�У������Ա�������������ȷ��С�����2λ��
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
            if((a+b+c>1000)||(book>0)||(a>600)||(b>600)||(c>600))//ֻҪ��һ������ָ��������������һ����Ʊ�ܶ��1000Ԫ�����600����÷�Ʊ���ñ���
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
