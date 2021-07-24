#include<iostream>
using namespace std;

bool staircaseSearch(int a[][100], int m, int n, int key){ //O(n)
	int i=0;
	int j=n-1;
	while(i<m && j>=0){
		if(a[i][j] == key){
			return true;
		}
		if(a[i][j]<key){
			++i;
		}
		else{
			--j;
		}
	}
	return false;
}

int main(){
	int a[][100] = {{1,3},{4,6},{8,9}};
	int m=3;
	int n=2;
	int key = 8;
	cout << staircaseSearch(a,m,n,key);
	return 0;
}
