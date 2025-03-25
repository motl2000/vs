//2025年3月五级考试
//平均分配
// #include<bits/stdc++.h>
// using namespace std;
// const int N=100001;
// int n;
// long long ans;
// struct node{
//     long long a,b;
// } ma[2*N+2],mb[2*N+2],m[2*N+2];
// bool compare1(node x,node y){
//         return x.a>y.a;
// }   
// bool compare2(node x,node y){
//     return x.b>y.b;
// }   
// int main()
// {
//     //输入
//     cin>>n;

//     for (int i=1;i<=2*n;i++)
//     {
//         cin>>m[i].a;
//     }
//     for (int i=1;i<=2*n;i++)
//     {
//         cin>>m[i].b;
//     }    
//     //把a>b的放到ma中，a<b的放到mb中
//     for (int i=1;i<=2*n;i++)
//     {
//         if (m[i].a>m[i].b)
//         {
//             ma[++ma[0].a]=m[i];
//         }
//         else if (m[i].a<m[i].b)
//         {
//             mb[++mb[0].a]=m[i];
//         }
//         else
//         {
//             ans+=m[i].a;
//         }
//     }
//     if (ma[0].a>n)
//         sort (ma+1,ma+ma[0].a+1,compare1);
//     if (mb[0].a>n)
//         sort (mb+1,mb+mb[0].a+1,compare2);
//     //统计a>b的和
//     int i=1;
//     while (i<=n&&i<=ma[0].a)
//     {
//         ans+=ma[i].a;        
//         i++;
//     }
//     //统计a<b的和
//     int j=1;
//     while (j<=n&&j<=mb[0].a)
//     {
//         ans+=mb[j].b;        
//         j++;
//     }
//     //如果b>a的数量过半
//     if (mb[0].a>n)
//     {
//         while (j<=mb[0].a)
//         {
//             ans+=mb[j].a;
//             j++;
//         }
//     }
//     //如果a>b的数量过半
//     if (ma[0].a>n)
//     {
//         while (i<=ma[0].a)
//         {
//             ans+=ma[i].b;
//             i++;
//         }
//     }
//     cout<<ans<<endl;
// }

// //代码段1
// #include <bits/stdc++.h>
//  using namespace std;
//  const int N = 2e5 + 5;
//  int n;
//  long long b[N], c[N], d[N];
//  long long ans;
//  int main() {
//     scanf("%d", &n);
//     for (int i = 1; i <= 2 * n; i++)
//         scanf("%lld", &b[i]);
//     for (int i = 1; i <= 2 * n; i++)
//         scanf("%lld", &c[i]);
//     for (int i = 1; i <= 2 * n; i++) {
//         ans += b[i];
//         d[i] = c[i] - b[i];
//     }
//     sort(d + 1, d + 2 * n + 1);                                     
//     for (int i = n + 1; i <= 2 * n; i++)    //加上c-b的n个差值，注意这里是从n+1开始
//         ans += d[i];
//     printf("%lld\n", ans);
//     return 0;
//  }
 
//代码段2
#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n;
long long ans,sumA,sumB;
struct node{
    long long a,b;
} ma[2*N+2],mb[2*N+2],m[2*N+2];
int main()
{
    //输入
    cin>>n;

    for (int i=1;i<=2*n;i++)
    {
        cin>>m[i].a;
    }
    for (int i=1;i<=2*n;i++)
    {
        cin>>m[i].b;
    }    
    //把a>b的放到ma中，a<b的放到mb中
    for (int i=1;i<=2*n;i++)
    {
        if (m[i].a>m[i].b)
        {
            ma[++ma[0].a]=m[i];
            sumA+=m[i].a;
        }
        else if (m[i].a<m[i].b)
        {
            mb[++mb[0].a]=m[i];
            sumB+=m[i].b;
        }
        else
        {
            ans+=m[i].a;
        }
    }
    if (ma[0].a>n)
        sort (ma+1,ma+ma[0].a+1,[](node x, node y) { return x.a > y.a; });
    if (mb[0].a>n)
        sort (mb+1,mb+mb[0].a+1,[](node x, node y) { return x.b > y.b; });
    //如果a>b的数量过半
    if (ma[0].a>n)
    {
        //统计a>b的和
        int i=1;
        while (i<=n)
        {
            ans+=ma[i].a;        
            i++;
        }
        while(i<=ma[0].a)
        {
            ans+=ma[i].b;
            i++;
        }
    }
    else
        ans+=sumA;  

    //如果b>a的数量过半
    if (mb[0].a>n)
    {
        //统计a<b的和
        int j=1;
        while (j<=n)
        {
            ans+=mb[j].b;        
            j++;
        }
        while(j<=mb[0].a)
        {
            ans+=mb[j].a;
            j++;
        }
    }   
    else
        ans+=sumB;

    cout<<ans<<endl;
}