//1345：【例4-6】香甜的黄油
//SPFA算法
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,p,c,i,j,x,y,t,min1,header,tail,tot,u;
int a[801][801],b[501],dis[801],num[801],w[801][801],team[1601];
bool exist[801];
int main(){
    cin>>n>>p>>c;                       //n个牧场，p个牧草，c条边
    for(i=1;i<=p;i++){                  //初始化,b[i]表示第i头牛所在的牧场
        b[i]=0;
        num[i]=0;                       //num[i]表示第i个牧场相邻的牧场数
        for (j=1;j<=p;j++)
            w[i][j]=0x7fffffff/3;       //w[i][j]表示第i个牧场到第j个牧场的距离，初始化为无穷大
    }
    for(i=1;i<=n;i++){
        cin>>b[i];
    }
    for(i=1;i<=c;i++){                  //初始化，a[i][j]表示邻接矩阵
        cin>>x>>y>>t;
        w[x][y]=w[y][x]=t;
        a[x][++num[x]]=y;               //a[i][j]表示第i个牧场相邻的牧场，邻接表
        a[y][++num[y]]=x;
    }
    min1=0x7fffffff/3;
    for (i=1;i<=p;i++){                 //SPFA算法
        for (j=1;j<=p;j++){             //初始化dis数组
            dis[j]=0x7fffffff/3;
        }
        memset(exist,false,sizeof(exist));
        memset(team,0,sizeof(team));
        dis[i]=0;
        exist[i]=true;
        team[1]=i;                      //team数组用于存储待访问的牧场
        header=0;
        tail=1;
        do{
            header++;
            header=((header-1)%1601)+1; //实现循环队列
            u=team[header];             //取出队首元素
            exist[u]=false;             //使该元素未访问
            for (j=1;j<=num[u];j++){    //松弛操作，访问u的所有相邻牧场
                if (dis[a[u][j]]>dis[u]+w[u][a[u][j]]){
                    dis[a[u][j]]=dis[u]+w[u][a[u][j]];
                    if (!exist[a[u][j]]){       //如果该牧场未访问，则加入队列
                        tail++;
                        tail=((tail-1)%1601)+1;
                        team[tail]=a[u][j];
                        exist[a[u][j]]=true;    
                    }
                }
            }
        }while (header!=tail);
        tot=0;
        for (j=1;j<=n;j++){
            tot+=dis[b[j]];
        }
        if (tot<min1){
            min1=tot;
        }
    }
    cout<<min1;
    return 0;

}