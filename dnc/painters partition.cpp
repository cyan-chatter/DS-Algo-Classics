#include<iostream>
using namespace std;

int validator(int *a, int& n, int k, int& t, int alltime){
	int time = 0;
	for(int i=0; i<n;){
		if( (time + a[i]*t ) <= alltime ){
			time += a[i] * t;	
			++i;
		}else if(a[i]*t > alltime){
			return false;	
		}
		else{
			--k;
			time = 0;
		}
	}
	if(k>0){
		return true;
	}
	return false;
}

int paintersPartition(int *a, int& n, int& k, int& t){
	int s=0,ans=INT_MAX,e=0;
	for(int i=0; i<n; ++i){
		e += t * a[i];
	}
	while(s<=e){
		int mid = (s + e) / 2;
		if(validator(a,n,k,t,mid)){
			if(mid<ans){
				ans = mid;
			}
			e = mid - 1;
		}else{
			s = mid + 1;
		}
	}
	return ans;
}


int main(){
	int k,n,t;
	k=2;
	n=4;
	t=1;
	int A[]={10,20,30,40};
	cout<<paintersPartition(A,n,k,t);
	return 0;
}
