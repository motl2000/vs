//4009：【GESP2306三级】春游
#include <iostream>
using namespace std;
int N, M, id, arrived[1001];
int main() {
    cin >> N >> M;
    while (M--) {
        cin >> id;
        arrived[id] = 1;
    }
    
    bool first = true;
    for (int i = 0; i < N; i++) {
        if (!arrived[i]) {
            cout << i << " ";
            first = false;
        }
    }
    
    if (first) 
        cout << N;  // 如果没有人缺勤
    cout << endl;
    
    return 0;
}
