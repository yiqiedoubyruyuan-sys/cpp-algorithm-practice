/*P3367 【模板】并查集*/

#include<iostream>
using namespace std;

const int MAXN=1000001;
int father[MAXN];
int size[MAXN];
int stack[MAXN];


//初始化
void build(int n){
    for(int i=1;i<=n;i++){
        father[i]=i;
        size[i]=1;
    }
}

//找代表节点
int find(int i){
    int size=0;
    while(i!=father[i]){
        stack[size++]=i;
        i=father[i];
    }
    while(size>0){
        father[stack[--size]]=i;
    }
    return i;
}

//判断是否在同一个集合里
bool isSameSet(int x,int y){
    return find(x)==find(y);
}

//合并两个集合
void union_(int x,int y){
int fx=find(x);
int fy=find(y);
if(fx!=fy){
    if(size[fx]>size[fy]){
        size[fx]+=size[fy];
        father[fy]=fx;
    }
    else{
        size[fy]+=size[fx];
        father[fx]=fy;
    }
}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    build(a);
    for(int i=1;i<=b;i++){
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1){
            union_(x,y);
        }
        else{
            if(isSameSet(x,y)){
                cout<<'Y'<<endl;
            }
            else {
                cout<<'N'<<endl;
            }
        }
    }
    return 0;
}