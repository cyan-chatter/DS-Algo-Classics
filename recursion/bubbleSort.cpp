#include<iostream>
using namespace std;

void swap(int &a, int &b){
    a = a^b;
    b = a^b; 
    a = a^b;
}

void bubbleSort(int *a, int j, int n){
    if(n==1){
        return;
    }
    if(j == n-1){
        return bubbleSort(a,0,n-1);
    }
    if(a[j] > a[j+1]){
        swap(a[j], a[j+1]);
    }
    bubbleSort(a,j+1,n);
}

int main(){
    int ar[] = {6,4,6,3,6,4,6,9,0,4,1,5,8,4,7,9,7,5,3,6,8};
    int n = sizeof(ar)/sizeof(int);
    bubbleSort(ar,0,n);
    for(int i=0; i<n; ++i){
        cout<<ar[i]<<" ";
    }
    return 0;
}