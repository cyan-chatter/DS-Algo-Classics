#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int palin(int number){
  vector<int> num;
  while(number!=0){
    num.push_back(number%10);
    number = number/10;
  }
  reverse(num.begin(), num.end()); 
  int n = num.size();
  if(n==1){
    return num[0];
  }
  int i=0,j=n-1;
  while(i<j){
    if(num[j] < num[i]){
      num[j] = num[i]; 
      ++i;
      --j;
    }
    else if(num[i] == num[j]){
      ++i;
      --j;
    }
    else if(num[j] > num[i]){
      int k = j-1;
      bool flag = false;
      num[j] = num[i];
      while(num[k] == 9){
        flag = true;
        num[k] = 0;
        --k; 
      }
      if(flag == true && k<i){
        ++num[n-1-k];
      }else{
        ++num[k];
      } 
      if(num[k] != num[n-k-1]){
        if(k<i && num[n-1-k] < num[k]) num[n-1-k] = num[k];
        else if(k>i && num[k] < num[n-1-k]) num[k] = num[n-1-k];
        else{
          i=0;
          j=n-1;
          continue;
        }
      }
      ++i;
      --j;
    }
  }
  for(int i=0; i<n; ++i){
    number += num[n-1-i] * pow(10,i);
  }
  return number;
}

int main() {
  int t,num;
  vector<int> ans;
  cin>>t;
  while(t--){
    cin>>num;
    ans.push_back(palin(num));
  }
  cout<<"\nOutPuts:\n";
  for(auto x:ans){
    cout<<x<<"\n";
  }
  return 0;
}
