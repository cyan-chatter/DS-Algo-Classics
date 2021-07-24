#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

void printMatrix(int a[][10], int m, int n){
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cout<<setw(5+j)<<a[i][j];
		}
		cout<<"\n";
	}
}


int main(){
	int str[][10] = {{4,5,3,6},{1,3,9,21},{19,14,16,7},{2,8,21,10},{16,2,40,29}};
	int m = 5;
	int n = 4;
	printMatrix(str,m,n);
	return 0;
}
