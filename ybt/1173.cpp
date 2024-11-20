//阶乘和
//用高精度计算出S=1!+2!+3!+…+n!（n≤100）,其中“!”表示阶乘，例如：5!=5×4×3×2×1。
//输入正整数n
//输出计算结果S

#include <bits/stdc++.h>
using namespace std;
int n,a[100000],len=1;          //a数组存储结果,len存储结果的位数
int t[100000],l=1;              //t数组存储当前阶乘的结果,l存储当前阶乘的位数
void factorial(int k){          //在当前t的基础上乘以k
    int s=0;
    for (int i=1;i<=l;i++){
        t[i]=t[i]*k+s;
        s=t[i]/10;
        t[i]%=10;
        //处理最高位进位
        if (s>0&&i==l){
            l++;
        }
    }
}
void add(){
    int s=0;
    for (int i=1;i<=l;i++){     //t的长度总是大于a的长度，所以只需要遍历t
        a[i]=a[i]+t[i]+s;
        s=a[i]/10;
        a[i]%=10;
        if (s>0)                //处理a最高位进位
            len=max(len,i+1);
        len=max(len,i);         //当t的高位超出a的高位时
    }
}
int main(){
    cin>>n;
    t[1]=1;
    for (int k=1;k<=n;k++){
        factorial(k);
        add();
    }
    for (int i=len;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}

