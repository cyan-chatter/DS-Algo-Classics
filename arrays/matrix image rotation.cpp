#include<iostream>
#include<algorithm>
using namespace std;

void rotateImage(int a[][100], int m, int n){
	
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			if(i>j){
				swap(a[i][j], a[j][i]);
			}
		}
	}
	
	for(int i=0; i<m; ++i){
		for(int j=0, k=n-1; j<k; ++j,--k){
			swap(a[i][j], a[i][k]);
		}
	}
	
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cout<<" "<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	
}

int main(){
	int a[][100] = {{1,3,3},{4,6,2},{8,9,1}};
	int m=3;
	int n=3;
	int key = 8;
	rotateImage(a,m,n);
	return 0;
}
