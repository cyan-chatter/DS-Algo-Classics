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

void permute(string &s, int i, set<string> &store, ll k){
    if(i==k){
        store.insert(s.substr(0,k));
        return;
    }
    for(int j=i; j<s.length(); ++j){
        swap(s[i],s[j]);
        permute(s,i+1,store, k);
        swap(s[i],s[j]);
    }
}

int main(){
    fio();
    inp(k);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string a;
    getline(cin,a);
    set<string> s;
    permute(a,0,s, k);
    for(auto &x: s){
        cout<<x<<"\t";
    }
    return 0;
}

