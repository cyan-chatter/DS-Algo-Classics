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

void mergeKSortedArrays(vvl &arrays, ll &k, vl &ans){
    pq_mn mh;
    ll n = INT_MIN;
    for(int i=0; i<k; ++i){
        ll size = arrays[i].size();
        n = max(n,size);
        mh.push(arrays[i][0]);
    }
    for(int i=1; i<n; ++i){
        for(int j=0; j<k; ++j){
            if(i>=arrays[j].size()) continue;
            if(arrays[j][i] <= mh.top()){
                ans.pb(arrays[j][i]);
            }
            else{
                ans.pb(mh.top());
                mh.pop();
                mh.push(arrays[j][i]);
            }
        }
    }
    while(!mh.empty()){
        ans.pb(mh.top());
        mh.pop();
    }
}

int main() {
    fio();
    inp(k);
    vvl arrays;
    for(int i=0; i<k; ++i){
        inp(n);
        inpvl(temp,n);
        arrays.pb(temp);
    }
    vl ans;
    mergeKSortedArrays(arrays,k, ans);
    for(ll i=0; i<k; ++i){ for(ll j=0; j<arrays[i].size(); ++j){ cout<<arrays[i][j]<<"\t"; } cout<<"\n"; }
    iter(x,ans){
        cout<<x<<" ";
    }
    return 0;
}
