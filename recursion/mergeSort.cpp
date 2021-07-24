#include<iostream>
using namespace std;

void swap(int &a, int &b){
    a = a^b;
    b = a^b; 
    a = a^b;
}
int c;
void merge(int *a, int s, int mid, int e){
    int res[e-s+1];
    int i=s, j=mid+1, k=0;
    while(i<=mid && j<=e){
        if(a[i] <= a[j]){
            res[k++] = a[i++];
        }else{
            res[k++] = a[j++];
            c += (mid-i+1);
        } 
    }
    while(i<=mid){
        res[k++] = a[i++];
    }
    while(j<=e){
        res[k++] = a[j++];
    }
    for(int r=s; r<=e; ++r){
        a[r] = res[r-s];
    }
}

void mergeSort(int *a, int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    merge(a,s,mid,e);
}

int main(){
    int ar[] = {1,5,2,6,3,0};
    int n = sizeof(ar)/sizeof(int);
    mergeSort(ar,0,n-1);
    for(int i=0; i<n; ++i){
        cout<<ar[i]<<" ";
    }
    cout<<"\nInversions: "<<c;
    return 0;
}