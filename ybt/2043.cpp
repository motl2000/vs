//2043：【例5.11】杨辉三角形
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[101][101]={0};
    for (int i=0;i<n;i++)
        a[i][0]=a[i][i]=1;
    for (int i=2;i<n;i++)
        for (int j=1;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<=i;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}