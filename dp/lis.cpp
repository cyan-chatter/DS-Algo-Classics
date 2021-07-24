#include<iostream>
using namespace std;

int lis(int arr[], int n){
	if(n==0){
		return 0; 
	}
	int dp[101];
	for(int i=0; i<n; ++i){
		dp[i] = 1;
	}
	int ans = -1;
	for(int i=0; i<n; ++i){
		for(int j=0; j<i; ++j){
			if(arr[j] <= arr[i]){
				dp[i] = max(dp[i], 1+dp[j]);
			}
		}
		ans = max(ans,dp[i]);
	}
	return ans;
}

int main(){
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80, 6};
	int n = sizeof(arr)/sizeof(int);
	cout << lis(arr,n);
	return 0;
}
