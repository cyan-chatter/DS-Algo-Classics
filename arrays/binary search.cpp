#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearch(int a[], int n, int key){
	int s = 0, e = n-1;
	int mid;
	while(s<=e){
		mid = (s+e)/2;
		if(a[mid] == key){
			return mid;
		}
		else if(a[mid]>key){
			e=mid-1;
		}
		else {
			s=mid+1;
		}
	}
	return -1;
}

int main(){
	
	int a[] = {1,5,12,27,51,66};
	int n = sizeof(a)/sizeof(int);
	int key=12;
	cout<<binarySearch(a,n,key);
	return 0;
}

