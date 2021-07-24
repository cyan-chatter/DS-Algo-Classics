#include<iostream>
using namespace std;

void toHanoi(int n, char src, char dest, char helper){
	//base case
	if(n==0){
		return;
	}
	//rec case
	//I : move n-1 discs from src to helper
		toHanoi(n-1,src,helper,dest);
	
	//II : move n-th disc from src to destination
	//This step happens automatically by Recursion
	cout<<"\nMove Disc no. : "<<n<<" disc from "<<src<<" to "<<dest;
	
	//III : now the helper has become source for the rest of the n-1 discs so do the same
	toHanoi(n-1,helper,dest,src);
	//cout<<"\nMove Disc no. : "<<n<<" disc from "<<src<<" to "<<dest<<"\n";
}



int main(){
	int n;
	cin>>n;
	toHanoi(n,'S','D','H');
	return 0;
}
