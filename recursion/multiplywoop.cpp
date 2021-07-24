#include<iostream>
using namespace std;

int badMul(int &a, int n){
    if(a==0 || n==0){
        return 0;
    }
    if(n==1){
        return a;
    }
    if(a==1){
        return n;
    }
    int mul;
    return mul = a + badMul(a,n-1);
}

int main(){
    cout<<"Hello Wanker: ";
    int a,b;
    cin>>a>>b;
    if(a<b){
        a = a+b;
        b = a-b;
        a = a-b;
    }
    cout<<badMul(a,b);
    return 0;
}