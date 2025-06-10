//P1080 [NOIP 2012 提高组] 国王游戏
//这题的解释看chc_1234567890的，比较清楚。
//此外的要点就是高精度乘除
#include<bits/stdc++.h>
using namespace std;
int read()      //读入优化
{
    char s;
    int k=0,base=1;
    while((s=getchar())!='-'&&s!=EOF&&!(s>='0'&&s<='9'));
    if(s==EOF)exit(0);
    if(s=='-')base=-1,s=getchar();
    while(s>='0'&&s<='9')
    {
        k=k*10+(s-'0');
        s=getchar();
    }
    return k*base;
}
void write(int x)   //输出优化
{
    if(x<0)
    {
        putchar('-');
        write(-x);
    }
    else
    {
        if(x/10)write(x/10);
        putchar(x%10+'0');
    }
}
int n,A,B;
struct node
{
    int x,y;
} a[1010];
bool cmp(node aa,node bb)   //排序
{
    if (aa.x*aa.y==bb.x*bb.y) return aa.y<bb.y;
    return (aa.x*aa.y)<(bb.x*bb.y); //此处是贪心的核心
}
int sum[1010];
int ans[1010],ls;
int p[1010],lp;
int m;//sum长度
int P;
bool Max()//比大小,ans>p: true
{
    int i=1;
    while (p[i]==0&&i<=lp) i++;//去掉前面的0
    int j=1;
    while (ans[j]==0&&j<=ls) j++;
    if (lp-i+1>ls-j+1) return false;//p的位数>ans的位数
    if (lp-i+1<ls-j+1) return true;
    while (i<=lp&&j<=ls)//一位一位的比较
    {
        if (p[i]<ans[j]) return true;
        if (p[i]>ans[j]) return false;
        i++;
        j++;
    }
    return false;
}
void cheng(int d)           //高精度乘法
{
    for (int i=1;i<=m;i++)
        sum[i]*=a[d].x;//高精度乘法
    for (int i=1;i<=m;i++)//进位
    {
        sum[i+1]+=sum[i]/10000;
        sum[i]%=10000;
    }
    if (sum[m+1]!=0) m++;
}
void div(int d)             //高精度除法
{
    memset(ans,0,sizeof(ans));
    ls=1;
    while (m>0&&sum[m]==0) m--;//去掉前导0
    P=0;
    int flag=0;
    for (int i=m;i>=1;i--)//高精度除法(模拟竖式)
    {
        P=P*10000+sum[i];
        ans[++ls]=P/a[d].y;
        if (ans[ls]==0&&!flag) ls--; else flag=1;
        P%=a[d].y;
    }
}
int main()
{
    n=read();
    A=read();
    B=read();
    for (int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
    sort(a+1,a+n+1,cmp);
    m=1;
    sum[1]=A;
    for (int i=1;i<=n;i++)
    {
        div(i);
        if (Max())
        {
            lp=ls;
            memcpy(p,ans,sizeof(ans));
        }
        cheng(i);
    }
    int i=0;
    while (i<=lp&&p[i]==0) i++;
    printf("%d",p[i]);i++;
    for (;i<=lp;i++)//输出
    {
        if (0<=p[i]&&p[i]<=9) printf("000%d",p[i]);else
        if (10<=p[i]&&p[i]<=99) printf("00%d",p[i]);else
        if (100<=p[i]&&p[i]<=999) printf("0%d",p[i]);else
        printf("%d",p[i]);
    }
    return 0;
}