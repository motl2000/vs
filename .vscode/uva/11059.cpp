//UVA11059 - 最大乘积
#include<iostream>
using namespace std;
int main() {
    int a[20], n;
    while (cin >> n && n) 
    {
        for (int i = 0; i < n; i++)        
            cin >> a[i];
        long long ans = 0;
        for (int i = 0; i < n; i++) 
        {
            long long v = 1;
            for (int j = i; j < n; j++) 
            {
                v *= a[j];
                if (v > ans) ans = v;
            }
        }
        cout << ans << endl;
    }
    return 0;
}