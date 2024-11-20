//大整数乘法
//求两个不超过200位的非负整数的积。
//输入有两行，每行是一个不超过200位的非负整数，没有多余的前导0。
//输出一行，即相乘后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。
#include <bits/stdc++.h>
using namespace std;
int a[201],b[201],c[401],lena,lenb,lenc;
int main(){
    string s;
    //读入数据
    cin>>s;
    lena=s.length();
    for (int i=1;i<=lena;i++){
        a[i]=s[lena-i]-'0';
    }
    cin>>s;
    lenb=s.length();
    for (int i=1;i<=lenb;i++){
        b[i]=s[lenb-i]-'0';
    }
    for (int i=1;i<=lena;i++){
        int x=0;
        for (int j=1;j<=lenb;j++){
            c[i+j-1]=a[i]*b[j]+c[i+j-1]+x;  //套用公式
            x=c[i+j-1]/10;
            c[i+j-1]%=10;
        }
        c[i+lenb]=x;                        //处理最高位进位
    }
    lenc=lena+lenb;
    while (c[lenc]==0&&lenc>1){
        lenc--;
    }
    for (int i=lenc;i>=1;i--){
        cout<<c[i];
    }
    return 0;
}