//高精度除法
#include <iostream>
#include <cstring>
using namespace std;
const int maxn=301;
int a[maxn],b[maxn],c[maxn],d,i;
void init(int a[]){
    string s;
    cin>>s;
    a[0]=s.length();                //a[0]存储数字长度
    for (int i=1;i<=a[0];i++){      //将字符串倒序存入数组
        a[i]=s[a[0]-i]-'0';     
    }
}
void print(int a[]){
    if (a[0]==0){
        cout<<0<<endl;
        return;
    }
    for (int i=a[0];i>=1;i--){
        cout<<a[i];
    }
    cout<<endl;
    return;
}
int compare(int a[],int b[]){       //比较a和b的大小,如果a>b返回1,如果a<b返回-1,如果a=b返回0
    if (a[0]>b[0]) return 1;
    if (a[0]<b[0]) return -1;
    for (int i=a[0];i>0;i--){
        if (a[i]>b[i]) return 1;
        if (a[i]<b[i]) return -1;
    }
    return 0;
}
void sub(int a[],int b[]){  //减法a=a-b
    int flag,i;
    flag=compare(a,b);
    if(flag==0){
        a[0]=0;
        return;
    }
    if (flag==1){
        for (int i=1;i<=a[0];i++){
            if (a[i]<b[i]){
                a[i+1]--;           //向上借位
                a[i]+=10;
            }
            a[i]-=b[i];
        }
        while (a[0]>0&&a[a[0]]==0){ //修正a[0]的位数
            a[0]--;
        }
        return;
    }
}
void numcopy(int p[],int q[],int det){
    for (int i=1;i<=p[0];i++)
        q[i+det-1]=p[i];
    q[0]=p[0]+det-1;
}
void devide(int a[],int b[],int c[]){
    int i,tmp[maxn];
    c[0]=a[0]-b[0]+1;           
    for (i=c[0];i>0;i--){
        memset (tmp,0,sizeof(tmp));
        numcopy (b,tmp,i);      //复制b到tmp,使temp的长度与当前a的长度一致
        while (compare(a,tmp)>=0){
            c[i]++;
            sub(a,tmp);
        }
    }
    while (c[0]>0 && c[c[0]]==0) 
        c[0]--;
    return;
}
int main() {
    memset (a,0,sizeof(a));
    memset (b,0,sizeof(b));
    memset (c,0,sizeof(c));
    init(a);
    init(b);
    devide(a,b,c); 
    print(c);
    print(a);
    return 0;
}