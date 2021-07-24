#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
//Stack in C++ Standard Template Library

int main() {

    stack<string> s;

    s.push("Apple");
    s.push("Mango");
    s.push("Guava");

    while(!s.empty()){
        cout<<s.top() <<endl;
        s.pop();
    }



    return 0;
}
