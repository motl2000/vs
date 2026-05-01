//4108：【GESP2503二级】时间跨越
#include <iostream>
using namespace std;

// 判断是否为闰年
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int y, m, d, h, k;
    
    cin >> y >> m >> d >> h >> k;

    // 处理闰年
    if(isLeapYear(y)) {
        month[2] = 29;
    }

    // 先加上k小时
    h += k;

    // 当前日期加上 h / 24 天
    int newDay = d + h / 24;
    h %= 24;

    int newMonth = m;
    int newYear = y;

    if (newDay > month[newMonth]) {//如果题目不限定k<=24,就可以改成while循环处理，当然内部也需要修改
        newDay -= month[newMonth];
        newMonth++;
        if (newMonth > 12) {
            newMonth = 1;
            newYear++;
        }
    }

    cout << newYear << " " << newMonth << " " << newDay << " " << h << endl;

    return 0;
}