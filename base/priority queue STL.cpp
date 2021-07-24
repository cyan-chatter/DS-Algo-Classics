#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;


int main(){

//syntax: 
//default (max heap): 
//priority_queue<type> name;
//custom priority comparision: 
//priority_queue <type of priority queue, d.s. containing stored data, comparator determining priority>
	

	//priority_queue<int> pq; //by default - Max Heap
	priority_queue< int, vector<int>, greater<int> > pq;
	int a[10] = {5,6,17,18,9,11};
	
	for(int i=0; i<6; i++){
		pq.push(a[i]);
	}
	
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	
	return 0;
}
