/*https://www.luogu.com.cn/problem/P1746?utm_source=chatgpt.com*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN=1001;
int move_[5]={-1,0,1,0,-1};
int queue_[MAXN*MAXN][2];
bool visited[MAXN][MAXN]={false};
int l,r;
int x1,x2,sy,y2;


int minDistance(vector<vector<int>>&grid){
    if (x1 == x2 && sy == y2) return 0;
l=r=0;
queue_[r][0]=x1;
queue_[r++][1]=sy;
visited[x1][sy]=true;
int n=grid.size();
int m=grid[0].size();

int level=0;
while(l<r){
    level++;
int size=r-l;

for(int k=0;k<size;k++){
    int x=queue_[l][0];
    int y=queue_[l++][1];

    for(int i=0;i<4;i++){
        int nx=x+move_[i];
        int ny=y+move_[i+1];

        
        if(nx>=0&&nx<n
         &&ny>=0&&ny<m
        &&!visited[nx][ny]){
            
            if(nx==x2&&ny==y2){
            return level;
            }
            queue_[r][0]=nx;
            queue_[r++][1]=ny;
            visited[nx][ny]=true;
        }
    }
}

}
return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
        grid[i][j]=s[j]-'0';
        if(grid[i][j]==1){
            visited[i][j]=true;
        }
        }
    }
    cin>>x1>>sy>>x2>>y2;
    x1--;
sy--;
x2--;
y2--;
    int ans=minDistance(grid);
    cout<<ans;
    return 0;
}