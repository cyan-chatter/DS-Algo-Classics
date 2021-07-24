#include<iostream>
#include<algorithm>
using namespace std;

bool validateConfig(int *a, int& n, int c, int& key){
	if(n==1 || c==1){
		return true;
	}
	for(int i=1,cpos=0; i<n; ++i){
		if(a[i]-a[cpos] >= key){
			cpos=i;
			--c;
		}
		if(c==1){
			break;
		}
	}
	if(c==1){
		return true;
	}
	return false;
}

int aggresiveCows(int *a, int& n, int& c){
	sort(a,a+n);
	int s = 0, e = a[n-1] - a[0], ans=-1;
	while(s<=e){
		int mid = (s+e)/2;
		if(validateConfig(a,n,c,mid)){
			if(mid>ans){
				ans = mid;
			}
			s = mid+1;
		}else{
			e = mid-1;
		}
	}
	return ans; 
}

int main(){
	int s,c,arr[101]={1,2,4,8,9};
	s=5;
	c=3;
	cout<<aggresiveCows(arr,s,c);
	return 0;
}
