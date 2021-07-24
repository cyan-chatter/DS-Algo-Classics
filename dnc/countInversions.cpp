#include<iostream>
using namespace std;

int piggybackOnMerge(int *A, int l, int mid, int h){
 int i=l,j=mid+1,k=0,B[h-l+1],c=0;
 while(i<=mid && j<=h){
	 if(A[i]<A[j])
	 B[k++]=A[i++];
	 else{
	 	B[k++]=A[j++];
		c += mid-i+1;  	
	 }
 }
 for(;i<=mid;i++)
 	B[k++]=A[i];
 for(;j<=h;j++)
 	B[k++]=A[j];
 for(int p=l;p<=h;p++)
 	A[p]=B[p-l];
 return c;
}


int countInversions(int *arr, int s, int e){
	if(s>=e){
		return 0;
	}
	int mid = (s+e)/2;
	int left = countInversions(arr,s,mid);
	int right = countInversions(arr,mid+1,e);
	return left + right + piggybackOnMerge(arr,s,mid,e);
}


int main(){
	int arr[] = {4,6,1,7,3,2,5};
	int n = sizeof(arr)/sizeof(int);
	cout<<countInversions(arr,0,n-1);
}
