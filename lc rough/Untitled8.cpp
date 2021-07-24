#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;	
	for(int tt=0; tt<t; ++tt){
		int n,d;
		pair<int,int> a[100];
		cin>>n;
		cin>>d;
		for(int i=0; i<n; ++i){
			cin>>a[i].first;
			a[i].second = 1;
		}
		sort(a,a+n);
		for(int i=0; i<n; ++i){
			if(a[i].first>d){
				a[i].second = 0;
				for(int j=0; j<i; ++j){
					int f=0;
					for(int k=1; k<i; ++k){
						if((a[j].first + a[k].first) < d){
							f=1;
							a[i].second = 1;
							a[i].first = a[j].first + a[k].first;
							break;	
						}
					}
					if(f==1){
						break;		
					}
				}
			}
		}
		int flag = 0;
		for(int i=0; i<n; ++i){
			if(a[i].second == 0){
				cout<<"NO\n";
				flag = 1;
				break;					
			}
		}
		if(flag == 0){
			cout<<"YES\n";	
		}
		
		
	}
	
	return 0;
}
