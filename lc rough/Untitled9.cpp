#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int check(char *s, char *t){
	
	int c=1;
	int k=0;
			for(int i=0,j=0; t[j] != '\0';){
				if(s[i] == '\0'){
					int fc=1;
					
					for(;t[j] != '\0' && fc==1;){
						if(s[k] == '\0'){
							k=0;
							++c;
							continue;
						}
						if(t[j] == s[k]){
							++j;
							++k;
						}else if(t[j] != s[k]){
							cout<<"-1\n";
							return 0;							
						}
					}
				}
				if(s[i] !='\0' && s[i]!=t[j]){
					cout<<"-1\n";
					break;
				}
				if(s[i] !='\0' && s[i] == t[j]){
					++i;
					++j;
				}
			}
			return c;

	
}

int main(){
	int t;
	cin>>t;	
	for(int tt=0; tt<t; ++tt){
		char s[20], t[20];
		int k=0;
		cin.getline(s,20);
		cin.getline(t,20);		
		
		if(strlen(s) <= strlen(t)){	
			check(s,t);
			
		}else{
			check(t,s);
		}
	}
	
	return 0;
}



			
