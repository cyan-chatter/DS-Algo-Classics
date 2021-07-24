#include<iostream>
#include<iomanip>
using namespace std;
int wineSale(int bottles[], int s, int e, int year){
	if(s>=e){
		return 0;
	}
	return max( (year*bottles[s] + wineSale(bottles,s+1,e,year+1)),  (year*bottles[e-1] + wineSale(bottles,s,e-1,year+1)) );
}


int wineSaleMemo(int bottles[], int s, int e, int year, int dp[101][101]){
	if(s>=e){
		return 0;
	}
	if(dp[s][e]!=-1){
		return dp[s][e];
	}else{
		dp[s][e] = max( (year*bottles[s] + wineSaleMemo(bottles,s+1,e,year+1,dp) ),  (year*bottles[e-1] + wineSaleMemo(bottles,s,e-1,year+1,dp) ) );	
		return dp[s][e];
	}
}

int wineSaleDP(int bottles[], int n){
	int s=0,e=n-1;
	int dp[n+1][n+1];
	for(int i=0; i<=n; ++i){
		for(int j=0; j<=n; ++j){
			dp[i][j] = -1;	
		}
	}
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i){
		dp[i][i] = n * bottles[i-1];
	}
	for(int len = 2, year = n-1; len<=n; ++len, --year){
		int s = 1;
		int iterations = n - len + 1;
		while(iterations--){
			int e = s + len - 1;
			dp[s][e] = max( (bottles[s-1]*year + dp[s+1][e]), (bottles[e-1]*year + dp[s][e-1]) );
			++s;
		}
	}
	return dp[1][n]; 
}

int main(){
	int bottles[] = {1,4,2,3};
	int n = sizeof(bottles)/sizeof(int);
	int dp[101][101];
	for(int i=0; i<=100; ++i){
		for(int j=0; j<=100; ++j){
			dp[i][j] = -1;	
		}
	}
	dp[0][0] = 0;
	cout<<wineSale(bottles,0,n,1)<<"\n";
	cout<<wineSaleMemo(bottles,0,n,1,dp)<<"\n";
	cout<<wineSaleDP(bottles,n);
	return 0;
}
