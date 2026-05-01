//4141：【GESP2509三级】数组清零
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 105;
int n;
int a[N];
int cnt;  // 记录操作次数

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    
    while (1) {  // 循环操作，直到数组全为0
        // 步骤1：找最大值的下标k（若有多个最大值，选下标最大的）
        int mx = n;  // 初始化为最后一个位置，保证下标最大性
        for (int i = 1; i <= n; i++)
            if (a[i] >= a[mx]) mx = i;  // >= 确保相同值时取更大下标
        
        // 若最大值为0，说明数组已全为0，结束循环
        if (a[mx] == 0) break;
        
        // 步骤2：找所有非零元素中的最小值
        int mn = a[mx];  // 初始化为当前最大值
        for (int i = 1; i <= n; i++)
            if (a[i] > 0) mn = min(mn, a[i]);  // 只在非零元素中找最小
        
        // 步骤3：将最大值减去最小值
        a[mx] -= mn;
        cnt++;  // 操作次数+1
    }
    
    printf("%d\n", cnt);
    return 0;
}
