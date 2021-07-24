#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
	return p1.first < p2.first;
}
int main(){
	
	int n,q;
	vector< pair<int,int> > v;
	cin>>n;
	cin>>q;
	int s,e;
	for(int 0; i<q; ++i){
		cin>>s>>e;
		v.push_back(make_pair(s,e));
	}
	q -= 2;
	sort(v.begin(),v.end(),compare);
	
	pair<int,int> prev;
	prev.first = v[0].first;
	prev.second = v[0].second;
	int c = 0;
	int sum = 0;
	vector< pair<int,int> > inc;
	inc.push_back(prev);
	for(int i=1; i<v.size(); ++i){
		if(v[i].second <= prev.second){
			continue;
		}
		else if(v[i].second == prev.second && v[i].first >= prev.frist){
			inc.pop_back();
			inc.push_back(v[i]);
			prev = v[i];
		}
		else if(v[i].second > prev.second && v[i].first >= prev.second){
			inc.push_back(v[i]);
			prev = v[i];
		}
	}
	cout<<c<<"\n";
	return 0;
}
