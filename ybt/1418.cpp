//1418：猴子选大王
#include <iostream>
#include <queue>
using namespace std;
int n,a[1000001];
queue<int> q;
int main() {
    cin >> n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        q.push(i);
    }
    while (q.size()>1) {
        int m=a[q.front()];     //这里必须要用一个临时变量存储，否则下面q.pop()后q.front()就变了
        for (int i=1;i<m;i++) {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    cout << q.front() << endl;
    return 0;
}