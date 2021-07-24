#include<iostream>
#include<queue>
using namespace std;

int main(){
	int n;
	int a[100000];
	int k;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>a[i];
	}
	cin>>k;
	deque<int> Q(k);
	int i=0;
	for(; i<k; ++i){
		while(!Q.empty() && a[i]>a[Q.back()]){
			Q.pop_back();
		}
		Q.push_back(i); 
	}
	for(; i<n; ++i){
		cout<<a[Q.front()]<<" ";
		while(!Q.empty() && (Q.front() <= i-k) ){
			Q.pop_front();
		}//contraction
		while(!Q.empty() && a[i] >= a[Q.back()]){
			Q.pop_back();
		}//logic
		Q.push_back(i);//expansion
	}
	cout<<a[Q.front()];
	return 0;
}
