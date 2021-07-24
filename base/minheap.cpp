#include<bits/stdc++.h>
using namespace std;

class minHeap{
	vector<int> v;
	
	void heapify(int index){
		int lchild = 2*index;
		int rchild = lchild + 1;
		int minIndex = index;
		
		if(lchild < v.size() && v[lchild] < v[index]){
			minIndex = lchild;
		}
		
		if(rchild < v.size() && v[rchild] < v[minIndex]){
			minIndex = rchild;
		}
		
		if(minIndex != index){
			swap(v[index], v[minIndex]);
			heapify(minIndex);
		}
		
	}
	
	public: 
		minHeap(){	
			v.push_back(-1);
		}
		
		void push(int data){
			v.push_back(data);
			int index = v.size() - 1;
			int parent = index/2;
			while(index>1 && v[index] < v[parent]){
				swap(v[index],v[parent]);
				index = parent;
				parent = parent/2;
			}
		}
		
		int getMin(){
			return v[1];
		}
		
		void pop(){
			int last = v.size() - 1;
			swap(v[1], v[last]);
			v.pop_back();
			heapify(1);
		}
		
		int isEmpty(){
			if(v.size() <= 1) return 1;
			else return 0;
		}
		
};

int main(){
	
	int a[] = {1,4,3,2,6,0,10,12};
	int n = sizeof(a)/sizeof(int);
	minHeap h;
	for(int i=0;i<n;++i){
		h.push(a[i]);
	}
	while(!h.isEmpty()){
		cout<<h.getMin()<<" ";
		h.pop();
	}	
}



