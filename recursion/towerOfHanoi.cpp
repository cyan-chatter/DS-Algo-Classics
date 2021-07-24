#include<iostream>
using namespace std;

int towerOfHanoi(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    return 2*towerOfHanoi(n-1) + 1;
}

int main(){
    int n = 4;
    cout<<towerOfHanoi(n);
    return 0;
}