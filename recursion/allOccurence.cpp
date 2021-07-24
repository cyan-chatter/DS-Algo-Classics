#include<iostream>
using namespace std;

int storeAllOcc(int *a, int i, int n, int &key, int* out, int j=0){
    if(i==n){
        return j;
    }
    if(a[i] == key){
        out[j] = i;
        return storeAllOcc(a,i+1,n,key,out,j+1);
    }
    return storeAllOcc(a,i+1,n,key,out,j);    
}

void opAllOcc(int *a, int i, int n, int &key){
    static int f = 0;
    static int l = 0;
    static int s = 0;
    if(l==0){
        s = i;
        l = 1;
    }
    if(i==n){
        return;
    }
    if(a[i] == key){
        cout<<i<<" ";
        f = 1;
    }
    opAllOcc(a,i+1,n,key);
    if(i==s && f==0){
        cout<<"-1";
    }
}


int main(){
    int ar[] = {2,5,3,6,3,5,34,4,4,3,5,3,6,34,6,54,8};
    int key = 3;
    int out[100];
    int n = sizeof(ar)/sizeof(int);
    int m = storeAllOcc(ar,0,n,key,out);
    for(int i=0; i<m; ++i){
        cout<<out[i]<<" ";
    }
    return 0;
}