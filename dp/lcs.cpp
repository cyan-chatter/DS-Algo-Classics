#include<iostream>
#include<string.h>
using namespace std;

int lcs(char x[], char y[], int m, int n){
	
	if(m==0 || n==0){
		return 0;
	}
	if(m==1 && n==1){
		if(x[0]==y[0]){
			return 1;
		}else{
			return 0;
		}
	}
	if(x[m-1] == y[n-1]){
		return 1 + lcs(x,y,m-1,n-1);
	}else{
		return max(lcs(x,y,m,n-1), lcs(x,y,m-1,n));
	}
}

int lcsDP(char x[], char y[], int m, int n){
	
	if(m==0 || n==0){
		return 0;
	}
	if(m==1 && n==1){
		if(x[0]==y[0]){
			return 1;
		}else{
			return 0;
		}
	}
	
	int dp[101][101];
	for(int i=0; i<=m; ++i){
		for(int j=0; j<=n; ++j){
			dp[i][j] = 0;
		}	
	}
	for(int i=1; i<=m; ++i){
		for(int j=1; j<=n; ++j){
			if(x[i-1] == y[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}else{
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			}
		}	
	}
	return dp[m][n];
}

int main(){
	
	char x[] = "nematode";
	char y[] = "empty";
	
	int m = strlen(x);
	int n = strlen(y);
	
	cout << lcsDP(x,y,m,n);
	
	return 0;
}
