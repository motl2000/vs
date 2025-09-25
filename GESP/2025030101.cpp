//4105：【GESP2503一级】图书馆里的老鼠
#include <iostream>
using namespace std;

int main() {
    int n, x, y,eaten = 0;//eaten为老鼠啃完的书的数量
    cin >> n >> x >> y;
    // 如果y%x==0，说明y是x的倍数，那么y/x就是啃完的书的数量
    if (y%x == 0)
        eaten = y/x;
    else//否则，啃完的书的数量是y/x向上取整
        eaten = y/x + 1;
    cout << n - eaten << '\n';
    return 0;
}
