#include <iostream>
#include <vector>
#include <string>
using namespace std;

char str[27];

void stringGen(vector<int> &v, int i, int n, string & out){
    if(i==n){
        cout<<out<<"\n";
        return;
    }
    if(v[i]>0){
        out.push_back(str[v[i]]);
        stringGen(v,i+1,n,out);
        out.pop_back();
    }
    if(i+1 < n  && v[i]*10 + v[i+1] <= 26){
        out.push_back(str[v[i]*10 + v[i+1]]);
        stringGen(v,i+2,n,out);
        out.pop_back();
    }
}

int main(){
    int n,t;
    vector<int> v;
    string out;
    cin>>n;
    str[0] = '0';
    for(int i=1; i<27; ++i){
        str[i] = char('A' + i - 1);
    }

    for(int i=0; i<n; ++i){
        cin>>t;
        v.push_back(t);
    }

    stringGen(v,0,n,out);

    return 0;
}