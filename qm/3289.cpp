//3289：练47.1 交作业
//一个小组共有7位同学，狐狸老师想批改他们的作业，向第一个同学说：“交作业了！”，第一个同学向第二个同学说：“交作业了！”……同学们依次传下去，然后由7号同学将作业交给6号同学，6号交给5号……然后交给狐狸老师，问狐狸老师收到了多少本作业？
#include<iostream>                      
using namespace std;   
int jiaozuoye(int n)
{  
	if(n==7)
    	return 1;                   //第7位同学交作业本上加上自己的作业本
  	else
    	return jiaozuoye(n+1)+1;    //在后一位交上作业本上加上自己的作业本
}
int main()
{
	cout<<jiaozuoye(1)<<endl;       //从第一位同学开始叫后面的同学交作业
	return 0;
}