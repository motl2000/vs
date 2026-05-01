//4078：【GESP2409三级】回文拼接
#include<bits/stdc++.h>  
using namespace std;      

int main(){
    int n,k;              
    cin>>n;               
    
    for(int i=1;i<=n;i++){  
        string s;           
        cin>>s;             
        int m = s.length(); // 获取字符串长度
        int fl = 0;         // 标记是否找到合法拆分，0表示未找到，1表示找到
        
        // 枚举拆分位置j，将字符串分成s[0..j-1]和s[j..m-1]两部分
        // j从2开始：保证第一部分至少2个字符（非空且需要形成回文）
        // j<=m-2：保证第二部分至少2个字符
        for(int j=2;j<=m-2;j++){
            // s1: 前半部分子串 [0, j)
            string s1=s.substr(0,j);
            // s2: 后半部分子串 [j, m)
            string s2=s.substr(j,m-j);
            
            string t1="",t2="";  // 用于存储反转后的字符串
            
            // 反转s1存入t1
            for(int k=(int)s1.size()-1;k>=0;k--)t1+=s1[k]; 
            // 反转s2存入t2  
            for(int k=(int)s2.size()-1;k>=0;k--)t2+=s2[k]; 
            
            // 判断两部分是否都是回文：正读反读相同
            if(t1==s1&&t2==s2){
                fl=1;      // 找到合法拆分，标记为找到
                break;     // 提前退出循环
            }
        }
        
        // 根据标记输出结果
        if(fl)
            cout<<"Yes\n";   
        else 
            cout<<"No\n";     
    }
}
