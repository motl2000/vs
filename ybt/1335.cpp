//1335：【例2-4】连通块,队列，这题实际是不需要队列的，仅仅是为了练习一下
//注：这题表述不清，一个黑色的也是一个连通块，然后一坨黑色的是一个连通块，实际是广搜
#include <iostream>
#include <queue>
using namespace std;
int n, m, a[101][101], vis[101][101], cnt;          //a[][]存储地图，vis[][]标记是否访问过，cnt记录连通块数
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;                            //队列存储坐标
void bfs(int x, int y) {
    q.push(make_pair(x, y));                        //将坐标(x,y)入队
    vis[x][y] = 1;
    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = t.first + dx[i], ny = t.second + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == 1 && vis[nx][ny] == 0) {
                q.push(make_pair(nx, ny));          //将坐标(nx,ny)入队
                vis[nx][ny] = 1;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1 && vis[i][j] == 0) {
                cnt++;                              
                bfs(i, j);
            }
    cout << cnt << endl;
    return 0;
}