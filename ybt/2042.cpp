//2042：【例5.10】稀疏矩阵
#include<iostream>
#include<iomanip>
using namespace std;
int n,m,a[101][101],b[101][3],k;
int main()
{
    cin>>n>>m;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
    for (int i=0;i<k;i++)
        cout<<b[i][0]+1<<" "<<b[i][1]+1<<" "<<b[i][2]<<endl;
    return 0;
}