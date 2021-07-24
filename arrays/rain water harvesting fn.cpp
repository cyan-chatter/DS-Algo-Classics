#include<iostream>
#include<algorithm>
using namespace std;

int rainWaterHarvesting(int a[], int n){

	int lml[n]={}; 
	int rml[n]={};
	lml[0] = a[0];
	rml[0] = 0;
	lml[n-1] = 0;
	rml[n-1] = a[n-1];
	
	for(int i=1,j=n-2; i<(n-1); ++i,--j){
		
		if(a[i]>=lml[i-1]){
			lml[i] = a[i];
		}
		else{
			lml[i] = lml[i-1];
		}
		
		if(a[j]>=rml[j+1]){
			rml[j] = a[j];
		}
		else{
			rml[j] = rml[j+1];
		}
		
	}
	
	int w;
	for(int i=1; i<(n-1); ++i){
		w += min(lml[i], rml[i]) - a[i];
	}
	
	return w;

}

int main(){
	int a[] = {0,2,1,3,0,1,2,1,2,1};
	int n = sizeof(a)/sizeof(int);
	cout<<rainWaterHarvesting(a,n);
	return 0;
}
