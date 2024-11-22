//扩号匹配问题
//在某个字符串（长度不超过100）中有左括号、右括号和大小写字母；规定（与常见的算数式子一样）任何一个左括号都从内到外与在它右边且距离最近的右括号匹配。写一个程序，找到无法匹配的左括号和右括号，输出原来字符串，并在下一行标出不能匹配的括号。不能匹配的左括号用"$"标注,不能匹配的右括号用"?"标注。
#include <bits/stdc++.h>
using namespace std;
char a[101];                    //原始字符串
char aa[101];                   //标记后的字符串
int search(int x){              //从x开始找到第一个左括号
    if (x==-1){
        return -1;          //找不到左括号
    }
    else if (aa[x]=='$'){
        return x;           //找到左括号
    }
    else{
        return search(x-1); //继续向左找
    }
}
int main(){
    while (scanf("%s",a)!=EOF){
        printf("%s\n",a);
        memset(aa,' ',sizeof(aa));    //清空aa数组
        int len=strlen(a);
        for (int i=0;i<len;i++){
            if (a[i]=='('){
                aa[i]='$';          //将左括号标记为$
            }
            else if (a[i]==')'){
                int x=search(i-1);  //找最近的左括号
                if (x==-1){
                    aa[i]='?';      //找不到左括号，将右括号标记为?
                }
                else{
                    aa[x]=' ';      //找到左括号，将左括号标记为空格
                }
            }
        }
        printf("%s\n",aa);
    }

    return 0;
}