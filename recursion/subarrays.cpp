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
typedef vector<pll> vp;
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
#define endline                cout<<"\n";

#define iter(x, v) for(auto &x: v)
#define w(t) ll t; cin>>t; while(t--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define inp(n) ll n; cin>>n;
#define fillInput(v,n) ll t; for(ll i=0; i<n; ++i){ cin>>t; v.push_back(t); }
#define inpv(v,n) vl v; ll t; for(ll i=0; i<n; ++i){ cin>>t; v.push_back(t); }

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


void subarrays(vl &v, ll i, set< vector<ll> > &store){

    if(i==v.size()){
        vl t;
        store.insert(t);
        return;
    }

    for(ll j=i; j<v.size(); ++j){
        vl temp;
        for(ll k=i; k<=j; ++k){
            temp.pb(v[k]);
        }
        store.insert(temp);
    }
    subarrays(v,i+1,store);
}

void subarraysV2(vl &v, ll i, ll j, set< vector<ll> > &store){

    if(i==v.size()){
        vl t;
        store.insert(t);
        return;
    }

    if(j==v.size()){
        subarraysV2(v,i+1,i+1,store);
        return;
    }

    vl temp;
    for(ll k=i; k<=j; ++k){
        temp.pb(v[k]);
    }
    store.insert(temp);

    subarraysV2(v,i,j+1,store);
}


int main(){
    fio();
    set< vector<ll> > store;
    inp(n);
    inpv(v,n);
    subarraysV2(v,0,0,store);
    for(auto &x: store){
        for(auto &y: x){
            cout<<y<<" ";
        }
        endline;
    }
    return 0;
}

