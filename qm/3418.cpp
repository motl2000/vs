//【例72.3】 提取数字串按数值排序
//用scanf读入字符，以及相关函数实现
// #include <bits/stdc++.h>
// using namespace std;
// int a[200],n;
// int main() {   
//     char c;
//     int x=0;
//     bool flag=false;                        //标记是否有数字
//     while (scanf("%c",&c)!=EOF&&c!='\n') {  //用scanf读入字符，直到回车符结束
//         if (c>='0'&&c<='9') {               //如果是数字，计算数值
//             x=x*10+c-'0';
//             flag=true;
//         }
//         else {
//             if (flag)                       //如果有数字，存入数组，这里不能用x>0，因为x可能为0
//                 a[n++]=x;
//             x=0;    
//             flag=false;
//         }
//     }
//     if (x>0)                                //如果最后的字符是数字的情况，因为上面碰到回车符就结束了，没有存入数组
//         a[n++]=x;
//     if (n==0) {                             //如果没有数字，输出0
//         printf("0");
//         return 0;
//     }
//     sort(a,a+n);
//     if (n>0)                                //输出第一个数，后面的数前面加逗号
//         printf("%d",a[0]);
//     for (int i=1;i<n;i++)                   //输出后面的数
//         printf(",%d",a[i]);
//     return 0;
// }
//用string读入，以及相关函数实现
#include <bits/stdc++.h>
using namespace std;
string s;
int a[200],n;
int main() {
    getline(cin,s);                         //用getline读入一行
    bool flag=false;                        //标记是否有数字
    int l=0,r=0;
    for (int i=0;i<s.length();i++) {        //遍历字符串
        //用substr提取数字串
        //用isdigit判断是否是数字
        if (isdigit(s[i])) {                 //如果是数字，计算数值
            if(!flag) l=i;                    //记录数字串的起始位置
            r=i;                             //记录数字串的结束位置
            flag=true;
        }
        else {
            if (flag) {                      //如果有数字，存入数组
                a[n++]=stoi(s.substr(l,r-l+1));  //stoi将字符串转为整数
            }
            flag=false;
        }


    }
    if (flag) {                             //如果最后的字符是数字的情况，因为上面碰到回车符就结束了，没有存入数组
        a[n++]=stoi(s.substr(l,r-l+1));
    }
    else if (n==0) {                        //如果没有数字，输出0
        cout<<"0";
        return 0;
    }
    sort(a,a+n);
    if (n>0)                                //输出第一个数，后面的数前面加逗号
        cout<<a[0];
    for (int i=1;i<n;i++)                   //输出后面的数
        cout<<","<<a[i];
    return 0;
}
