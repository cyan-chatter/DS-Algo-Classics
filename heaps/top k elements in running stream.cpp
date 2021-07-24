#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

void query_print(priority_queue<int,vector<int>,greater<int> > pq, int k){
	while(k--){
		cout<<pq.top()<<" ";
		pq.pop();	
	}
	cout<<"\n";
}

int main(){
	int no,k;
	int cs = 0;
	priority_queue<int,vector<int>,greater<int> > pq;
	//at query point, find the largest k elements -- min heap
	cin>>k;
	while(scanf("%d", &no)!=EOF){
		if(no == -1){
			query_print(pq,k);
		}else if(cs<k){
			pq.push(no);
			++cs;	
		}else{
			if(no>pq.top()){
				pq.pop();
				pq.push(no);
			}	
			++cs;
		}
	}
	return 0;
}

// 3 1 2 3 4 -1 5 9 10 -1 12 15 8 6 -1
