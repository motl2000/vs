//4062：【GESP2406三级】寻找倍数
#include<bits/stdc++.h>    
using namespace std;        

const int N = 1e5+10;       // 定义常量N = 100010，数组最大容量（留一点余量）
int a[N];                   // 全局数组，用于存储输入的n个数

int main(){
    int t;                  
    cin>>t;                 // 读入测试组数
    while(t--){             // 循环处理每组测试数据
        int n;              
        cin>>n;             
        
        int x = 0;          // x：记录数组中的最大值，初始化为0
        
        // 第一遍遍历：读入数据并找出最大值
        for(int i=1;i<=n;i++){
            cin>>a[i];      // 读入第i个数
            x = max(x,a[i]); // 更新最大值
        }
        
        int fl = 0;         // 标记变量：fl=0表示"Yes"，fl=1表示"No"
                            // 含义：判断最大值x是否能被数组中所有元素整除
        
        // 第二遍遍历：检查x是否能被每个a[i]整除
        for(int i=1;i<=n;i++){
            if(x % a[i])     // 如果x除以a[i]有余数（不能整除）
                fl = 1;      // 标记为不满足条件
        }
        
        if(fl) 
            cout<<"No\n";   // 存在不能整除的情况
        else   
            cout<<"Yes\n";  // 所有元素都能整除x
    }
    return 0;               
}
