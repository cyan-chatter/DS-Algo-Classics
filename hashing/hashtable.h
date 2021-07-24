#include<cstring>
#include<string.h>
using namespace std;

template<typename T> class node{
	public:
		string key;	
		T value;
		node<T> *next;
		node(string key, T value){
			this->key = key;
			this->value = value;
		}
		~node(){
			if(next!=NULL){
				delete next;
			}
		}
};

template<typename T> class hashtable{
	int cs;
	int ts;
	node<T> **buckets;
	
	int hashFn(string key){
		int L = key.length();
		int ans = 0;
		int p = 1; 
		for(int i=0; i<L; ++i){
			ans += key[L-i-1] * p;
			p = p*37;
			p %= ts;
			ans %= ts;
		}
		return ans;
	}
	
	void rehash(){
		node<T>** oldBuckets = buckets;
		int oldTs = ts;
		ts *= 2;
		cs = 0;
		buckets = new node<T>* [ts];
		for(int i=0; i<ts; ++i){
			buckets[i] = NULL;
		}
		for(int i=0; i<oldTs; ++i){
			node<T>* temp = oldBuckets[i];
			while(temp!=NULL){
				insert(temp->key, temp->value);
				temp = temp->next;
			}
			delete oldBuckets[i];	//recursive node destructor call
		}
		delete [] oldBuckets;
	}
	
	public:
		hashtable(int ds = 7){
			cs = 0;
			ts = ds;
			buckets = new node<T>* [ts];
			for(int i=0; i<ts; ++i){
				buckets[i] = NULL;
			}
		}
		void insert(string key, T value){
			int i = hashFn(key);
			node<T>* n = new node<T>(key,value);
			n->next = buckets[i];
			buckets[i] = n; 	
			cs++;
			float load_factor = (float) cs/ts;
			if(load_factor > 0.7){
				rehash();	
			}
		}
		void print_hash_table(){
			cout<<"\n";
			for(int i=0; i<ts; ++i){
				node<T>* temp = buckets[i];
				cout<<i<<" :-> ";
				while(temp!=NULL){
					cout<<temp->key<<" : "<<temp->value<<"  ";
					temp=temp->next;
				}
				cout<<"\n";
			}
		}
		T* search(string key){
			int i = hashFn(key);
			node<T>* temp = buckets[i];
			while(temp!=NULL){
				if(temp->key == key){
					return &(temp->value);
				}
				temp = temp->next;
			}
			return NULL;
		}
		
		
};



