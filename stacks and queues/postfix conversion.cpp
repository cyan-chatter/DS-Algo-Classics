#include <iostream>
#include <stack>
#include <string.h>
#include <ios>
#include <limits>
#include <vector>
#include <string>
using namespace std;


int priority(char ch){
  if(ch == '^'){
    return 1;
  }
  else if(ch == '/'){
    return 2;
  }
  else if(ch == '*'){
    return 3;
  }
  else if(ch == '-'){
    return 4;
  }
  else if(ch == '+'){
    return 5;
  }
  else if(ch == '('){
    return 6;
  }
  else return 0;
}

bool isOperator(char ch){
  if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' || ch == ')'){
    return true;
  }else{
    return false;
  }
}

void postfix(char* exp, string &ans){
  int len = strlen(exp);
  stack<char> st;
  for(int i=0; i<=len; ++i){
    if(isOperator(exp[i])){
      if(st.empty()){
        st.push(exp[i]);
        continue;
      }
      if(priority(exp[i]) < priority(st.top()) && priority(exp[i]) != 0){
        st.push(exp[i]);
      }
      else{
        if(priority(exp[i]) == 0){
          while(st.top() != '('){
            ans += st.top();
            st.pop();
          }
          if(st.top() == '('){
            st.pop();
          }
        }
        else if(exp[i] == '('){
          st.push(exp[i]);
        }
        else{
          while(!st.empty() && priority(st.top()) <= priority(exp[i])){
            if(st.top() != '(' && st.top() != ')')
              ans += st.top();
            st.pop();  
          }
            st.push(exp[i]);
        } 
      } 
    }else{
      ans += exp[i];
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
    postfix(exp,ans);
    answers.push_back(ans);
    ans.clear();
  }
  for(auto x : answers){
    cout<<x<<"\n";
  }
}
