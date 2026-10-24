#include<bits/stdc++.h>
using namespace std;

const int MAXN=5001;
const int MAXM=200001;

int father[MAXN];
vector<array<int,3>>edges;
int n,m;

//初始化
void build(int x){
   for(int i=1;i<=x;i++){
    father[i]=i;
   }
}


//查找根节点+路径压缩
int find(int x){
    if(x!=father[x]){
        father[x]=find(father[x]);
    }
    return father[x];
}

//合并成功return ture->在一个集合里
bool union_(int x,int y){
    int fx=find(x);int fy=find(y);
    if(fx!=fy){
        father[fy]=fx;
        return true;
    }
    return false;
}

int main(){
    cin>>n>>m;
    build(n);edges.resize(m);
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    sort(edges.begin(),edges.end(),[](const auto& a,const auto& b){
        return a[2]<b[2];
    });
    int ans=0;
    int edgecnt=0;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];

        if(union_(u,v)){
            ans+=w;
            edgecnt++;
        }
        if(edgecnt==n-1){
            break;
        }
    }

    if(edgecnt==n-1){
        cout<<ans;
    }
    else{
        cout<<"orz";
    }
    return 0;
}
