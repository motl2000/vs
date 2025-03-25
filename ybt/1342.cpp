//1342：【例4-1】最短路径问题
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n , m;
int a[110][2];                          //存储坐标
double dis[110][110];                   //存储距离
int main(){
	cin >> n;
    for(int i = 1; i <= n; i ++) 
        cin >> a[i][0] >> a[i][1];
 
    memset(dis , 127 , sizeof dis);     //初始化为无穷大
    cin >> m;
    int x , y;
    double d;
    while(m --){                        //输入边,并计算距离
 
        cin >> x >> y;
        d = sqrt((1.0 * a[x][0] - a[y][0]) * (a[x][0] - a[y][0]) + (a[x][1] - a[y][1]) * (a[x][1] - a[y][1]));
        dis[x][y] = d;
        dis[y][x] = d;
    }
    for(int k = 1; k <= n; k ++){                       //Floyd算法,k为中间点
        for(int i = 1; i <= n; i ++){                   //i为起点
            for(int j = 1; j <= n; j ++){               //枚举起点和终点
                if(dis[i][k] + dis[k][j] < dis[i][j])   //松弛操作
                    dis[i][j] = dis[i][k] + dis[k][j];
            }
        }
    }
    int s , t;
    cin >> s >> t;
 
    printf("%.2lf" , dis[s][t]);
	return 0;
}