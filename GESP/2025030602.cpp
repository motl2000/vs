// 2025年3月六级考试
// 环线
// 官方答案用的单调队列，复杂度是O(2n),这段代码巧妙地结合了环形数组展开、前缀和和单调队列技术。
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 4e5 + 5;
int n;
long long a[N], pre[N];
int q[N], ql, qr;                               //q用来保存一个升序排序的当前最小前缀和对应a序列中的序号队列
long long ans;
int main() {
   scanf("%d", &n);
   for (int i = 1; i <= n; i++) {
       scanf("%lld", &a[i]);
       a[n + i] = a[i];                         // 为了方便处理环，将数组复制一份，因为环上不会重复访问，所以复制一份即可
   }
   for (int i = 1; i <= 2 * n; i++)
       pre[i] = pre[i - 1] + a[i];              // 前缀和，pre
   ql = qr = 1;                                 // ql和qr分别指向队列首尾
   ans = -1e18;
   for (int i = 1; i <= 2 * n; i++) {
       while (ql <= qr && q[ql] < i - n)        // 如果最小的前缀和对应的a序列中的序号q[ql]已经不在环上（i-n到i是环能覆盖的最大长度），那么就删除它
           ql++;                                
       ans = max(ans, pre[i] - pre[q[ql]]);     //pre[i] - pre[q[ql]] 是i到i-n区间内的最大值
       while (ql <= qr && pre[i] < pre[q[qr]])  // 如果当前前缀和比队尾小，那么就删除队尾，使得队列单调递增
           qr--;
       q[++qr] = i;                             // 将i加入队列
   }
   printf("%lld\n", ans);
   return 0;
}

// 普通方法复杂度是O(n^2)，会超时
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// const int N = 4e5 + 5;
// int n;
// long long a[N], pre[N];
// int q[N], ql, qr;                               //q用来保存一个升序排序的当前最小前缀和对应a序列中的序号队列
// long long ans;
// int main() {
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++) {
//        scanf("%lld", &a[i]);
//        a[n + i] = a[i];                         // 为了方便处理环，将数组复制一份，因为环上不会重复访问，所以复制一份即可
//    }
//    for (int i = 1; i <= 2 * n; i++)
//        pre[i] = pre[i - 1] + a[i];              // 前缀和，pre
//    ans = -1e18;
//    for (int i=1;i<=2*n;i++){
//         for (int j=max(1,i-n);j<i;j++) {
//             ans = max(ans, pre[i] - pre[j]);
//         }
//    }
//    printf("%lld\n", ans);
//    return 0;
// }
