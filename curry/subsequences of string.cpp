#include<iostream>
#include<stdlib.h>
using namespace std;

void subsequences(char *in, char *out, int i, int j){
	if(in[i]=='\0'){
		out[j] = '\0';
		puts(out);
		return;
	}
	//1. include current character
	out[j] = in[i];
	subsequences(in, out, i+1,j+1);
	
	//2. exclude current character
	subsequences(in, out, i+1,j);
}

int main(){
	char in[100];
	gets(in);
	char out[100]=" ";
	subsequences(in, out, 0, 0);
	return 0;
}
