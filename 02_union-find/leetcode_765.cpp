#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
const int MAXN=1000001;
int stack[MAXN];
int father[MAXN];
int size[MAXN];
int set;
//初始化
void build(int n){
for(int i=0;i<n;i++){
    father[i]=i;
    size[i]=1;
    set=n;
}
}

//找到代表节点并且实现路径压缩
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

//合并
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
    set--;
}

int main(){
   vector<int> arr;
   int x;
   string line;

   getline(cin,line);
   stringstream ss(line);
   while(ss>>x){
    arr.push_back(x);
   }
   int m=arr.size()/2;
    build(m);
    for(int i=0;i<arr.size();i+=2){
        union_(arr[i]/2,arr[i+1]/2);
    }
    cout<<m-set;
    return 0;
    

}




