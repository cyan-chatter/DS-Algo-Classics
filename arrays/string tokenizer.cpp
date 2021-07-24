#include<iostream>
#include<cstring>
using namespace std;


int main(){
	
	char str[] = "Yo, boku no naamaewa Cyan desu";
	char* ptr;
	ptr = strtok(str, " ,");
	while(ptr!=NULL){
		cout<<ptr<<"\n";
		ptr=strtok(NULL," ,");
	}
	return 0;
}
