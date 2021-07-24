#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int binarySearchMinimizedMaxSubsegmentSum(int a[], int n, int m){
	int s = a[n-1], e = 0;
	int mid, ans = -1;
	for(int i=0; i<n; ++i){
		e += a[i];
	}
	
	while(s<=e){
		mid = (s+e)/2;
		int conf = 0, ssum = 0, maxsum = 0;
		for(int i=0; i<n; ++i){
			if((ssum + a[i]) <= mid){
				ssum += a[i];
 			}else{
 				ssum = a[i];
 				++conf;
			 }
			if(ssum > maxsum){
				maxsum = ssum;
			} 
		}
		++conf;
		if(conf == m){
			ans = mid;
			e = mid-1;
		}else{
			s = mid+1;
		}
	}
	
	return ans;
}

int main(){
	
	int a[] = {10,20,30,40};
	int n = sizeof(a)/sizeof(int);
	int m = 2;
	cout<<binarySearchMinimizedMaxSubsegmentSum(a,n,m);
	return 0;
}

