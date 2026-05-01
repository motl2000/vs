//4158：【GESP2512四级】优先购买
//贪心、排序
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <assert.h>
using namespace std;

// 商品结构体
struct Item {
    string name;   // 商品名
    int price;     // 价格
    int priority;  // 优先级（数值越小优先级越高）
};

// 商品排序比较函数（选择购买顺序）
bool cmp(const Item &a, const Item &b) {
    if (a.priority != b.priority) return a.priority < b.priority;  // 优先级小的在前（优先级高）
    if (a.price != b.price) return a.price < b.price;              // 价格小的在前
    return a.name < b.name;                                        // 名字字典序小的在前
}

string s[1005];          // 存储购买成功的商品名
std::map<string, int> mp; // 商品名到优先级的映射（用于查重）

int main() {
    int M, N;
    cin >> M >> N;  // M:预算，N:商品数量
    
    Item items[N];
    // 读取商品信息
    for (int i = 0; i < N; ++i) {
        cin >> items[i].name >> items[i].price >> items[i].priority;
        
        mp[items[i].name] = items[i].priority;
    }
    
    // 按优先级、价格、名字字典序对商品排序（确定购买顺序）
    sort(items, items + N, cmp);
    
    int budget = M;  // 剩余预算
    int count = 0;   // 购买商品数量
    
    // 贪心策略：按顺序购买能买得起的商品
    for (int i = 0; i < N; ++i) {
        if (items[i].price <= budget) {  // 买得起
            budget -= items[i].price;     // 扣除价格
            s[count++] = items[i].name;   // 记录商品名
        }
    }
    
    // 按字典序输出购买商品名（题目输出要求）
    sort(s, s + count);
    for (int i = 0; i < count; ++i) {
        cout << s[i] << endl;
    }
    
    return 0;
}
