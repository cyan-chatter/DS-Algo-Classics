#include <iostream>
#include <stack>
#include <string.h>
#include <ios>
#include <limits>
#include <vector>
#include <string>
using namespace std;


int prec(char ch){
  if(ch == '^'){
    return 3;
  }
  else if(ch == '/' || ch == '*'){
    return 2;
  }
  else if(ch == '+' || ch == '-'){
    return 1;
  }
  else return 4;
}

bool isOperand(char ch){
  if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
    return true;
  }else{
    return false;
  }
}

bool isOperator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^'){
    return true;
  }else{
    return false;
  }
}

void rpn(char* exp, string &ans){
  
  stack<char> st;
  for(int i=0; exp[i]!= '\0'; ++i){
    int ch = exp[i];
    if(isOperand(ch)){
      ans += ch;
    }else if(isOperator(ch)){
      while(!st.empty() && st.top()!='(' && prec(st.top()) >= prec(ch)){
        ans += st.top();
        st.pop();
      }
      st.push(ch);
    }else if(ch == '('){
      st.push(ch);
    }else if(ch == ')'){
      while(!st.empty() && st.top()!='('){
        ans += st.top();
        st.pop();
      }
      st.pop();
    }
  }
  while(!st.empty()){
    ans += st.top();
    st.pop();
  }
}

int main(){
  int t;
  char exp[401];
  cin>>t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  vector<string>answers;
  string ans;
  while(t--){
    cin.getline(exp,400,'\n');
    rpn(exp,ans);
    answers.push_back(ans);
    ans.clear();
  }
  for(auto x : answers){
    cout<<x<<"\n";
  }
}
