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

void soln(){
    inp(n);
    vp v;
    vl ans;
    for(ll i=0; i<n; ++i){
        ll t1;
        ll t2;
        cin>>t1>>t2;
        v.pb({t1,t2});
    }
    ans.pb(1);
    for(ll i=1; i<n; ++i){
        ll as = ans.size();
        bool f = true;
        for(ll j=0; j<as; ++j){
            if((v[i].S <= v[j].S && v[i].S >= v[j].F) || (v[i].F >= v[j].F && v[i].F <= v[j].S)){
                if(ans[j] == 1) ans.pb(1);
                else ans.pb(2);
                f = false;
                break;
            }
        }
        if(f) ans.pb(2);
    }
    bool fl = true;
    for(auto &x : ans){
        if(x==2){
            fl = false;
            break;
        }
    }
    if(fl){
        cout<<"-1\n";
        return;
    }

    for(auto &x : ans){
        cout<<x<<" ";
    }
    endline;
}

int main(){
    fio();
    w(t){
        soln();
    }
    return 0;
}

