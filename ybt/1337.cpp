//1337：【例3-2】单词查找树
//输入为一个单词列表，每一行仅包含一个单词和一个换行/回车符。每个单词仅由大写的英文字母组成，长度不超过63个字母
//输出仅包含一个整数，该整数为单词列表对应的单词查找树的结点数。
#include<bits/stdc++.h>
using namespace std;
char s[100005];
int tot=0;//编号
int trie[100005][26];               //字典树
void insert(char *s){               //插⼊单词s
    int len=strlen(s);              //单词s的长度
    int root=0;                     //字典树上当前匹配到的结点
    for(int i=0;i<len;i++){
        int id=s[i]-'A';            //⼦节点编号,
        if(trie[root][id]==0)       //如果之前没有从root到id的前缀
            trie[root][id]=++tot;   //插⼊当前字母，同时记录节点数
        root=trie[root][id];        //如果当前字母存在，顺着字典树往下⾛
    }
}
int main(){
    while(scanf("%s",s)!=EOF)
         insert(s);
    printf("%d\n", tot + 1);
    return 0;
}