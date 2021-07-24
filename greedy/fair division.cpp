#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int fairDivision(vector<int> &can, int n){
	int c1 = 0;
	for(int i=0; i<n; ++i){
		if(can[i] == 1){
			++c1;
		}
	}
	if(c1&1){
		return 0;
	}
	int c2 = n - c1;
	if(c1 == 0 && c2&1 == 1){
		return 0;
	}
	
	return 1;
}


int main(){
	int t;
	cin>>t;
	vector <int> ans;
	while(t--){
		int n;
		int w;
		vector<int> candies; 
		cin>>n;
		for(int i=0; i<n; ++i){
			cin>>w;
			candies.push_back(w);
		}
		ans.push_back(fairDivision(candies,n));	
	}
	for(auto io:ans){
		if(io==1){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
	return 0;
}
