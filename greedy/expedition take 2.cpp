#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class functor{
	public:
	bool operator()(pair<int,int> p1, pair<int,int> p2){
		return p1.second < p2.second;
	}
};

bool myCompare( pair<int,int> p1, pair<int,int> p2 ){
	return p1.first < p2.first;
}

int expedition(vector< pair<int,int> > &fps, int &n, int &l, int &p){
	
    int ccd = p,c=0,cf,dist=0;
//	if(p<fps[0].first){
//		return -1;
//	}
//	cf = fps[0].second + p - fps[0].first;
//	for(int i=1; i<=n; ++i){
//		if(i==n){
//			if(cf<l){
//				return -1;
//			}
//		}else if(cf >= (fps[i].first - fps[i-1].first)){
//			cf -= (fps[i].first - fps[i-1].first);
//			cf += fps[i].second; 
//		}else{
//			return -1;
//		}		
//	}
	
	priority_queue< pair<int,int>, vector< pair<int,int> >, functor> cfps;
	while(dist<l){
		bool flag = false;
		for(int i=0; i<n; ++i){
			if(fps[i].first <= dist+ccd && dist < fps[i].first){
				cfps.push(fps[i]);
				flag = true;
			}
		}
		if(flag){
			pair<int,int> sfp = cfps.top();
			ccd = ccd - sfp.first + sfp.second;
			dist = sfp.first;
			++c;	
			cfps.pop();
			while(!cfps.empty()){
				cout<<(cfps.top()).second<<" ";
				cfps.pop();
			}
			cout<<"\n";  
		}else{
			dist += ccd; 
			if(dist<l){
				return -1;
			}
		}
	}
	
	return c;
}

int main(){
	int t;
	vector<int> ans;
	cin>>t;
	while(t--){
		int N,fp,mf,L,P;
		vector< pair<int,int> > fps;
		cin>>N;
		for(int i=0; i<N; ++i){
			cin>>fp;
			cin>>mf;
			fps.push_back(make_pair(fp,mf));
		}
		cin>>L;
		cin>>P;
		for(int i=0; i<N; ++i){
			fps[i].first = L - fps[i].first;
		}
		sort(fps.begin(),fps.end(),myCompare);
		ans.push_back(expedition(fps,N,L,P));
	}
	for(auto io:ans){
		cout<<io<<"\n";
	}
	return 0;
}
