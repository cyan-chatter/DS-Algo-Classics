#include<iostream>
#include<vector>

using namespace std;

 bool validMountainArray(vector<int>& a) {
        int len = a.size();
        if(len<3){
           return false; 
        }
        int i=0;    
        while(i<len && a[i+1]>a[i]){
                ++i;
        }
        if(i==0){
            return false;
        }
        if(i == len){
            return false;
        }
        if(i == (len-1)){
            if(a[i] > a[i-1]){
                return true;
            }
            else return false;
        }
        
        while(i<len && a[i+1]<a[i]){
            ++i;
        }
        if(i == len){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    int main(){
    	vector<int> a;
    	a.push_back(0);
    	a.push_back(3);
    	a.push_back(2);
    	a.push_back(1);
    	
    	cout<<validMountainArray(a);
    	return 0;
	}
