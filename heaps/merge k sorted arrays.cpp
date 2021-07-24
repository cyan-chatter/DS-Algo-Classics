#include<iostream>
#include<queue>
#include<vector>
using namespace std;

template <typename T> class myCompare{
	public:
		bool operator()(pair<int,int> a, pair<int,int> b){
			return (a.first > b.first);
		}
};

vector<int>* heap_MergeKSortedArrays(vector<vector<int> > &v, priority_queue<pair<int,int>,vector<pair<int,int> >,myCompare<pair<int,int> > > &pq, int &k){
		vector<int>* final = new vector<int>;
		pair<int,int> myPair;
		vector<int> iter;
		int id = 0;
		
		for(int i=0; i<k; ++i){
			iter.push_back(0);
		}
		
		for(int i=0; i<k; ++i){
			if(!v[i].empty()){
				myPair.first = v[i][0];
				myPair.second = i;
				pq.push(myPair);	
			}
		}
		
		while(pq.top().second != -1){
			id = pq.top().second;
			++iter[id];
			final->push_back(pq.top().first);
			pq.pop();
			if(iter[id] < v[id].size()){
				myPair.first = v[id][iter[id]]; 
				myPair.second = id;
			}else{
				myPair.first = INT_MAX;
				myPair.second = -1;
			}
			pq.push(myPair);		
		}
		
		return final;
}

void print_vector(vector<int>* v){
	cout<<"\n";
	for(int i=0; i < v->size(); ++i){
		cout<<(*v)[i]<<" ";
	}
	cout<<"\n";
}



int main(){
	int no,k;
	int cs = 0;
	pair<int,int> val;
	priority_queue<pair<int,int>,vector<pair<int,int> >,myCompare<pair<int,int> > > pq;	//minheap
	cin>>k;
	vector<vector<int> > v;
	vector<int> aux;
	for(int i=0; i<k; ++i){
		do{
			cin>>no;
			if(no != -1){
				aux.push_back(no);
			}	
		}while(no != -1);
		v.push_back(aux);
		aux.clear();
	}
	vector<int> *final = heap_MergeKSortedArrays(v,pq,k);
	print_vector(final);	
	return 0;
}

// 3 1 2 3 8 -1 5 9 10 -1 2 9 18 25 -1
