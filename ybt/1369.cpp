//1369：合并果子(fruit)
//这题是一个经典的哈夫曼树问题，我们可以用优先队列来解决这个问题。每次取出两个最小的数，合并后放回，直到队列中只剩一个数。
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;       //优先队列，小根堆
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while (q.size() > 1) {                                  //依次取出两个最小的数，合并后放回
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a + b;
        q.push(a + b);
    }
    cout << ans << endl;
    return 0;
}