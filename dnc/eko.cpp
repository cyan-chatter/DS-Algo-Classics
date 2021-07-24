#include<iostream>
#include<algorithm>
using namespace std;

int validator(int* a, int& n, int& m, int& H){
	int sum = 0;
	for(int i=0; i<n; ++i){
		if(a[i] > H) sum += a[i] - H;
	}
	if(sum >= m){
		return true;
	}
	return false;
}

int eko(int *a, int& n, int& m){
	sort(a,a+n);
	int s=0,ans=-1,e=a[n-1];
	while(s<=e){
		int mid = (s + e) / 2;
		if(validator(a,n,m,mid)){
			if(mid>ans){
				ans = mid;
			}
			s = mid + 1;
		}else{
			e = mid - 1;
		}
	}
	return ans;
}

int main(){
	int n,m;
	n=4;
	m=7;
	int h[]={20,15,10,17};
	cout<<eko(h,n,m);
	return 0;
}
