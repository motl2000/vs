#include <iostream>
#include <string>
using namespace std;
 int main() {
    int a = 10;       // 定义整型变量 a，初始化为 10
    int *p = &a;      // 定义指针 p，指向 a 的地址
    int *&q = p;      // 定义 q 是 p 的引用（即 q 是 p 的别名）
    *q = 20;          // 通过 q 修改 p 指向的值（即 a）
    cout << a << endl; // 输出 a 的值
    return 0;
}
          