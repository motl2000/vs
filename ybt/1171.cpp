//大整数的因子
#include <iostream>
#include <cstring>
using namespace std;
string s;
int main(){
    cin>>s;
    int flag=0;
    for (int k=2;k<=9;k++){
        int t=0;
        for (int i=0;i<s.length();i++){
            t=t*10+s[i]-'0';            //将上一个余数乘10加上之后的一位数得到下一个被除数
            t%=k;
        }
        if (t==0){
            flag=1;
            cout<<k<<" ";
        }
    }
    if (flag==0){
        cout<<"none"<<endl;
    }
}