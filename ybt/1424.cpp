//1424：【例题3】喷水装置
//二维重叠转换为一维重叠
#include <bits/stdc++.h>
using namespace std;
 
// 比较函数，按照区间的终点进行排序
bool cmp(const pair<double, double>& p1, const pair<double, double>& p2) {
    return p1.second > p2.second;
}
 
int main() {
    int t;
    cin >> t;                       // 读取测试用例的数量
 
    for (int i = 0; i < t; ++i) {   // 遍历每个测试用例
        int n;
        double l, w;
        cin >> n >> l >> w;         // 对于每个测试用例，首先读取n、l和w
        
        vector<pair<double, double>> v1;    // 存储满足条件的圆的起始和结束位置
        for (int j = 0; j < n; ++j) {       // 遍历所有圆
            double loc, r;
            cin >> loc >> r;                // 读取每个圆的位置和半径
            
            if (r > w / 2) {                // 如果圆的半径大于水带宽度的一半，则进一步计算
                double start = loc - sqrt(r * r - w * w / 4);
                double end = loc + sqrt(r * r - w * w / 4);
                v1.push_back({start, end}); // 将计算得到的覆盖范围加入向量
            }
        }
 
        double current = 0;                 // 当前覆盖到的位置
        sort(v1.begin(), v1.end());         // 根据起点对区间进行排序
        int flag = 0, num = 0;              // 初始化标志位和使用的喷水装置数量
 
        while (current < l) {               // 当还未覆盖整个长度时继续循环
            vector<pair<double, double>> v2;// 存储可能用于覆盖当前点的区间
            for (auto it = v1.begin(); it != v1.end();) {
                if (it->first <= current) { // 如果区间的开始位置在当前覆盖范围内
                    v2.push_back(*it);      // 加入临时向量
                    it = v1.erase(it);      // 从原向量中移除该元素
                } else {
                    break;
                }
            }
 
            if (v2.empty()) {               // 如果没有合适的区间可以使用
                flag = 1;
                break;
            }
            //从可以覆盖当前点的喷嘴中找出覆盖范围最大的
            sort(v2.begin(), v2.end(), cmp); // 按照区间终点降序排列
            num++;                           // 增加使用的喷水装置数量
            current = v2.begin()->second;    // 更新当前覆盖到的最大位置
        }
 
        if (flag == 1) {
            cout << -1 << endl;             // 如果无法完全覆盖，输出-1
        } else {
            cout << num << endl;            // 输出需要使用的最小喷水装置数量
        }
    }
 
    return 0;
}