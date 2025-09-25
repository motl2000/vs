//1435：【例题3】曲线
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

const double EPS = 1e-9;
const double INF = 1e18;

struct Func {
    double a, b, c;
    double eval(double x) const {
        return a * x * x + b * x + c;
    }
};

// 计算 F(x)
double F(const vector<Func>& fs, double x) {
    double maxVal = -INF;
    for (const auto& f : fs) {
        maxVal = max(maxVal, f.eval(x));
    }
    return maxVal;
}

// 三分搜索 F(x) 在 [L, R] 上的最小值
double ternarySearch(const vector<Func>& fs, double L, double R) {
    for (int iter = 0; iter < 100; ++iter) {//暂且认为 100 次迭代后精度足够（经验值）
        if (R - L < EPS) break;
        double m1 = L + (R - L) / 3.0;
        double m2 = R - (R - L) / 3.0;
        if (F(fs, m1) + EPS > F(fs, m2))   // 注意浮点比较
            L = m1;
        else
            R = m2;
    }
    return F(fs, (L + R) / 2.0);
}

int main() {
    cout << fixed << setprecision(4);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<Func> fs(n);
        for (int i = 0; i < n; ++i) {
            cin >> fs[i].a >> fs[i].b >> fs[i].c;
        }
        double ans = ternarySearch(fs, 0.0, 1000.0);
        cout << round(ans * 10000.0) / 10000.0 << '\n';   // 四舍五入到 4 位
    }
    return 0;
}
