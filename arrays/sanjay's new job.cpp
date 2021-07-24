#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

bool myCompare(pair<string,int> p1, pair<string,int> p2){
	if(p1.second == p2.second){
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}

int main(){
	int x = 70;
	int n;
	cin>>n;
	pair<string,int> emp[100005];
	string name;
	int sal;
	for(int i=0; i<n; ++i){
		cin>>name;
		cin>>sal;
		emp[i].first = name;
		emp[i].second = sal;
	}
	
	sort(emp,emp+n,myCompare);
	
	for(int i=0; i<n; ++i){
		cout<<"\n";
		if(emp[i].second >= x){
			cout<<emp[i].first<<"\t";
			cout<<emp[i].second<<"\n";	
		}
	}
	return 0;
}
