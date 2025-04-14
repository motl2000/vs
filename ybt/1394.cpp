//1394：连接格点(grid)
#include <bits/stdc++.h>
using namespace std;
//克鲁斯卡尔（Kruskal）算法计算最小生成树，+贪心，先选择向下连接，然后再选择向右连接
int n, m;
struct node { //根节点坐标
    int x, y;
};
node fa[1005][1005];                    //fa[i][j]表示第i行，第j列的根节点
node Find(int x, int y) {               //并查集寻根
    if (fa[x][y].x == x && fa[x][y].y == y) return fa[x][y];
    return fa[x][y] = Find(fa[x][y].x, fa[x][y].y);
}
int ans = 0;
int cnt = 1;                            //加入最小生成树的节点数量
bool flag=0;                            //标记是否完成最小生成树
//使用代价v连接xa,ya点和xb,yb点
void Union(int xa,int ya,int xb,int yb,int v){
    if (xb>m||yb>n) return;             //出界，返回
    node xx = Find(xa, ya);             //起点寻根
    node yy = Find(xb, yb);             //终点寻根
    if (xx.x != yy.x || xx.y != yy.y) { //不同根
        fa[yy.x][yy.y] = xx;            //合并
        cnt++;                          //多一个点加入最小生成树
        ans+=v;                         //代价+v
        if (cnt == n * m) {             //如果所有节点都加入了最小生成树
            flag=1;                     //标记完成最小生成树
            return;                     //返回
        }
    }
    return;
}
int main() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++) {       //初始化根为自己
        for(int j = 1; j <= n; j++) {
            fa[i][j]={i,j};
        }
    }
    int a, b, c, d;
    while(cin >> a >> b >> c >> d) {
        Union(a,b,c,d,0);               //合并已有的连线
    }
    for(int i = 1; i <= m; i++) {       //枚举每个点向下连线
        for(int j = 1; j <= n; j++) {
            Union(i,j,i+1,j,1);
            if (flag==1) break;
        }
        if (flag==1) break;
    }
    //如果向下连接没有连接全部的点，继续向右连接
    for(int i = 1; i <= m; i++) {       //枚举每个点向右连线
        if (flag==1) break;
        for(int j = 1; j <= n; j++) {
            Union(i,j,i,j+1,2);
            if (flag==1) break;
        }
        if (flag==1) break;
    }
    cout<<ans;
    return 0;
}