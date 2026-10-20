/*
题目：p8813_power
算法：思维
核心思想：最大值是1e9所以b=2时 a最大为[sqrt(1e9)]=31622,当a=2时b最大为[log2(1e9)]=29 
特判a,b=1的情况，其他情况直接枚举即可
区域逻辑 边界处理
*/




#include<iostream>
using namespace std;
const int MAX=1e9;
typedef long long i64;
i64 power(i64 a,i64 b){
    i64 ans=1;
    for(int i=0;i<b;i++){
        
    if(ans>MAX/a){
        return -1;
    }
    ans*=a;
}
return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 a,b;
    cin>>a>>b;
    if(a==1||b==1){
        if(a==1){
            cout<<1;
            return 0;
        }
        else {
            cout<<a;
            return 0;
        }
    }
    else {
        if(a>31622||b>29){
            cout<<-1;
        }
        else{
            cout<<power(a,b);
        }
    }
    return 0;
}