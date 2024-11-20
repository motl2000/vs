//除以13
//题目描述:输入一个大于0的大整数N，长度不超过100位，要求输出其除以13得到的商和余数。
//输入:一个大于0的大整数，长度不超过100位。
//输出:两行，第一行为商，第二行为余数。
#include <bits/stdc++.h>
using namespace std;
int a[101],c[101],lena,lenc;
int main(){
    string s;
    //读入数据
    cin>>s;
    lena=s.length();
    for (int i=0;i<lena;i++){
        a[i]=s[i]-'0';
    }
    int x=0;
    for (int i=0;i<lena;i++){
        c[i]=(a[i]+x*10)/13;        //将之前的余数乘10加上当前位的数再除以13，得到商,并存入c数组
        x=(a[i]+x*10)%13;           //求出新的余数
    }
    lenc=1;
    while (c[lenc]==0&&lenc<lena){  //去掉前导0
        lenc++;
    }
    for (int i=lenc;i<lena;i++){    //输出商
        cout<<c[i];
    }
    cout<<endl<<x;
    return 0;
}
