//1372：小明的账单
#include<bits/stdc++.h>
using namespace std;
int main()
{
	multiset<int> ms;                       //multiset是C++标准模板库中的一个容器，它类似于set，但允许存储重复的元素，默认元素以升序排序。
	int n, t, m; 
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &t);                    
		for(int j = 1; j <= t; ++j)
		{
			scanf("%d", &m);                //输入账单钱数 
			ms.insert(m);
		}
		multiset<int>::iterator itFirst = ms.begin();//::iterator是multiset容器的迭代器类型。itFirst是一个迭代器，它被初始化为指向ms中第一个元素的位置。
        multiset<int>::iterator itLast = prev(ms.end());//itLast也是一个迭代器，它被初始化为指向ms中最后一个元素的位置。
                                                        //prev()函数返回指向指定迭代器之前的位置的迭代器。
                                                        //end()函数返回指向容器中最后一个元素之后的位置的迭代器。
                                                        //所以prev(ms.end())返回指向ms中最后一个元素的位置。
		printf("%d %d\n", *itFirst, *itLast);
		ms.erase(itFirst); //删除itFirst
		ms.erase(itLast);  //删除itLast
	}
	return 0;
}