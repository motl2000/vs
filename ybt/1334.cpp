//1334：【例2-3】围圈报数，队列
#include <iostream>
#include <queue>
using namespace std;
int n, m;
queue<int> q;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) q.push(i);
    while (q.size() > 1) {
        for (int i = 1; i < m; i++) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << " ";
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}