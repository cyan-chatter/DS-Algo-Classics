#include<iostream>
using namespace std;

int rodCutting(int profit[], int n){
	if(n==0){
		return 0;
	}
	if(n==1){
		return profit[0];
	}
	int dp[n+1];
	for(int i=0; i<=n; ++i){
		dp[i] = -1; 
	}
	dp[0] = 0;
	dp[1] = profit[0];
	for(int i=2; i<=n; ++i){
		for(int j=0; j<=i; ++j){
			if(j-1 < 0){
				dp[i] = max(dp[i],profit[i-1]);
			}else{
				dp[i] = max(dp[i], profit[j-1] + dp[i-j]);	
			}
		}
	}
	return dp[n];
}

int main(){
	int rod[] = {2,3,2,5}; 
	int n = sizeof(rod)/sizeof(int);
	cout<<rodCutting(rod,n);
	return 0;
}
