#include<iostream>
using namespace std;

int knapsack(int wts[], int prices[], int n, int w){
	if(n==0 || w==0){
		return 0;
	}
	int inc = 0, exc = 0;
	if(wts[n-1]<=w){
		inc = prices[n-1] + knapsack(wts,prices,n-1,w-wts[n-1]);	
	}
	exc = knapsack(wts,prices,n-1,w);
	return max(inc,exc);
}

int knapsackDP(int wts[], int prices[], int N, int W){
	int dp[101][101];
	for(int n=0; n<=N; ++n){
		for(int w=0; w<=W; ++w){
			if(n==0||w==0){
				dp[n][w] = 0;
			}else{
				int inc = 0, exc = 0;
				if(wts[n-1] <= w){
					inc = prices[n-1] + dp[n-1][ w-wts[n-1] ];
				}
				exc = dp[n-1][w];
				
				dp[n][w] = max(inc,exc);
			}
		}
	}
	return dp[N][W];
}


int main(){
	int wts[] = {2,2,3,1};
	int prices[] = {5,20,20,10};
	int N = 4;
	int W = 5;
	cout<<knapsackDP(wts,prices,N,W);
	return 0;
}
