//1396：病毒(virus)
/**
【解题思路】
原字典中的单词是按照字母顺序排列的，指的就是原文件中的单词都是按照字典序顺序排列的。
既然是字典，可以认为其中不存在相同的单词。
也就是下面的单词在字典序意义下一定大于上面的单词。
假设存在被病毒感染后的字符a、b，分别是图中的一个顶点。如果a被病毒感染前的字符的ASCII码小于b被病毒感染前的字符的ASCII码，那么认为顶点a到顶点b有一条有向边。
读入被病毒感染后的一个字符串s，和上一次读入的字符串ls进行比较，假设二者第一个不同的字符（包括字符串末尾的’\0’）是第i个字符，也就是s[i]和ls[i]，那么根据字典序的定义，s[i]在被病毒感染前的字符的ASCII码一定大于ls[i]在被病毒感染前的ASCII码，也就是顶点ls[i]到顶点s[i]有一条有向边。
遍历被病毒感染后的字典，根据以上方法建图。
要想得到完整的感染前后所有字符的一一对应关系，那么该有向图无环且其拓扑排序序列应该是唯一的。（如果初始情况或删掉某个顶点后，入度为0的顶点始终只有1个，那么拓扑排序是唯一的）
得到的拓扑排序序列即为a~z字符序列被感染后变成的字符序列。

注意：给定的感染后的字符只是a~z中的部分字符，将这些字符保存在一个set中。访问顶点时，遍历这个set就可以访问到所有的顶点。
对于最后输入的待还原的字符串，也要先判断其中的字符是否都是保存感染后字符的set中的字符，如果存在其它字符，直接输出0。
*/
#include<bits/stdc++.h>
using namespace std;
#define N 30
int edge[N][N], deg[N];                  //edge[i][j]：被感染后的字母i到j有一条边，即字母i应在j前，deg[i]：后一个字母的入度
set<int> st;                            //保存被感染后的所有字符 
map<char, char> mp;                     //mp[i]：感染后的字符i原来是什么字符 
bool topoSort()                         //如果返回值为false，则该有向图没有拓扑排序或没有唯一拓扑排序 
{
	int ct = 0;
	char alph = 'a';
	queue<int> que;
	for(int v : st) 
        if(deg[v] == 0)
        {
            que.push(v);
            ct++;
        }
	if(ct > 1)//入度为0的应该只有1个 
		return false;
	while(!que.empty())
	{
		int u = que.front();
		que.pop();
		mp[u+'a'] = alph++;//拓扑排序序列对应a,b,c... 
		ct = 0;
		for(int v : st) if(edge[u][v] && --deg[v] == 0)
		{
			que.push(v);
			ct++;
		}
		if(ct > 1)//删掉u后，入度为0的应该只有1个 
			return false;
	}
	return mp.size() == st.size();//st中每个字符都有对应的字符，图中才没有环，是完成了拓扑排序 
}
int main()
{
	string s, ls, t;                    //ls：上一个字符串
	int k;
	cin >> k;
	for(int j = 1; j <= k; ++j)
	{
		cin >> s;
		for(char c : s)                 //把所有感染后的字符串中的字符加入st 
			st.insert(c-'a');
		if(j == 1)                      //第一次循环只记录ls
		{
			ls = s; 
			continue;
		}
		for(int i = 0; i < s.length(); ++i) 
		{
			if(s[i] != ls[i])
			{
				if(ls[i] != '\0')
				{
					edge[ls[i]-'a'][s[i]-'a'] = 1;  //ls[i]到s[i]有一条边
					deg[s[i]-'a']++;                //s[i]的入度+1
				}
				break;
			}
		}
		ls = s;                                     //更新ls,准备下一个比较
	}
	cin >> t;                           //待转换字符串
	bool hasAns = topoSort();
	for(char c : t) 
        if(st.count(c-'a') == 0)        //如果出现不存在的字符 
		    hasAns = false;
	if(hasAns)
		for(char c : t)
			cout << mp[c];
	else
		cout << 0;
	return 0;
}
