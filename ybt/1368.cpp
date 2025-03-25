//1368：对称二叉树(tree_c)
//如果二叉树的左右子树的结构是对称的，即两棵子树皆为空，或者皆不空，则称该二叉树是对称的。编程判断给定的二叉树是否对称.
//二叉树用顺序结构给出，若读到#则为空，如二叉树T1=ABCDE，又如：T2=ABCD#E，如果二叉树是对称的，输出“Yes”,反之输出“No”。
#include <iostream>
#include <cstring>
using namespace std;
string s;
int a[10000];
int main(){
    cin>>s;
    int len=s.length();
    for (int i=1;i<len;i++){
        //求二叉树的父节点编号
        int fa=(i-1)/2;
        if (s[i]!='#')
            a[fa]++;
        //如果是右子树
        if (i%2==0 && a[fa]%2!=0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    //判断最后一个叶子节点的父节点是否对称
    if (a[(len-2)/2]%2==0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}