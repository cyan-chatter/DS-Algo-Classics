#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int lb,ub;
    cin>>lb;
    cin>>ub;
    for(int num=lb; num<=ub; ++num){
    	int n = num;
    	int flag = 1;
    	while(n>0){
    		int digit = n%10;
    		if(digit == 0){
    			flag = 0;
    			break;
			}
    		if(num%digit != 0){
    			flag = 0;
    			break;
			}
			n = n/10;
		}
		if(flag == 1){
			cout<<num<<" ";
		}
	}
    return 0;
}

