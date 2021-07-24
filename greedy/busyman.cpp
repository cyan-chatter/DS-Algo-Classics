#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
	return p1.second < p2.second;
}
//sort wrt finish times
int main(){
	
	int n;
	vector< pair<int,int> > v;
	cin>>n;
	while(n--){
		int s,e;
		cin>>s>>e;
		v.push_back(make_pair(s,e));
	}
	sort(v.begin(),v.end(),compare);
	
	int finishTime = v[0].second;
	int c = 1;
	for(int i=1; i<v.size(); ++i){
		if(v[i].first >= finishTime){
			++c; //count only the non overlapping ones
			finishTime = v[i].second;
		}
	}
	cout<<c<<"\n";
	return 0;
}
