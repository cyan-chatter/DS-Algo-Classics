#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	char y = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(y);
}

void revRec(stack<int> &s){
	if(s.empty()){
		return;
	}
	char x = s.top();
	s.pop();
	revRec(s);
	insertAtBottom(s,x);
}

void print(stack<int> s){
	while(!s.empty()){
        cout<<s.top() <<endl;
        s.pop();
    }
}

int main() {

    stack<int> s;
	return 0;
}
