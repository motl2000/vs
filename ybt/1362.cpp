//1362：家庭问题(family)
#include <iostream>
#include <queue>
using namespace std;
int n, k, a[1001][1001], vis[1001], cnt, maxNum;
queue<int> q;
void bfs(int x) {
    q.push(x);
    vis[x] = 1;
    int num=1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();    
        for (int i = 1; i <= n; i++) {
            if (a[t][i] == 1 && vis[i] == 0) {
                q.push(i);
                vis[i] = 1;
                num++;               
            }
        }
    }
    maxNum=max(maxNum,num);
}
int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            cnt++;
            bfs(i);
        }
    }
    cout << cnt <<" "<< maxNum;
    return 0;
}