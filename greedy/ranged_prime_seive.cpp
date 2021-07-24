#include <iostream>
#include<vector>
using namespace std;

void ranged_prime_sieve(int m, int n){
  if(m<=n){
    return;
  }
  vector<bool> prime;
  for(int i=0; i<=n; ++i){
    prime.push_back(true);
  }
  for(int i=2; i<n;++i){
    for(int cn=i*i; cn<=n; cn += i){
      prime[cn] = false;
    }
  }

  for(int i=m; i<=n; ++i){
    cout<<"yes\n";
    if(prime[i]){
      cout<<i<<"\n";
    }
  }

}

int main() {
  int t,m,n;
  cin>>t;
  vector< pair<int,int> > input;
  for(int i=0; i<t; ++i){
    cin>>m>>n;
    input.push_back(make_pair(m,n));
  }
  for(int i=0; i<t; ++i){
    ranged_prime_sieve(input[i].first,input[i].second);
    cout<<"\n";
  }

}
