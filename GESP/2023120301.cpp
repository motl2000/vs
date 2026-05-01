#include <stdio.h>

int main(int argc, char **argv)
{
    // n: 小猫数量, i: 每次扔掉的鱼数, j: 循环变量, k: 最后一只小猫拿走的鱼数, ans: 当前鱼数
    long long n, i, j, k, ans;
    bool flag;  // 标记当前k是否满足所有小猫分鱼的条件
    
    // 读取输入：小猫数量n和每次扔掉的鱼数i
    scanf("%lld%lld", &n, &i);
    
    k = 1;  // 从最后一只小猫拿走1条鱼开始尝试
    
    // 暴力枚举：不断尝试增加最后一只小猫拿走的鱼数
    while(true)
    {
        flag = true;  // 假设当前k是可行的
        ans = k * n + i;  // 计算第N只小猫分鱼前的鱼数
        
        // 逆向模拟：从第N-1只小猫回溯到第1只小猫的分鱼过程
        for(j = 1; j < n; j++)
        {
            // 关键检查：分鱼后的鱼数必须是(n-1)的整数倍
            // 因为每只小猫分鱼后剩下n-1份，鱼数应该能被(n-1)整除
            if(ans % (n - 1) != 0)
            {
                flag = false;  // 不满足条件，当前k值无效
                break;
            }
            
            // 逆向推导上一只小猫分鱼前的鱼数：
            // ans/(n-1): 得到每份的鱼数
            // *n: 得到n份的总鱼数（被拿走一份前）
            // +i: 加上扔掉的i条鱼
            ans = ans / (n - 1) * n + i;
        }
        
        if(flag) break;  // 找到满足条件的最小解，退出循环
        
        k++;  // 尝试下一个k值
    }
    
    printf("%lld\n", ans);  // 输出最小的初始鱼数
    
    return 0;
}
