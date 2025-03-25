//1371：看病
#include<bits/stdc++.h>
using namespace std;
struct Person
{
    char name[25];
    int level;
    bool operator < (const Person &b) const             //重载<运算符，使得level大的优先级高
    {
    	return b.level > level;                         
	}
};
int main()
{
    Person per;
    int n;
    char s[25];
    scanf("%d", &n);
    priority_queue<Person> pq;                          //大根堆 
    for(int i = 1; i <= n; ++i)
    {
        scanf("%s", s);
        if(strcmp(s, "push") == 0)                      //判断是否是push
        {
        	scanf("%s%d", per.name, &per.level);
            pq.push(per);
        }
        else//pop
        {
            if(pq.empty())
            	printf("none\n");
            else
            {
                per = pq.top();
                printf("%s %d\n", per.name, per.level);
                pq.pop();
            }
        }
    }
    return 0;
}
