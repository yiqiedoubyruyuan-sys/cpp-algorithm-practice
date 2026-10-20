/*
并查集的使用是如下的场景
1)一开始每个元素都拥有自己的集合，在自己的集合里只有这个元素自己
2)intfind(i):查找i所在集合的代表元素，代表元素来代表i所在的集合->find里面有路径压缩
3)booleanisSameSet(a，b):判断a和b在不在一个集合里
4)void union(a，b):a所在集合所有元素与b所在集合所有元素合并成一个集合
5)各种操作单次调用的均摊时间复杂度为0(1)
*/

#include<iostream>
using namespace std;

const int MAXN=1000001;
int father[MAXN];
int size[MAXN];
int stack[MAXN];
int n;

//初始化
void build(){
    for(int i=0;i<=n;i++){
        father[i]=i;
        size[i]=1;
    }
}

//i号节点，向上一直找，找到代表节点,返回
int find(int i){
    int size=0;//沿途个数
    while(i!=father[i]){
        stack[size++]=i;
        i=father[i];
    }
    //沿途收集好了，i跳到了代表节点
    while(size>0){
        father[stack[size--]]=i;
    }
    return i;
}

//判断是否在同一个集合里
bool isSameSet(int x,int y){
    return find(x)==find(y);
}

//合并两个集合
void Union(int x,int y){
    int fx=find(x);
    int fy=find(y);//代表节点
    if(fx!=fy){
        if(size[fx]>=size[fy]){
            size[fx]+=size[fy];
            father[fy]=fx;
        }
        else{
            size[fy]+=size[fx];
            father[fx]=fy;
        }
    }
}