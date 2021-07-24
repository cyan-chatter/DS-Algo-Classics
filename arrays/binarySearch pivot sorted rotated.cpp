#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearchPivotSortedRotated(int a[], int n){
	int s = 0, e = n-1;
	int mid;
	while(s<=e){
		mid = (s+e)/2;
		if(mid<(n-1) && a[mid] > a[mid+1]){
			return mid;
		}
		else if(mid>0 && a[mid] < a[mid-1]){
			return mid-1;
		}
		else{
			if(a[s] <= a[mid]){
				s = mid+1;
			}
			else if(a[e] >= a[mid]){
				e = mid-1;
			}
		}
	}
	return -1;
}

int main(){
	
	int a[] = {72,95,99,101,5,12,27,51,66};
	int n = sizeof(a)/sizeof(int);
	int key=27;
	cout<<binarySearchPivotSortedRotated(a,n);
	return 0;
 }

