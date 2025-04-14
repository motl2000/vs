    //1389：亲戚
    #include<bits/stdc++.h>
    using namespace std;
    #define N 1000005
    int fa[N], peoNum[N];           //peoNum[i]：以i为根结点的家族人数
    void initFa(int n)
    {
        for(int i = 1; i <= n; ++i)
        {
            fa[i] = i;
            peoNum[i] = 1;          //默认每个人是一个家族，有一个人
        }
    }
    int find(int x)
    {
        if(x == fa[x])
            return x;
        else
            return fa[x] = find(fa[x]);
    }
    void merge(int i, int j)
    {
        int x = find(i), y = find(j);
        if(x == y)                      //如果x, y已经在一个集合内，直接返回 
            return;
        fa[x] = y;                      //x的双亲设为y 
        peoNum[y] += peoNum[x];         //以y为根结点的集合元素数量增加以x为根结点的集合的元素数量 	
    }
    int main()
    { 
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        char c;
        int n, m, a, b;
        cin >> n >> m;
        initFa(n);
        for(int i = 1; i <= m; ++i)
        {
            cin >> c;
            if(c == 'M')
            {
                cin >> a >> b;
                merge(a, b);//合并a，b所在的集合 
            }
            else // c == 'Q'
            {
                cin >> a;
                cout << peoNum[find(a)] << '\n';//输出a所在家族的人数 
            }
        }
        return 0;
    }
