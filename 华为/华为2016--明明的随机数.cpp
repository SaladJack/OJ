/*
��������ѧУ����һЩͬѧһ����һ���ʾ���飬Ϊ��ʵ��Ŀ͹��ԣ������ü����������N��1��1000֮������������N��100�������������ظ������֣�ֻ����һ������������ͬ����ȥ������ͬ������Ӧ�Ų�ͬ��ѧ����ѧ�š�Ȼ���ٰ���Щ����С�������򣬰����źõ�˳��ȥ��ͬѧ�����顣����Э��������ɡ�ȥ�ء��롰���򡱵Ĺ�����
 
 
Input Param 
     n               ����������ĸ���     
 inputArray      n�����������ɵ����� 
     
Return Value
     OutputArray    ����������������
 

ע������������֤�����������ȷ�ԣ�������������֤��
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
void sortAnddelete(vector<int> arr){
    sort(arr.begin(),arr.end());
    vector<int>::iterator itr = arr.begin();
    int head = arr[0];
    itr++;
    while(itr!=arr.end()){
        if(*itr==head)
            itr=arr.erase(itr);
        else {
            head = *itr;
            itr++;
        }
    }
    /*
    vector<int>::iterator itr2 = arr.begin();
    for(;itr!=arr.end();itr++)
        cout<<*itr<<endl;
        */
    int len = arr.size();
     
    for(int i= 0 ;i<len;i++){
    cout<<arr[i]<<endl;
    }
     
}
int main(){
int num;
 
vector<int> _array;
int temp;
while(cin>>num){
    while(num--){
    cin>>temp;
    _array.push_back(temp);
    }
    sortAnddelete(_array);
    _array.clear();
}
 
 
}