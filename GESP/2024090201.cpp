//4075：【GESP2409二级】数位之和
#include <bits/stdc++.h>
using namespace std;

bool isBeautiful(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum % 7 == 0;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int x;
        scanf("%d", &x);
        printf("%s\n", isBeautiful(x) ? "Yes" : "No");
    }
    return 0;
}
