#include<iostream>
using namespace std;

int fibonacci(int n, int *dp){
	if( (n==0) || (n==1) ){
		dp[n] = n;
		return dp[n];
	}
	if(dp[n] != -1){
		return dp[n];
	}else{
		dp[n] = fibonacci(n-1,dp) + fibonacci(n-2,dp);
		return dp[n];
	}
}

int fibonacciDP(int n){
	int *dp = new int[n+1]; 
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2; i<=n; ++i){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];
}

int main(){
	int dp[100],n=45;
	for(int i=1; i<=n; ++i){
		dp[i] = -1;
	}
	cout<<fibonacciDP(n)<<"\n";
	return 0;
}
