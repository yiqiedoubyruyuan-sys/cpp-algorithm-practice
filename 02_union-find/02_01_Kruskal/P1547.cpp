/*https://www.luogu.com.cn/problem/P1547
最小生成树的应用
*/

#include<bits/stdc++.h>
using namespace std;

const int MAXN=20001;
const int MANM=1e4;

vector<array<int,3>>edges;
int father[MAXN];
//初始化
void build(int x){
    for(int i=1;i<=x;i++)
    father[i]=i;
}

//找头节点
int find(int i){
    if(i!=father[i]){
        father[i]=find(father[i]);
    }
    return father[i];
}

//判断是否合并
bool union_(int x,int y){
    int fx=find(x);int fy= find(y);
    if(fx!=fy){
        father[fx]=fy;
        return true;
    }
    return false;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    edges.resize(m);build(n);
    for(int i=0;i<m;i++){
        cin>>edges[i][0]
        >>edges[i][1]
        >>edges[i][2];
    }
    sort(edges.begin(),edges.end(),[](const auto& a,const auto& b){
        return a[2]<b[2];
    });

    int edgescnt=0;
    int ans_max=0;
    for(int i=0;i<m;i++){
        int v=edges[i][0];
        int u=edges[i][1];
        int w=edges[i][2];

        if(union_(u,v)){
            edgescnt++;
            if(w>ans_max){
                ans_max=w;
            }
        }

        if(edgescnt==n-1){
            break;
        }
    }
    cout<<ans_max;
    return 0;
}