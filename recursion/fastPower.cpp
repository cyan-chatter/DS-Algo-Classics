#include<iostream>
using namespace std;

int power(int a, int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return a;
    }
    int t = power(a,n/2);
    t *= t;
    if(n&1) t = a*t;
    return t;
}

int main(){
    int b,e;
    cin>>b>>e;
    cout<<power(b,e);
    return 0;
}