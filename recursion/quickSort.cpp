#include<iostream>
using namespace std;

void swap(int &a, int &b){
    a = a^b;
    b = a^b; 
    a = a^b;
}

int partition(int *a, int s, int e){
    int i = s-1;
    int j = s;
    swap(a[(s+e)/2], a[e]);
    for(;j<e; ++j){
        if(a[j]<=a[e]){
            ++i;
            swap(a[j],a[i]);
        }
    }
    swap(a[e],a[i+1]);
    return i+1;
}

void quickSort(int *a, int s, int e){
    if(s>=e){
        return;
    }
    int p = partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}

int main(){
    int ar[] = {1,5,2,6,3,0};
    int n = sizeof(ar)/sizeof(int);
    quickSort(ar,0,n-1);
    for(int i=0; i<n; ++i){
        cout<<ar[i]<<" ";
    }
    return 0;
}