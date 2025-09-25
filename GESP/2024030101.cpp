//4041：【GESP2403一级】小杨买书
#include <iostream>
using namespace std;

int main() {
    int money;
    cin >> money;
    //计算可以买多少本书
    int books = money / 13;
    //计算剩余的钱
    int rest = money % 13;
    cout << books << '\n' << rest << '\n';
    return 0;
}
