#include<iostream>
using namespace std;

int op(int n, int signal){
	if(signal == 1){
		if( (n/3 >= 1) && (n%3 == 0) ){
			return n/3;	
		}
	}
	if(signal == 2){
		if( (n/2 >=1) && (n%2 == 0) ){
			return n/2;	
		}
	}
	if(signal == 3){
		if(n-1 >= 1){
			return n-1;	
		}
	}
	return -1;
}

int minSteps(int n, int dp[]){
	if(n==1){
		return 0;
	}
	if(dp[n]!=-1){
		return dp[n];
	}else{
		int ms = INT_MAX;
		for(int i=1; i<=3; ++i){
			int mn = op(n,i);
			int mm = INT_MAX;
			if(mn!=-1){
				mm = minSteps(mn,dp);	
			}
			if(mm!=INT_MAX){
				ms = min(ms,1+mm);	
			}
		}
		if(ms!=INT_MAX){
			dp[n] = ms;	
		}
		return ms;	
	}
}

int minStepsDP(int n){
	if(n==1){
		return 0;
	}
	int dp[101];
	for(int i=0; i<=n; ++i){
		dp[i] = INT_MAX;
	}
	dp[1] = 0;
	for(int i=2; i<=n; ++i){
		int o1 = INT_MAX, o2 = INT_MAX, o3 = INT_MAX;
		if(i%3 == 0 && i/3 >= 1){
			o1 = 1 + dp[i/3];
		}
		if(i%2 == 0 && i/2 >= 1){
			o2 = 1 + dp[i/2];
		}
		if(i-1 >= 1){
			o3 = 1 + dp[i-1];
		}
		dp[i] = min(o1, min(o2,o3));
	}
	return dp[n];
}

int main(){
	int dp[101],n=98;
	for(int i=0; i<=n; ++i){
		dp[i] = -1;
	}
	cout<<minStepsDP(n);
	return 0;
}
