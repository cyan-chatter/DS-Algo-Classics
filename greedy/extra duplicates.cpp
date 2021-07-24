#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<ios>
#include<limits>
#define ll long long int
using namespace std;

void extra_duplicates(vector<ll> &v, ll &n){
	if(n<=1){
		cout<<"0";
		return;
	}
	sort(v.begin(),v.end());
	vector< pair<ll,ll> > dups;
	ll j=0;
	dups.push_back(make_pair(0,0));
	int c = 0;
	for(int i=0; i<n-1; ++i){
		if(v[i] == v[i+1]){
			++c;
			if(i == n-2){
				dups.push_back(make_pair(v[i],c));
				++j;
			}
		}else if(i>=1 && v[i-1] == v[i] && v[i] != v[i+1]){
			dups.push_back(make_pair(v[i],c));
			c = 0;
			++j;		 
		}
	}
	for(auto io : dups){
		cout<<io.first<<" "<<io.second<<"\n";
	}
}


int main(){
	ll n,ele;
	int t;
	cin>>t;
	while(t--){
	cin>>n;
	vector<ll>v;
	for(ll i=0; i<n; ++i){
		cin>>ele;
		v.push_back(ele);
	}
	extra_duplicates(v,n);	
	}
	return 0;
}
