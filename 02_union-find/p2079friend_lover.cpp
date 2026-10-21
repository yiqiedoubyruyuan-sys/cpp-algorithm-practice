/* 
这个题在并查集的基础上要求处理负数情况下
不过直接转正全部初始化不就行了吗
*/

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
const int MAXN=1000001;
int father[MAXN];
int size[MAXN];

//初始化
void build(int b){
    for(int i=0;i<=b;i++){
        father[i]=i;
        size[i]=1;
    }
}

//找代表节点
int find(int i){
        if(i!=father[i]){
            father[i]=find(father[i]);
        }
        return father[i];
}

//合并两个集合
void union_(int x,int y){
    int fx=find(x);
    int fy=find(y);

    if(fx==fy) return;
    if(size[fx]>=size[fy]){
        size[fx]+=size[fy];
        father[fy]=fx;
    }
    else{
        size[fy]+=size[fx];
        father[fx]=fy;
    }
}

//判断在不在一个集合里
bool isSameSet(int x,int y){
    return (find(x)==find(y));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    
    build(n);
    for(int i=0;i<p;i++){
        int x,y;
        cin>>x>>y;
        union_(x,y);
    }
    int a1=size[find(1)];
    build(m);


    for(int i=0;i<q;i++){
        int r,t;
        cin>>r>>t;
        union_(-r,-t);
    }
    int a2=size[find(1)];
    


    int ans=min(a1,a2);
    cout<<ans;
    return 0;

}