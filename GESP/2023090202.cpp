//4016：【GESP2309二级】数字黑洞
//程序一，三个变量的形式
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    int cnt = 0;
    while (N != 495) {
        int a = N % 10;
        int b = N / 10 % 10;
        int c = N / 100;

        // 三个数字排序
        if (a > b) swap(a, b);
        if (b > c) swap(b, c);
        if (a > b) swap(a, b);

        int maxNum = c * 100 + b * 10 + a;
        int minNum = a * 100 + b * 10 + c;
        N = maxNum - minNum;
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}

//程序二，数组的形式
#include <iostream>
#include <algorithm>
using namespace std;
int d[3];
int main() {
    int N;
    cin >> N;

    int cnt = 0;
    while (N != 495) {
        //初始化d数组
        d[0] = N / 100;
        d[1] = N / 10 % 10;
        d[2] = N % 10;
        // 排序
        sort(d, d + 3);     
        // 求最大最小值         
        int minNum = d[0] * 100 + d[1] * 10 + d[2];
        int maxNum = d[2] * 100 + d[1] * 10 + d[0];

        N = maxNum - minNum;
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}
