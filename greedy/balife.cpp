#include<iostream>
#include<climits>
using namespace std;

int balife(int *a, int n){
	
	if(n==0){
		return -1;
	}
	int cumsum[n+1];
	cumsum[0] = a[0];
	for(int i=1; i<n; ++i){
		cumsum[i] = cumsum[i-1] + a[i];
	}
	if(cumsum[n-1] % n != 0){
		return -1;
	}
	int final = cumsum[n-1] / n ;
	int ans = INT_MIN;
	for(int i=1; i<n; ++i){
		int left = final*i - cumsum[i-1]; 
		int right = final*(n-i) - cumsum[n-1] + cumsum[i-1];
		ans = max(ans, max(left,right) );
	}
	return ans;
}

int main(){
	int a[100001] = {};
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>a[i];
	}
	cout<<balife(a,n);
	return 0;
}

