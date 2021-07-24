#include <iostream>
#include <vector>
#include <string>
using namespace std;

char keypad [11][6] = {
        " ", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"
};

void phoneKeypad(string &dial, int i, int n, string& out){
    if(i==n){
        cout<<out<<"\n";
        return;
    }
    for(int j=0; keypad[ int(dial[i] - '0')][j] != '\0'; ++j){
        out.push_back(keypad[ int(dial[i] - '0')][j]);
        phoneKeypad(dial,i+1,n,out);
        out.pop_back();
    }
}

int main(){
    cout<<"Hello Wanker\n";
    string dial,out;
    getline(cin,dial);
    phoneKeypad(dial, 0, dial.size(), out);
    return 0;
}

