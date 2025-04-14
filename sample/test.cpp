#include <iostream>
using namespace std;
int main()
{
    string ch="hello";
    if(ch[5]==NULL)
    {
    cout<<"right"<<endl;
    }
    else if (ch[5]=='\0')
    {
        cout<<"wrong"<<endl;
    }
    else
    {
        cout<<"hello"<<endl;
    }
    return 0;
}