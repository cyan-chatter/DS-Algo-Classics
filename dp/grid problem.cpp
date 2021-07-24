#include<iostream>
using namespace std;

int minCost(int grid[3][3], int m, int n){
	if(m==0 && n==0){
		return grid[0][0];
	}
	int op1 = INT_MAX, op2 = INT_MAX;
	if(n-1 >= 0){
		op1 = minCost(grid,m,n-1);
	}
	if(m-1 >= 0){
		op2 = minCost(grid,m-1,n);
	}
	if(op1 != INT_MAX || op2 != INT_MAX){
		return grid[m][n] + min(op1,op2);	
	}
}

int minCostDP(int grid[3][3], int m, int n){
	if(m==0 && n==0){
		return grid[0][0];
	}
	int dp[m+1][n+1];
	for(int i=0; i<=m; ++i){
		for(int j=0; j<=n; ++j){
			dp[i][j] = INT_MAX;		
		}
	}
	int i=0, j=0;
	dp[0][0] = grid[0][0];
	for(int i=0; i<=m; ++i){
		for(int j=0; j<=n; ++j){
			int op1 = INT_MAX;
			int op2 = INT_MAX;
			if(j-1 >= 0){
				op1 = dp[i][j-1];
			}
			if(i-1 >= 0){
				op2 = dp[i-1][j];
			}	
			if(op1!=INT_MAX || op2!=INT_MAX){
				dp[i][j] = grid[i][j] + min(op1,op2);
			}
		}	
	}
	return dp[m][n];
}

int main(){
	int grid[3][3]={{1,2,3},{4,8,2},{1,5,3}};
	cout<<minCostDP(grid,2,2);
	return 0;
}
