#include<iostream>
using namespace std;

int firstOcc(int *a, int n, int &key){
    if(n==0){
        return -1;
    }
    int mila = firstOcc(a,n-1,key);
    if(mila == -1 && a[n-1] == key){
        mila = n-1;
    }
    return mila;
}

int firstOcc2(int *a, int n, int &key){
    if(n<=0){
        return -1;
    }
    if(a[0] == key){
        return 0;
    }
    int mila = firstOcc2(a+1,n-1,key);
    if(mila >= 0){
        ++mila;
    }
    return mila;
}

int main(){

    int ar[] = {2,5,3,6,3,5,34,4,4,3,5,3,6,34,6,54,8};
    int key = 34;
    int n = sizeof(ar)/sizeof(int);
    cout<<firstOcc2(ar,n,key);
    return 0;
}