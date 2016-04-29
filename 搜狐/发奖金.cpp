#include<stdio.h>
/*
 狐进行了一次黑客马拉松大赛，全公司一共分为了N个组，每组一个房间排成一排开始比赛，比赛结束后没有公布成绩，但是每个组能够看到自己相邻的两个组里比自己成绩低的组的成绩，比赛结束之后要发奖金，以1w为单位，每个组都至少会发1w的奖金，另外，如果一个组发现自己的奖金没有高于比自己成绩低的组发的奖金，就会不满意，作为比赛的组织方，根据成绩计算出至少需要发多少奖金才能让所有的组满意。 


输入描述:

每组数据先输入N，然后N行输入N个正整数，每个数表示每个组的比赛成绩。


输出描述:

输出至少需要多少w的奖金
*/
    
int main(){
        
    int n;  
    while(scanf(%d,&n)!=EOF){  
        int i = 0;
        total记录奖金总共需要发出的奖金
        int total = 0;
        temp数组记录给对应参数组所发的奖金
        int temp[1000] = {0};
         int num[1000];
        while(i  n) scanf(%d,&num[i++]);
            
        for(i = 0; i  n; i++) printf(%dt,num[i]);
            
        第一次扫描（从左到右）
        temp[0] = 1;
        for(i  = 1; i  n; i++){
            if(num[i]  num[i-1]) temp[i] = temp[i-1] + 1;
            else temp[i] = 1;
        }
        第二次扫描（从右到左）
        for(i = n-1; i  0; i--){
            if(num[i-1]  num[i] && temp[i-1] = temp[i]) temp[i-1] = temp[i] + 1;
        }
        for(i = 0; i  n; i++) total += temp[i];
        printf(%dn,total);
    }
    return 0;
}