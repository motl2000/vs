//例7.6】黑白棋子的移动
#include <iostream>
#include <iomanip>
using namespace std;
int n,step,space;                       //n表示黑白棋子的个数，step表示步数，space表示空格的位置
char c[101];
void print(){
    int i;
    cout<<"step";
    if (step<10)                        //控制输出格式,书上的代码有问题
        cout<<' ';
    cout<<step<<":";
    for (i=1;i<=2*n+2;i++)
        cout<<c[i];
    cout<<endl;
    step++;
}
void init(int n){
    int i;
    step=0;
    space=2*n+1;
    for (i=1;i<=n;i++)
        c[i]='o';
    for (i=n+1;i<=2*n;i++)
        c[i]='*';
    c[2*n+1]='-';                       //初始化空格在最后
    c[2*n+2]='-';
    print();
}
void move(int k){                   
    int i;
    for (i=0;i<=1;i++){                 //移动黑白棋子到空格位置
        c[space+i]=c[k+i];
        c[k+i]='-';                     //原位置变成空格
    }
    space=k;                            //空格位置更新
    print();
}
void f(int n){
    int i,k;
    if (n==4){                          //基础情况是n=4
        move (4);
        move (8);
        move (2);
        move (7);
        move (1);
    }
    else{
        move(n);                    //先移动中间的白黑棋子到最后
        move(2*n-1);                //再移动2*n-1位置的白黑棋子到刚才的空位
        f(n-1);                     //此时前2*（n-1)个棋子已经排好，递归处理前2*(n-1)个棋子，直到只剩8个棋子
    }
}
int main(){
    cin>>n;
    init(n);
    f(n);
    return 0;
}