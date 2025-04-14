//2025年3月五级考试
//原根判断
#include <cstdio>
 using namespace std;
 int a, p;
 int ans;
 int fpw(int b, int e) {            //快速幂
    if (e == 0)
        return 1;
    int r = fpw(b, e >> 1);
    r = 1ll * r * r % p;
    if (e & 1)
        r = 1ll * r * b % p;
    return r;
 }
 void check(int e) {
    if (fpw(a, e) == 1)
        ans = 0;
 }
 int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &a, &p);
        ans = 1;
        int phi = p - 1, r = phi;
        /*
        确定p-1是不是最小的满足a^x=1
        如果p-1不是最小的，那么假设x是最小的，那么a^x=1
        得到(a^x)^n=1
        也就是a^xn=1
        可以推断xn=p-1（也可以证明），即x一定是p-1的因数，然后枚举因数就可以了
        */
        for (int i = 2; i * i <= phi; i++)//最小性约束：若存在更小的k满足a^k ≡ 1 mod p，则这个k必须是φ(p)的约数
            if (phi % i == 0) {     
                check(phi / i);
                if(ans == 0)
                    break;
                while (r % i == 0)
                    r /= i;
            }
        if (ans && r > 1)   
            check(phi / r);
        printf(ans ? "Yes\n" : "No\n");
    }
    return 0;
 }