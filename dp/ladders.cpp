#include<iostream>
using namespace std;

int ways(int n, int k, int dp[]){
	if(n<0){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	int ans = 0;
	for(int i=1; i<=k; ++i){
		ans += ways(n-i,k,dp);
	}
	dp[n] = ans;
	return ans;
}

int laddersDP(int n, int k){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	int *dp = new int[n+1];
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<=n; ++i){
		dp[i] = 0;
		for(int j=1; j<=k; ++j){
			if(i-j >= 0){
				dp[i] += dp[i-j];	
			}
		}
	}
	return dp[n];
}// O(nk)

int ladders(int n, int k){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	int *dp = new int[n+1];
	dp[0] = 1;
	dp[1] = 1;
	//calculate the first window
	for(int i=2; i<=k+1; ++i){
		dp[i] = 0;
		for(int j=1; j<=k; ++j){
			if(i-j >= 0){
				dp[i] += dp[i-j];	
			}
		}
	}
	//calculate all other windows
	for(int i=k+2; i<=n; ++i){
		dp[i] = 2*dp[i-1] - dp[i-1-k];
	}
	return dp[n];
}

int main(){
	int n=50;
	int k=3;
	int dp[n+1];
	for(int i=0; i<=n; ++i){
		dp[i] = -1;
	}
	dp[0] = 1;
	cout<<ladders(n,k);
	return 0;
}
