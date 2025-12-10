//1494：【例 1】Sightseeing Trip
/*思路：
使用Floyd-Warshall算法计算所有点对之间的最短路径，同时记录路径信息。
通过遍历所有可能的三元组(i, j, k)，找到最短的旅行路径。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAX 0x3f3f3f3f
#define ll long long
using namespace std;
int path[310][310],dis[310][310],points[310][310],way[310][310],e,v;//path存储最短路径，dis存储最短路径长度，points存储领接表，way存储最短路径中从 i 到 j 的下一个中间点。
int ans[310],sn=0;                  //ans数组存储最短路径，sn为数组下标
void init()
{
    memset(dis,0x3f,sizeof(dis));   //将每个字节赋值为0x3f,即255
    memset(points,0x3f,sizeof(points));
    cin>>v>>e;
    for(int i=1; i<=v; i++)          //初始化
        dis[i][i]=points[i][i]=0;
    for(int i=1; i<=e; i++)          //读入,构建图的邻接矩阵
    {
        int a,b,w;
        cin>>a>>b>>w;
        dis[a][b]=dis[b][a]=min(dis[a][b],w);
        points[a][b]=points[b][a]=dis[a][b];
    }
}
void getway(int x,int y)             //递归函数，从 x 到 y 的最短路径中提取顶点序列。
{
    if(way[x][y]==0)                 //如果没有下一个点，则返回
    {
        return ;
    }
    getway(x,way[x][y]);            //前,先找到x到y的下一个点
    ans[++sn]=way[x][y];            //中
    getway(way[x][y],y);            //后,再找到y到x的下一个点
}
void solve1()                       //Floyd-Warshall 算法的变种来寻找最短环路。
{
    int minn=MAX;
    for(int k=1; k<=v; k++)          //遍历每个中间点 k ，检查是否存在通过 k 的更短环路。
    {
        for(int i=1; i<k; i++)       //遍历i,j
            for(int j=i+1; j<k; j++) //i!=j
            {
                //如果存在从i到j的最短路径+从k到i的最短路径+从k到j的最短路径小于minn,则更新minn和ans数组
                //dis[i][j]+points[k][i]+points[j][k]表示从i到j的最短路径+从k到i的最短路径+从k到j的最短路径
                if(minn>(ll)dis[i][j]+points[k][i]+points[j][k])
                {
                    minn=dis[i][j]+points[k][i]+points[j][k];
                    sn=0;           
                    ans[++sn]=i;     //将i存入ans数组中
                    getway(i,j);     //递归函数，从 i 到 j 的最短路径中提取顶点序列。
                    ans[++sn]=j;
                    ans[++sn]=k;
                }
            }
        for(int i=1; i<=v; i++)
            for(int j=1; j<=v; j++) //具有对称性
            {
                if(dis[i][j]>(ll)dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                    way[i][j]=k;//标志下一个目标点
                }
            }
    }
    if(minn>=MAX)
    {
        cout<<"No solution."<<endl;
    }
    else
    {
        for(int i=1; i<=sn; i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }
}
 
int main()
{
    init();
    solve1();
}