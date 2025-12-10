//4076：【GESP2409二级】小杨的N字矩阵
#include <cstdio>

int main() {
    int m;
    scanf("%d", &m);

    for (int i = 1; i <= m; ++i) {          // 行号 1..m
        for (int j = 1; j <= m; ++j) {      // 列号 1..m
            if (i == j || j == 1 || j == m) // 主对角线、第1列、第m列
                printf("+");
            else
                printf("-");
        }
        printf("\n");
    }
    return 0;
}
