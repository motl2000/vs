//2025年3月GESP 四级
//荒地开垦
//选择清扫杂物后可以释放最多荒地的点
#include<bits/stdc++.h>
 using namespace std;
 const int N = 1005;
 char mat[N][N];                            //地图
 int a[N][N];                               //a[i][j]：点(i,j)可以释放荒地的数量
 const int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
 int main() {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    assert(1 <= n && n <= 1000);
    assert(1 <= m && m <= 1000);
    for (int i = 1; i <= n; i ++)
        scanf("%s", mat[i] + 1);            //输入地图，从第二行第二列开始输入，空出第一行第一列，就免去判断上边界和左边界
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            int num = 0, p = -1;            //p：当前点周围有'#'的点的方向，num：当前点周围有'#'的点的数量
            for (int k = 0; k < 4; k ++)    //遍历四个方向    
                if (mat[i + d[k][0]][j + d[k][1]] == '#')   //当前点周围有'#'
                    num ++, p = k;              //如果只有一个'#'，正好记录这个方向
            if (mat[i][j] == '.' && num == 1)   //当前点周围有杂物且周围只有一个杂物
                a[i + d[p][0]][j + d[p][1]] ++; //表示如果清扫这个杂物，可以释放当前这个荒地，因为如果有1个以上的杂物，即使清扫了其中一个，也不能释放这个荒地
            else if (mat[i][j] == '.' && num == 0)
                ans ++;                         //当前点周围没有'#'，可开垦的数量加一
            else if (mat[i][j] == '#' && num == 0)
                a[i][j] ++;                     //当前这个'#'的点如果被清扫，也可以释放一个荒地
        }
    int mx = 0;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j <= m; j ++)
            mx = max(mx, a[i][j]);              //mx：可以释放的荒地的最大值
    cout << ans + mx << endl;
    return 0;
 }