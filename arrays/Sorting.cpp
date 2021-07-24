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

bubbleSort(int a[], int n){
	for(int i=1; i<n; ++i){
		for(int j=0; j<(n-i); ++j){
			if(a[j+1]<a[j]){
				swap(a[j+1], a[j]);
			}
		}
	}
}

selectionSort(int a[], int n){
	for(int i=0; i<n-1; ++i){
		int minIndex = i;
		for(int j=i+1; j<n; ++j){
			if(a[j]<a[minIndex]){
				minIndex = j;
			}
		}
		swap(a[i], a[minIndex]);	
	}
}

int main(){
	int a[] = {4,5,3,188,75,6,7,30,44,21,11};
	int n = sizeof(a)/sizeof(int);
	print(a,n);	
	//bubbleSort(a,n);
	selectionSort(a,n);	
	print(a,n);
	return 0;
}
