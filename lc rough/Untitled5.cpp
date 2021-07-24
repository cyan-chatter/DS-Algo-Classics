#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearchMod(int a[], int n){
	int s = 0, e = n-1;
	int mid,f,d=0;
	while(s<=e){
		mid = (s+e)/2;
		if(a[mid] == key){
			f = key;
			e=mid-1;
		}
		else if(a[mid]>key){
			e=mid-1;
		}
		else {
			s=mid+1;
		}
	}
	int i = f+2;
	while(a[i] == a[f]){
		a[i] = INT_MIN;
		++i;
	}
	if(i-f > 2){
		d = i-f-1;
	}
}

int main(){
	
	int a[] = {1,1,1,5,5,6,6,6,12,27,27,27,27,51,66};
	int n = sizeof(a)/sizeof(int);
	int key=12;
	cout<<binarySearchMod(a,n);
	return 0;
}

