//4089：【GESP2412一级】温度转换
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double K;
    if (!(cin >> K)) return 0;

    //将K转换为摄氏温度C，
    double C = K - 273.15;
    //再转换为华氏温度F
    double F = C * 1.8 + 32;

    //如果F大于212.0，则输出“Temperature is too high!”
    if (F > 212.0) {
        cout << "Temperature is too high!" << endl;
    } else {
        cout << fixed << setprecision(2);
        cout << C << " " << F << endl;
    }
    return 0;
}
