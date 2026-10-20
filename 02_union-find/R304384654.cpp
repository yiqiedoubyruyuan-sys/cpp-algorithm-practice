/*UVA1197*/
#include<iostream>
using namespace std;

const int MAXN=1000001;
int father[MAXN];
int size[MAXN];
int stack[MAXN];
int a;

//初始化
void build(int b){
    for(int i=0;i<b;i++){
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
    int n,m,p;
    cin>>n>>m>>p;
    build(n);
    for(int i=0;i<m;i++){
        int m1,m2;cin>>m1>>m2;
        union_(m1,m2);
    }
    for(int i=0;i<p;i++){
        int p1,p2;
        cin>>p1>>p2;
        if(isSameSet(p1,p2)){
             cout<<"Yes";
             if(i!=p-1)cout<<endl;
        }
       
        else{
            cout<<"No";
            if(i!=p-1)cout<<endl;
        }
    }
    return 0;
}


    