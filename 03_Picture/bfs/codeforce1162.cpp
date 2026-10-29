#include<bits/stdc++.h>
using namespace std;

const int MAXN=101;
const int MAXM=101;

int queue_[MAXN*MAXM][2];
bool visited[MAXN][MAXM];
int l,r;

int move_[5]={-1,0,1,0,-1};


int maxDistance(vector<vector<int>>& grid){
    l=r=0;
    int n=grid.size();
    int m=grid[0].size();
    int seas=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                visited[i][j]=true;
                queue_[r][0]=i;
                queue_[r++][1]=j;
            }
            else{
                visited[i][j]=false;
                seas++;
            }
        }
    }
    if(seas==0||seas==n*m){
        return -1;
    }
    int level=0;
    while(l<r){
        level++;
        int size=r-l;
        for(int k=0;k<size;k++){
            int x=queue_[l][0];
            int y=queue_[l++][1];

            for(int i=0;i<4;i++){
                int nx=x+move_[i];
                int ny=y+move_[i];

                if(nx>0&&ny>0
                &&nx<n&&ny<m
                &&!visited[nx][ny]){
                    visited[nx][ny]=true;
                    queue_[r][0]=nx;
                    queue_[r++][1]=ny;
                }
            }
        }
    }
    return level-1;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>>grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<maxDistance(grid)<<endl;
    return 0;
}