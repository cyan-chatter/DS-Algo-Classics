#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<char> &s1, stack<char> &s2, int n=-11){
	if(n==-11){
	while(!s1.empty()){
		s2.push(s1.top());
		s1.pop();	
	}	
	}else{
	while(n--){
		s2.push(s1.top());
		s1.pop();	
	}		
	}
}

stack<char> reverseStack1(stack<char> s){
	stack<char>sE; 
	transfer(s,sE);
	return sE;	
}

stack<char> reverseStack2(stack<char> s1){
	stack<char>s2;
	int n = s1.size();
	for(int i=0; i<n; i++){
		char x = s1.top();
		s1.pop();
		transfer(s1,s2,n-i-1);
		s1.push(x);
		transfer(s2,s1,n-i-1);
	}	
	return s1;
}

void insertAtBottom(stack<char> &s, int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	int y = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(y); 
}

void reverseStackRecursive(stack<char> &s){
	if(s.empty()){
		return;
	} 
	int x = s.top();
	s.pop();
	reverseStackRecursive(s);
	insertAtBottom(s,x);
}

int main() {

    stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    
		reverseStackRecursive(s);
			
    while(!s.empty()){
        cout<<s.top() <<endl;
        s.pop();
    }

    return 0;
}
