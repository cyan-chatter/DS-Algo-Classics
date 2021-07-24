#include<bits/stdc++.h>
using namespace std;

int dp[100] = {0};

int factorial(int n){
	if(n==1 || n==0){
		return 1;
	}
	return (n*factorial(n-1));
}

int catalanNumberFast(int n){
	if(n==0 || n==1){
		return 1;
	}
	int nfact = factorial(n);
	nfact = pow(nfact,2);
	nfact = factorial(2*n)/nfact;
	return (nfact/(n+1));
}

int catalanNumber(int n){
	if(n==0){
		return 1;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	else{
		int num=0;
		for(int i=1; i<=n; ++i){
			num += catalanNumber(i-1) * catalanNumber(n-i);
		}
		dp[n] = num;
		return num;
	}
}


int main(){
	int N = 5;
	cout<<catalanNumberFast(N);
	return 0;
}
