#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string.h>
#include<cstring>
using namespace std;

int coolstr(string str, int s, int e){
	if(s>=e){
		return 0;
	}
	int n = e-s;
	string left = str.substr(s,n/2);
	string right = str.substr(n/2,e+1);
	int la = coolstr(left,s,n/2);
	int ra = coolstr(right,n/2,e);
	char d = left[s];
	int flag = 1;
	for(int i=0; left[i]!='\0'; ++i){
		if(left[i] != d){
			flag = 0;
			break;
		}
	}
	if(flag == 1){
		int flag2 = 1;
		char e = right[n/2];
		if(e==d){
			flag2 = 0;
		}
		for(int i=0; right[i]!='\0'; ++i){
		if(right[i] != e){
			flag2 = 0;
			break;
		}
		}
		if(flag2 == 1){
			return la + ra +1;
		}
	}
	return la + ra;
}

int main() {
    int n;
    string str;
    cin>>n;
    getline(cin,str);
    cout<<coolstr(str,0,n);
    return 0;
}

