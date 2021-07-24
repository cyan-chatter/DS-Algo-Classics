#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int defkin(vector<int> &vx, vector<int> &vy, int w, int h){
	vx.push_back(0);
	vx.push_back(w);
	vy.push_back(0);
	vy.push_back(h);
	sort(vx.begin(),vx.end());	
	sort(vy.begin(),vy.end());
	vector<int> dx;
	int ans = 0;
	for(int i=0; i < vx.size()-1; ++i){
		dx.push_back(vx[i+1]-vx[i]-1);
	}
	for(int i=0; i < vy.size()-1; ++i){
		int undefendedArea = dx[i] * ( vy[i+1] - vy[i] - 1); 
		if(undefendedArea > ans){
			ans = undefendedArea;
		}
	}
	return ans;
}

int main(){
	
	vector< int > boardx;
	vector< int > boardy;
	int w,h,n,x,y;
	cin>>w;
	cin>>h;
	cin>>n;
	while(n--){
		cin>>x;
		cin>>y;
		boardx.push_back(x);
		boardy.push_back(y);
	}
	cout<<defkin(boardx,boardy,w,h);
	return 0;
}
