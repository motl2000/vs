#include <iostream>
using namespace std;

// 汉诺塔递归函数
void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    hanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from " << from << " to " << to << endl;
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    
    // A, B, C 分别代表三个柱子
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
