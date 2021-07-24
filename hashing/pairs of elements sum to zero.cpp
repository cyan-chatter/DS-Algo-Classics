#include<iostream>
#include<unordered_map>	 
#include<cstring>
#include<algorithm>
using namespace std;

pair<int,int>* pairsSumToZero(int *a,int n){
	pair<int,int>* ans = new pair<int,int> [n];
	unordered_map<int,pair<int,int>> store;
	for(int i=0; i<n; ++i){	
		auto it = store.find(abs(a[i]));
		if(it != store.end()){
			if(a[i]>=0){
				++((*it).second.first);
			}else{
				++((*it).second.second);
			}
		}else{
			if(a[i]>=0){
				store.insert(make_pair(abs(a[i]),make_pair(1,0)));			
			}else{
				store.insert(make_pair(abs(a[i]),make_pair(0,1)));			
			}
		} 	
	}
	int k=0,noPairs=0;
	for(auto it:store){
		if(it.second.second >= 1){
			noPairs = (it.second.first)*(it.second.second);
			while(noPairs--){
				ans[k].first = it.first;
				ans[k].second = -(it.first);
				++k;
			}
		}		
	}
	return ans;
}

int main(){
	int a[] = {2,5,5,-1,4,7,-4,-3,0,-2,-2,-5};
	int n = sizeof(a)/sizeof(int);
	pair<int,int>* ans = NULL;
	ans = pairsSumToZero(a,n);
	for(int i=0; i<n; ++i){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}
	return 0;
}

