#include<iostream>
#include"hashtable.h"
using namespace std;

int main(){
	hashtable<int> h;
	h.insert("aam", 85);
	h.insert("seb", 60);
	h.insert("kela", 75);
	h.insert("sharifa", 90);
	h.insert("lichi", 80);
	int *taste_rating = h.search("sharifa");
	if(taste_rating == NULL){
		cout<<"NULL";
	}else{
		cout<<(*taste_rating);
	}
	h.print_hash_table();
	return 0;
}

