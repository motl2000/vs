//1339：【例3-4】求后序遍历
//输入：共两行，第一行一个字符串，表示树的先序遍历，第二行一个字符串，表示树的中序遍历。树的结点一律用小写字母表示
//输出：一行，表示树的后序遍历
#include <bits/stdc++.h>
using namespace std;
string pre, in;
void post(int l1, int r1, int l2, int r2) { //l1,r1表示先序遍历的区间，l2,r2表示中序遍历的区间
    if (l1 > r1) return;
    int k = in.find(pre[l1]);               //找到根节点在中序遍历中的位置
    post(l1 + 1, l1 + k - l2, l2, k - 1);   //递归左子树
    post(l1 + k - l2 + 1, r1, k + 1, r2);   //递归右子树
    cout << pre[l1];                        //输出根节点
}
int main() {
    cin >> pre >> in;
    post(0, pre.size() - 1, 0, in.size() - 1);
    return 0;
}