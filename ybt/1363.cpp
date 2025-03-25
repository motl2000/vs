//1363：小球(drop)
//虽然可以用链式存储方式，但此题用顺序存储更方便
//可以用二叉树的顺序存储结构来模拟这个过程，根结点为1，左子树为2*根结点，右子树为2*根结点+1。
#include <iostream>
#include <queue>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
bool tree[1100000];//顺序存储结构二叉树 初始值为false
int main()
{
    int mx, D, I, p;                    //p为此时指向的结点在数组中的下标 第1位置是树的根
    cin >> D >> I;
    mx = int(pow(2, D))-1;              //mx为树的最大结点数
	for(int i = 1; i <= I; ++i)
    {
        p = 1;
        while(p <= mx/2)                //叶子结点那一层不用计算
        {
            if(tree[p])
            {
                tree[p] = false;
                p = 2 * p + 1;          //走右子树
            }
            else
            {
                tree[p] = true;
                p = 2 * p;              //走左子树
            }
        }
    }
    cout << p;
    return 0;
}