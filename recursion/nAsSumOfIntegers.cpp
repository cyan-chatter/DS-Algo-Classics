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

set<vl> ans;
vl aux;

void f(ll i){
    if(i==0){
        ans.insert(aux);
        return;
    }
    for(ll j=1; j<=i; ++j){
        if(i-j >= 0){
            aux.pb(j);
            f(i-j);
            aux.pop_back();
        }
    }
}

int main() {
    fio();
    ll n;
    cin >> n;
    f(n);
    auto it = ans.begin();
    while(it!=ans.end()){
        auto jt = it; ++jt;
        auto &cache = (*it);
        while(jt!= ans.end()){
            auto &x = (*jt);
            bool fl = false;
            if(cache.size()==x.size()){
                fl = true;
                unordered_map<ll,ll> hm;
                iter(y,cache){
                    if(hm.count(y)) ++hm[y];
                    else hm[y] = 1;
                }
                iter(y,x){
                    if(hm.count(y) == 0 || hm[y] == 0){
                        fl = false;
                        break;
                    }
                    --hm[y];
                }
                if(fl){
                    iter(z,hm){
                        if(z.S != 0){
                            fl = false;
                            break;
                        }
                    }
                }
            }
            if(fl) jt = ans.erase(jt);
            ++jt;
        }
        ++it;
    }
    iter(x,ans){
        iter(io,x){
            cout<<io<<" ";
        }
        endline;
    }
    return 0;
}
