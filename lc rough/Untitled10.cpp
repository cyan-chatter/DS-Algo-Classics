#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;

void answer(int n, int target){
	if(n==0 || (target==0 && n!= 0) || (n!=0 && target == 0)){
        cout<<"Not Possible";
        return;
    }
	long long int small = pow(10,n-1);
    long long int large = pow(10,n) - 1;
    set<long long int, greater<long long int> > array;
    for(long long int num1=small; num1<=large; ++num1){
    	long long int sum=0, num = num1;
		while(num>0){
    		long long int digit = num%10;
    		sum += digit;
    		num = num/10;
		}
		if(sum == target){
			array.insert(num1);	
		}
	}
	if(array.empty()){
		cout<<"Not Possible";
		return;
	}
	long long int l = (*(array.begin())), s = (*(array.rbegin()));
	cout<<l<<" "<<s;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,target;
    cin>>n;
    cin>>target;
    answer(n,target);
    return 0;
}

