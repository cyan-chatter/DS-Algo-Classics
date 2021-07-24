#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<long int,long int> p1, pair<long int,long int> p2){
	return p1.second < p2.second;
}

int maximumCircles(vector< pair<long int,long int> > cord, int n){
	if(n==1){
		return 0;
	}
	int c = 0;
	int ft = cord[0].second;
	for(int i=1; i<n; ++i){
		if(cord[i].first >= ft){
			ft = cord[i].second;
		}else{
			++c;
		}
	}
	return c;
}

int main(){
	int n;
	long int c,r; 
	cin>>n;
	vector< pair<long int,long int> > cord;
	for(int i=0; i<n; ++i){
		cin>>c;
		cin>>r;
		cord.push_back(make_pair(c-r,c+r));
	}
	sort(cord.begin(),cord.end(),compare);
	cout<<maximumCircles(cord,n);
	return 0;
}
