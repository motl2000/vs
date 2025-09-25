//4057：【GESP2406一级】休息时间
#include <iostream>
using namespace std;

int main() {
    int h, m, s, k;
    cin >> h >> m >> s >> k;

    //统一成秒为单位后，计算休息时刻的秒数
    int total = h * 3600 + m * 60 + s + k;

    //计算小时
    int nh = total / 3600;
    //计算分钟
    int nm = (total % 3600) / 60;
    //计算秒数
    int ns = total % 60;

    cout << nh << ' ' << nm << ' ' << ns << '\n';
    return 0;
}
