#include<iostream>
#include<algorithm>
using namespace std;

bool validator(int *ranks, int n, int p, int alltime){
	for(int i=0; i<n; ++i){
		int time = 0, parata = 0;
		while(time<=alltime){
			time += ranks[i] * (parata+1);
			if(time<=alltime) ++parata;
		}
		p -= parata;
	}
	if(p<=0){
		return true;
	}
	return false;
}

int rotiPrata(int *ranks, int &n, int &p){
	sort(ranks,ranks+n);
	int s = 0, ans = INT_MAX;
	int e = (ranks[n-1] * n * (n+1))/2;
	while(s<=e){
		int mid = (s+e)/2;
		if(validator(ranks,n,p,mid)){
			if(mid<ans){
				ans = mid;
			}
			e = mid-1;
		}else{
			s = mid+1;
		}
	}
	return ans;
}


int main(){
	
	int p,l,ranks[51]={1,2,3,4};
	p=10;
	l=4;
	cout<<rotiPrata(ranks,l,p);
	return 0;
}
