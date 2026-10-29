/*https://www.luogu.com.cn/problem/solution/P1443*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN=401;
const int MAXM=401;

bool visited[MAXN][MAXM]={false};
int queue_[MAXN*MAXM][2];
int l,r;
int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={-1,1,-2,2,-2,2,-1,1};


void minDistance(vector<vector<int>>&grid,int x,int y){
int n=grid.size();
int m=grid[0].size();
int level=0;
grid[x][y]=0;
l=r=0;
queue_[r][0]=x;
queue_[r++][1]=y;
visited[x][y]=true;
while(l<r){
    level++;
    int size=r-l;

    for(int k=0;k<size;k++)
    {
        int x0=queue_[l][0];
        int y0=queue_[l++][1];

        for(int i=0;i<8;i++){
            int nx0=x0+dx[i];
            int ny0=y0+dy[i];

            if(nx0>=0&&nx0<n
               &&ny0>=0&&ny0<m
            &&!visited[nx0][ny0]){
                queue_[r][0]=nx0;
                queue_[r++][1]=ny0;
                visited[nx0][ny0]=true;
                grid[nx0][ny0]=level;
            }
        }
    }
}

}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<vector<int>> grid(n,vector<int>(m,-1));
    minDistance(grid,x-1,y-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
            if(j==m-1)cout<<endl;
        }
    }
   
    return 0;
}