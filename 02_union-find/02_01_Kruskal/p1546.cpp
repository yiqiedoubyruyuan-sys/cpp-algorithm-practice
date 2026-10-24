/*https://www.luogu.com.cn/problem/P1546?utm_source=chatgpt.com*/

#include<bits/stdc++.h>
using namespace std;


const int MAXN=101;
const int MAXM=1e5+1;
const int MAX=1e9;

int father[MAXN];


struct Edge{
    int u,v,w;
};
Edge edges[10005];

bool cmp(Edge a,Edge b){
    return a.w<b.w;
}

void build(int x){
    for(int i=0;i<x;i++){
        father[i]=i;
    }
}

int find(int i){
    if(i!=father[i]){
        father[i]=find(father[i]);
    }
    return father[i];
}

bool union_(int x,int y){
    int fx=find(x);int fy=find(y);
    if(fx!=fy){
        father[fx]=fy;
        return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    build(n);
    int cnt=0;
    int ans=0;
    int edgecnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int t;cin>>t;
            if(i<j){
             edges[cnt]={i,j,t};
             cnt++;
            }
        }
    }
    sort(edges,edges+cnt,cmp);
    for(int i=0;i<cnt;i++){
        if(union_(edges[i].u,edges[i].v)){
            ans+=edges[i].w;
            edgecnt++;
        }
        if(edgecnt==n-1){
            break;
        }
    }
    cout<<ans;
    return 0;
    
}