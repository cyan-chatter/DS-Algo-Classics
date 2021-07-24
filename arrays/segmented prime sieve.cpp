#define lint long int
#define MAX 100000
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

const int N = 100000;

void sieve(vector<int> &primes){
  int p[N] = {0};
  for(int i=2; i<=N; ++i){
    if(p[i]==0){
      primes.push_back(i);
      for(int j=i; j<=N; j=j+i){
        p[j] = 1;
      }
    }
  }
}

void ranged_prime_generator(int m, int n, vector<int> & primes){
  if(m>=n){
    return;
  }
  bool segment[n-m+1];
  for(int i=0; i<n-m+1; ++i){
    segment[i] = false;
  }
  for(auto x : primes){
    if(x*x > n) break;
    int start = (m/x)*x;
    if(x>=m && x<=n){
      start = x*2;
    }
    for(int i=start; i<=n; i=i+x){
      segment[i-m] = true;
    }
  }
  for(int i=0; i<n-m+1; ++i){
    if(!segment[i] && (i+m)!=1){
      cout<<i+m<<"\n";
    }
  }
}

int main() {
  int t,m,n;
  vector<int> primes;
  sieve(primes);
  cin>>t;
  vector< pair<int,int> > input;
  for(int i=0; i<t; ++i){
    cin>>m>>n;
    input.push_back(make_pair(m,n));
  }
  for(int i=0; i<t; ++i){
    ranged_prime_generator(input[i].first,input[i].second,primes);
    cout<<"\n";
  }

}
