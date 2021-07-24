#include <iostream>
#include <string>
#include <set>
#include <ios>
#include <limits>
using namespace std;

set<string> st;

void swap(char &a, char &b){
    char t = a;
    a = b;
    b = t;
}

void stringPermutations(string in, int i, int &n, string &out, int &c){
    if(i==n){
        ++c;
        st.insert(out);
        return;
    }
    for(int k=i; k<n; ++k){
        out.push_back(in[k]);
        swap(in[k],in[i]);
        stringPermutations(in,i+1,n,out,c);
        swap(in[k],in[i]);
        out.pop_back();
    }

}

int main(){
    string s, out; int n,c=0;
    cin>>n;
    cin.ignore(numeric_limits<streamsize> :: max() , '\n');
    getline(cin,s);
    stringPermutations(s,0,n,out, c);
    cout<<"Number of Permutations: "<<c<<"\n";
    for(auto io: st){
        cout<<io<<"\n";
    }
    return 0;
}
