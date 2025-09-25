//4013：【GESP2309一级】买文具
#include <iostream>
using namespace std;

int main() {
    int X, Y, Z, Q;
    cin >> X >> Y >> Z >> Q;

    //计算需要多少钱
    int total = 2 * X + 5 * Y + 3 * Z;

    //判断是否够买所有的文具
    if (total <= Q) {
        cout << "Yes" << endl;
        //输出剩多少钱 
        cout << Q - total << endl;
    } else {
        cout << "No" << endl;
        //输出还差多少钱
        cout << total - Q << endl;
    }

    return 0;
}
