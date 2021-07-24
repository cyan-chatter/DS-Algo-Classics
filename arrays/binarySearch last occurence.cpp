#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lastOccurence(int a[], int n, int key){
	int s = 0, e = n-1;
	int mid,ans = -1;
	while(s<=e){
		mid = (s+e)/2;
		if(a[mid] == key){
			ans = mid;
			s = mid+1;
		}
		else if(a[mid]>key){
			e = mid-1;
		}
		else {
			s = mid+1;
		}
	}
	return ans;
}

int main(){
	
	int a[] = {1,3,5,5,5,4,12,12,20,27,51,51,66};
	int n = sizeof(a)/sizeof(int);
	int key=5;
	cout<<lastOccurence(a,n,key);
	return 0;
}

