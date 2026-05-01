//GESP2025年6月6级学习⼩组
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1005;  // 最大支持n=1000，符合题目约束
int n;               // 学生人数
int a[N];            // 原地DP：a[i]初始存储αi，最终存储i名同学的最大总积极度

int main() {
    scanf("%d", &n);  // 读取班级人数n
    
    // 外层循环：遍历从1到n的人数
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);  
        
        // 内层循环：尝试将i拆分为j和i-j两部分（1 ≤ j < i）
        for (int j = 1; j < i; j++) {
            // 状态转移：比较"不分组"和"分组"两种方案
            // a[i] 当前值：i人全在一个小组的积极度
            // a[j] + a[i-j]：将i人分为j人和i-j人两个小组的积极度之和
            // 由于a[j]和a[i-j]在前面已经更新过，所以都是最优值
            a[i] = max(a[i], a[j] + a[i - j]);
        }
    }
    printf("%d\n", a[n]);
    
    return 0;
}
