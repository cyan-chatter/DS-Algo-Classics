#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<ios>
#include<limits>
#define ll long long int
using namespace std;

ll biased_standings(vector<ll> &v, ll &n){
	if(n<=1){
		return 0;
	}
	sort(v.begin(),v.end());
	ll badness = 0;
	for(int i=0; i<n; ++i){
		badness += abs(v[i] - i - 1);
	}
	return badness;	
}


int main(){
	ll n,ele;
	int t;
	string name;
	cin>>t;
	vector<ll>ans;
	while(t--){
	cin>>n;
	vector<ll>v;
	for(ll i=0; i<n; ++i){
		getline(cin,name);
		cin.ignore(numeric_limits<streamsize>::max(),' '); 
		cin>>ele;
		v.push_back(ele);
	}
	ans.push_back(biased_standings(v,n));	
	}
	for(auto io:ans){
		cout<<io<<"\n";
	}
	return 0;
}
