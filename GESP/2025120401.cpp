//建造
//模拟
#include <iostream>
using namespace std;
int a[1010][1010];  // 存储地形海拔高度，下标从1开始
int main() {
    int M, N, H;
    cin >> M >> N >> H;  // 输入行数、列数、最大允许高度差
    // 读取地形数据
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> a[i][j];
        }
    }
    int max_sum = 0;  // 记录符合条件的最大海拔和
    // 遍历所有可能的3x3区域左上角坐标(i,j)
    for (int i = 1; i <= M - 2; ++i) {
        for (int j = 1; j <= N - 2; ++j) {
            // 初始化当前区域的统计值
            int local_max = a[i][j];    // 当前区域最高海拔
            int local_min = a[i][j];    // 当前区域最低海拔
            int local_sum = 0;          // 当前区域海拔总和
            
            // 遍历3x3区域内的9个点
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    int height = a[i + x][j + y];
                    local_sum += height;
                    if (height > local_max) local_max = height;
                    if (height < local_min) local_min = height;
                }
            }
            // 检查是否适合建造停机坪（高度差不超过H）
            if (local_max - local_min <= H) {
                if (local_sum > max_sum) {
                    max_sum = local_sum;  // 更新最大和
                }
            }
        }
    }
    cout << max_sum;  // 输出结果
    return 0;
}
