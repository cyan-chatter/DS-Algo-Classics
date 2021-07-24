#include<iostream>
#include<string>
using namespace std;

void generateBrackets(int i, int j, int n, string& out){
    if(i==n && j==n){
        cout<<out<<"\n";
        return;
    }
    if(i<n){
        out.push_back('(');
        generateBrackets(i+1,j,n,out);
        out.pop_back();
    }
    if(j<n && j<i){
        out.push_back(')');
        generateBrackets(i,j+1,n,out);
        out.pop_back();
    }
}

int main(){
    int n=4;
    string out;
    generateBrackets(0,0,n,out);
    return 0;
}
