#include<iostream>
#include<string.h>
using namespace std;

char* rotateString(char a[50], int &k){
	int len = strlen(a);
	for(int i=len; i>=0; --i){
		a[i+k] = a[i];
	}
	for(int j=0; j<k; ++j){
		a[j] = a[len+j];
	}
	a[len] = '\0';
	return a;
}

int main(){
	char a[50]="SayanChatterjee";
	int k=4;
	strcpy(a,rotateString(a,k));
	cout<<a;
	return 0;
}
