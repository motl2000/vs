//除法（Division,uva725）
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n;
    char buf[99];                                   //存储字符串
    while(scanf("%d",&n),n) {
        int cnt = 0;
        for(int fghij = 1234;;fghij++) {            //枚举fghij，由于数字不能重复，所以从1234开始
            cnt++;
            int abcde = fghij*n;
            sprintf(buf,"%05d%05d",abcde,fghij);    //将abcde和fghij转为字符串
            if(strlen(buf)>10) break;               //如果字符串长度大于10，说明有重复数字
            sort(buf,buf+10);
            bool ok = true;
            for(int i=0;i<10;i++) {                 //判断是否有重复数字
                if(buf[i]!='0'+i) ok = false;
            }
            if(ok) {
                
                printf("%05d / %05d = %d\n",abcde,fghij,n);
            }
        }
        printf("枚举次数为%d.\n",cnt);
    }
    return 0;
}