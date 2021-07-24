#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearchSortedRotated(int a[], int n, int key){
	int s = 0, e = n-1;
	int mid;
	while(s<=e){
		mid = (s+e)/2;
		if(a[mid] == key){
			return mid;
		}
		else if(a[s] <= a[mid]){
			if(key >= a[s] && key < a[mid]){
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}
		else if(a[e] >= a[mid]){
			if(key > a[mid] && key <= a[e]){
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}
	}
	return -1;
}

int main(){
	
	int a[] = {72,95,101,1,1,12,27,51,66};
	int n = sizeof(a)/sizeof(int);
	int key=27;
	cout<<binarySearchSortedRotated(a,n,key);
	return 0;
}

