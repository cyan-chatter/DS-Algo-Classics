#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ll, bool> plb;
typedef pair<ll, char> plc;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector< pll > vp;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef map<ll, ll> mll;
typedef map<char, ll> mcl;
typedef priority_queue<ll> pq_mx;
typedef priority_queue<ll, vl, greater<ll> > pq_mn;
#define mp                  make_pair
#define pb                  push_back
#define eb                  emplace_back
#define F 					first
#define S					second
#define oyes				cout<<"YES\n";
#define ono				    cout<<"NO\n";
#define endline             cout<<"\n";

#define rep0(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n; i++)
#define iter(x, v) for(auto &x: v)
#define w(t) ll t; cin>>t; while(t--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define inp(n) ll n; cin>>n;
#define fillInput(v,n) ll t; for(ll i=0; i<n; ++i){ cin>>t; v.push_back(t); }
#define inpvl(v,n) vl v; ll t; for(ll i=0; i<n; ++i){ cin>>t; v.push_back(t); }
#define inpvp(v,n) vp v; ll t1, t2; for(ll i=0; i<n; ++i){ cin>>t1>>t2; v.push_back({t1,t2}); }
#define showMatrix(v,m,n) for(ll i=0; i<m; ++i){ for(ll j=0; j<n; ++j){ cout<<v[i][j]<<"\t"; } cout<<"\n"; }


const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const ll inf = 1e18;
const double pi = 3.141592653;
//const int mod = 998244353;

//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//getline(cin,a);
//cin.getline(s,101,'\n');

void fio() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

void showMinHeap(pq_mn minheap){
    while(!minheap.empty()){
        cout<<minheap.top()<<" ";
        minheap.pop();
    }
}

void showMaxHeap(pq_mx minheap){
    while(!minheap.empty()){
        cout<<minheap.top()<<" ";
        minheap.pop();
    }
}

int main() {
    fio();
    ll n;
    pq_mn minheap;
    pq_mx maxheap;

    while(cin>>n){
       if(n==-1){
           if(ll(maxheap.size()) >= ll(minheap.size())){
                cout<<maxheap.top()<<"\n";
                maxheap.pop();
               bool imbalance = abs(ll(maxheap.size()) - ll(minheap.size())) > 1;
               if(imbalance){
                   maxheap.push(minheap.top());
                   minheap.pop();
               }
           }
           else{
               cout<<minheap.top()<<"\n";
               minheap.pop();
               bool imbalance = abs(ll(maxheap.size()) - ll(minheap.size())) > 1;
               if(imbalance){
                   minheap.push(maxheap.top());
                   maxheap.pop();
               }
           }
           continue;
       }
       if(maxheap.empty() && minheap.empty()){
           maxheap.push(n);
           continue;
       }
       if(minheap.empty() || n <= minheap.top()){
           maxheap.push(n);
           bool imbalance = abs(ll(maxheap.size()) - ll(minheap.size())) > 1;
           if(imbalance){
               minheap.push(maxheap.top());
               maxheap.pop();
           }
           continue;
       }
       if(n > minheap.top()){
           minheap.push(n);
           bool imbalance = abs(ll(maxheap.size()) - ll(minheap.size())) > 1;
           if(imbalance){
               maxheap.push(minheap.top());
               minheap.pop();
           }
       }
    }
    return 0;
}
