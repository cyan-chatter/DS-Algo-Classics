#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

float squareRoot(int n, int p=3){
	
	float ans = 0;
	
	//finding the integer part with binary search
	
	int s = 0, e = n;
	int mid,integer;
	
	while(s<=e){
		mid = (s+e)/2;
		if(mid*mid == n){
			return mid;
		}
		else if(mid*mid > n){
			e=mid-1;
		}
		else {
			s=mid+1;
			integer = mid;
		}
	}
	//we have integer part now
	ans = integer;
	
	//fractional part with linear search
	
	float inc = 0.1;
	for(int i=0; i<p; ++i){
		if(ans*ans == n){
			return ans;
		}
		while(ans*ans <= n){
			ans += inc;
		}
		ans -= inc;
		inc = inc/10;
	}
	
	return ans; 
}

int main(){
	cout<<squareRoot(49)<<"\n";
	cout<<squareRoot(80,3);
	return 0;
}

