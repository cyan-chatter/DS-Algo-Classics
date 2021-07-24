#include<iostream>
using namespace std;

void print(int a[], int n){
	cout<<"\n";
	for(int i=0; i<n; ++i){
		cout<<" "<<a[i];
	}
	cout<<"\n";
}

void swap(int &a, int &b){
	int temp = a;
	a=b;
	b=temp;
}

wavesort(int a[], int n){
	for(int i=0; i<n; i+=2){
		if(i>0 && a[i-1]>a[i]){
			swap(a[i], a[i-1]);
		}
		if(i<n-1 && a[i+1]>a[i]){
			swap(a[i], a[i+1]);
		}
	} 
}

int main(){
	int a[] = {4,5,3,188,75,6,7,30,44,21,11};
	int n = sizeof(a)/sizeof(int);
	print(a,n);	
	wavesort(a,n);
	print(a,n);
	return 0;
}
