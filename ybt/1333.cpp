//1333：【例2-2】Blah数集
//这题不严谨，要求是出队顺序也必须是升序的，而不是全部算完再排序
#include <bits/stdc++.h>
using namespace std;
int a, n;
int main() {
    while (cin >> a >> n) {
        queue<int> q1, q2;
        n--;//基数算第一个元素，都没加入队列，默认已经出队一个了
        //每执行一次，就会出队一个最小值（出队出的都是最小值）
        while (n--) {
            q1.push(2 * a + 1);
            q2.push(3 * a + 1);
            if (q1.front() < q2.front()) {
                //q1出队，基数变q1的队头
                a = q1.front();
                q1.pop();
            } else if (q1.front() > q2.front()) {
                a = q2.front();
                q2.pop();
            } else {
                //相同值都出队
                a = q1.front();
                q1.pop();
                q2.pop();
            }
        }
        //a就是第n个出队的元素
        cout << a << endl;
    }
    return 0;
}


