//迷宫
#include <iostream>
using namespace std;
int k;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int startx,starty,endx,endy,flag;
void dfs(int x,int y,string maze[],int n){
    if (x==endx&&y==endy){
        cout<<"YES"<<endl;
        flag=1;
        return;
    }
    for (int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx>=0&&nx<n&&ny>=0&&ny<n&&maze[nx][ny]=='.'){
            maze[nx][ny]='#';
            dfs(nx,ny,maze,n);//这题不需要回溯，因为只要找到一条路径就可以了，回溯会超时
        }
        if (flag)
            return;
    }

}
int main(){
    cin>>k;
    for (int i=0;i<k;i++){
        int n;
        cin>>n;
        string maze[n];
        for (int j=0;j<n;j++){
            cin>>maze[j];
        }
        flag=0;
        cin>>startx>>starty>>endx>>endy;
        maze[startx][starty]='#';
        dfs(startx,starty,maze,n);
        if (flag==0)
            cout<<"NO"<<endl;

    }
    return 0;
}