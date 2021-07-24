#include<iostream>
using namespace std;

int minCoinsDP(int coins[], int amount, int n, int dp[]){
	if(amount==0){
		return 0;
	}
	if(dp[amount] == -1){
		int coinsNeeded = INT_MAX;
		for(int i=0; i<n; ++i){
			if(amount-coins[i] >= 0){
				int smol = minCoinsDP(coins,amount-coins[i],n,dp);
				if(smol!=INT_MAX){
					coinsNeeded = min(coinsNeeded,1+smol);		
				}
			}
		}
		dp[amount] = coinsNeeded;	
		return coinsNeeded;
	}else{
		return dp[amount];
	}
}

int minCoins(int coins[], int amount, int n){
	int *dp = new int[amount+1];
	for(int i=0; i<=amount; ++i){
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for(int ca=1; ca<=amount; ++ca){
		for(int i=0; i<n; ++i){
			if(ca-coins[i] >= 0 && dp[ ca-coins[i] ]!=INT_MAX){
				dp[ca] = min(dp[ca], 1+dp[ ca-coins[i] ] );
			}
		}
	}	
	return dp[amount];
}//O(nm)

int main(){
	int coins[] = {1,2,5,10,50};
	int amount = 179;
	int n = sizeof(coins)/sizeof(int);
	int dp[amount+1];
	for(int i=0; i<=amount; ++i){
		dp[i] = -1;
	}
	dp[0] = 0;
	cout<<minCoins(coins,amount,n);
	return 0;
}
