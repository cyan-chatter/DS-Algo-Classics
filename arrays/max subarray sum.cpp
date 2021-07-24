#include<iostream>
#include<algorithm>
using namespace std;

int maxSubarraySumByCSum(int a[], int n){ // O(n^2)
	int csum[n]={};
	csum[0] = a[0];
	for(int i=0; i<n; ++i){
		csum[i] = a[i] + csum[i-1];
	}
	int sum=0, maxsum=0;
	for(int i=0; i<n; ++i){
		for(int j=i+1; j<n; ++j){
			sum = csum[j] - csum[i-1];
			if(maxsum<sum){
				maxsum = sum;
			}
		}	
	}
	return maxsum;
}

int maxSubarraySumByKdanes(int a[], int n){ // O(n)
	int cs = 0, ms = 0, rs = INT_MIN;
        for(int i=0; i < a.size(); ++i){
            cs += a[i];
            rs = max(rs,cs);
            if(cs < 0){
			    cs = 0;
		    }
            ms = max(cs,ms);    
        }
        //cout<<cs<<" "<<rs<<" "<<ms;
        if(cs == 0){
            return rs;
        }
        return ms;
}

int main(){
	int a[] = {-4,1,3,-2,-16,2,8,-9,4};
	int n = sizeof(a)/sizeof(int);
	cout<<maxSubarraySumByKdanes(a,n);
}
