#include<iostream>
#include<unordered_map>	 //works with separate chaining
//#include<map>  //works with red- black tree
#include<cstring>
using namespace std;

int main(){
	
	unordered_map<string,int> m;
	
	//Insertion
	m["mango"] = 100;
	m.insert(make_pair("apple", 120));
	
	if(m.count("apple") == 0){
		cout<<-1<<" ";
	}else{
		cout<<m["apple"]<<" ";
	}
	//m.erase("mango");
	auto f = m.find("mango");
	if(f!=m.end()){
		cout<<(f->second)<<" ";
	}else{
		cout<<-1<<" ";
	}
	
	return 0;
}

