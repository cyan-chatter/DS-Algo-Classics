#include<iostream>
#include<unordered_map>
using namespace std;

#define hashmap unordered_map<char,node*>

class node{
	public:
		char data;
		hashmap h;
		bool isTerminal;
		
		node(char d){
			data = d;
			isTerminal = false;
		}
};

class trie{
	node* root;
public:
	trie(){
		root = new node('\0');
	}		
	void addWord(char *word){
		node* temp = root;
		for(int i=0; word[i] != '\0'; ++i){
			char ch = word[i];
			if(temp->h.count(ch)==0){
				node*child = new node(ch);
				temp->h[ch] = child;
				temp = child;
			}
			else{
				temp = temp->h[ch];
			}
		}
		temp->isTerminal = true;
	}
	//lookup
	bool search(char* word){
		node* temp = root;
		for(int i=0; word[i]!='\0'; ++i){
			char ch = word[i];
			if(temp->h.count(ch)){
				temp = temp->h[ch];
			}else{
				return false;
			}
		}
		return temp->isTerminal;	//so that return true only when a valid word is searched 
	}	
};

//searching - O(n)


int main(){
	
	char fruits[][40] = {"aapel", "kaula", "aam", "lichi", "aata", "aanaraus", "paati lebu", "komla lebu"};
	trie t;
	for(int i=0; i<8; ++i){
		t.addWord(fruits[i]);
	}
	char searched[40];
	cin.getline(searched,40);
	if(t.search(searched)){
		cout<<searched<<" found\n";
	}else{
		cout<<"Not Found!\n";
	}
	return 0;
}
