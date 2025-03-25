//1332：【例2-1】周末舞会，队列
#include <iostream>
#include <queue>
using namespace std;
int n,m,k;      //n男舞者，m女舞者，k首舞曲
queue<int> q1,q2;
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) q1.push(i);
    for (int i = 1; i <= m; i++) q2.push(i);
    for (int i = 1; i <= k; i++) {
        cout << q1.front() << " " << q2.front() << endl;
        q1.push(q1.front());
        q1.pop();
        q2.push(q2.front());
        q2.pop();
    }
    return 0;
}