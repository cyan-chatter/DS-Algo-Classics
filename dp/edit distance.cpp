#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

int editDistance(string input, string output, int m, int n){
	
	if(m==0 && n==0){
		return 0;
	}
	
	int dp[101][101];
	for(int i=0; i<101; ++i){
		dp[0][i] = i;
	}
	for(int i=0; i<101; ++i){
		dp[i][0] = i;
	}
	
	for(int i=1; i<=m; ++i){
		for(int j=1; j<=n; ++j){
			if(input[i-1] != output[j-1]){
				int insertion = 1 + dp[i][j-1];
				int deletion = 1 + dp[i-1][j];
				int replacement = 1 + dp[i-1][j-1];
				dp[i][j] = min(insertion, min(deletion,replacement));
			}else{
				dp[i][j] = dp[i-1][j-1];
			}
		}
	}
	
	return dp[m][n];
	
}


int main(){
	string input = "cats";
	int m = 4;
	string output = "cast";
	int n = 4;
	cout<<editDistance(input,output,m,n);
	return 0;
}
