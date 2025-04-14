//1347：【例4-8】格子游戏
//此题的解题核心就是：两个已连通的点之间，再添加一条边就构成了一个环；
//所以此题采用二维并查集来做，如果两个点已连通（祖先相同），那就满足题意，否则的话将这两个点之间建立联系（将这两个点连通起来）
#include <bits/stdc++.h>

using namespace std;

struct node {
    int x, y;
};
const int N = 205;
node f[N][N];                   //f[x][y]：存储（x,y）这个结点的横坐标、纵坐标
int n, m;

node find(node k) {             //查找k的祖先
    if (f[k.x][k.y].x == k.x && f[k.x][k.y].y == k.y)
        return f[k.x][k.y];
    return f[k.x][k.y] = find(f[k.x][k.y]);
}

void merge(node k1, node k2) {  //合并k1和k2所在的两个集合
    k1 = find(k1);
    k2 = find(k2);
    f[k1.x][k1.y] = k2;
}

int main() {
    cin.tie(0);
    cin >> n >> m;
    int x, y;
    char c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j].x = i;
            f[i][j].y = j;
        }
    }
    node k1, k2;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y >> c;
        if (c == 'D') {         //连接（x,y）和（x+1,y）这两个结点
            k1 = find(f[x][y]);
            k2 = find(f[x + 1][y]);
        } else {
            k1 = find(f[x][y]);
            k2 = find(f[x][y + 1]);
        }
        //先判断当前的两点是否已连通，两个已连通的点之间，再添加一条边就构成了一个环
        if (k1.x == k2.x && k1.y == k2.y) {
            cout << i;
            return 0;
        } else {
            //不连通，那就连起来
            merge(k1, k2);
        }
    }
    cout << "draw";
    return 0;
}
