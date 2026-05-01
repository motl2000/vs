//4030：【GESP2312三级】单位转换
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

// 获取单位对应的转换系数
// 基于单位缩写特点：'k'开头表示千，单字符表示基本单位，双字符且非'k'开头表示最小单位
// 长度单位：km(1000000), m(1000), mm(1)
// 重量单位：kg(1000000), g(1000), mg(1)
// 例如：1km = 1 * 1000000 / 1 = 1000000mm
int get_base(char *s) {
    // 单字符单位：'m'或'g'，系数为1000（相对于最小单位）
    if (strlen(s) == 1) // strlen(s)表示字符串s的长度
        return  ;//填入返回值
    // 双字符单位：'k'开头表示千(km/kg)，系数为1000000；否则为最小单位(mm/mg)，系数为1
    if(s[0] == 'k')
        return ;//填入返回值
    else
        return ;//填入返回值
}
int main() {
    int T;  // T: 题目数量
    scanf("%d", &T);
    
    while(T --) {
        int x;          // x: 待转换的数值
        char s1[5], s2[5];  // s1: 原单位, s2: 目标单位
        
        // 读取输入格式：x unit1 = ? unit2
        scanf("%d", &x);          // 读取数值x
        scanf("%s", s1);          // 读取原单位unit1
        
        // 连续三次读取字符串到s2，跳过"="和"?"，最终s2中存储的是目标单位
        // 第一次读取：s2 = "="
        // 第二次读取：s2 = "?"
        // 第三次读取：s2 = 目标单位（如"mm"或"g"）
        scanf("%s", s2), scanf("%s", s2), scanf("%s", s2);
        
        // 输出转换结果：x unit1 = 转换后数值 目标单位
        // 例如：1 km = 1 * 1000000 / 1 mm = 1000000 mm
        int ans = ;//填入转换公式
        printf("%d %s = %d %s\n", x, s1, ans, s2);
    }
    return 0;
}
