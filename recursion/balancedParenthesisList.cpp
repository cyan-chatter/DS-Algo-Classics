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

#define rep0(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n; i++)
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

vs ans;

void f(ll &n, ll i, string &aux, ll c1, ll c2) {
    if (i == 2*n) {
        ans.pb(aux);
        return;
    }
    if(c1<n){
        aux.push_back('(');
        f(n,i+1,aux,c1+1,c2);
        aux.pop_back();
    }
    if(c2<c1){
        aux.push_back(')');
        f(n,i+1,aux,c1,c2+1);
        aux.pop_back();
    }
}

int main() {
    fio();
    ll n;
    cin >> n;
    string aux;
    f(n,0,aux,0,0);
    iter(x,ans){
        cout<<x<<"\n";
    }

    return 0;
}
