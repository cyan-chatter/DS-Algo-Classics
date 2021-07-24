#include<iostream>
using namespace std;
int ways = 0, nrc = 0, nrc2 = 0;
void countBinaryStrings(int n,int tell){
    ++nrc;
    if(n==0){
        ++ways;
        return;
    }
    if(tell){
        countBinaryStrings(n-1,0);
        return;
    }
    countBinaryStrings(n-1,0);
    countBinaryStrings(n-1,1);
}

int count2(int n){
    ++nrc2;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 2;
    }
    if(n==2){
        return 3;
    }
    return count2(n-1) + count2(n-2);
}

int main(){
    
    int n=3;
    countBinaryStrings(n,0);
    cout<<count2(n)<<" "<<nrc2<<"\n";
    cout<<ways<<" "<<nrc;
    return 0;
}