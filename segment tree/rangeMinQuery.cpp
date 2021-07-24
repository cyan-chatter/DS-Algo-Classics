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
#define oyes				cout<<"YES\n"
#define ono				    cout<<"NO\n"
#define endline             cout<<"\n"

#define rep0(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n; i++)
#define iter(x, v) for(auto &x: v)
#define w(t) ll t; cin>>t; while(t--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fillInput(v,n) for(ll i=0; i<n; ++i){ ll t; cin>>t; v.push_back(t); }
#define inp(n) ll n; cin>>n;
#define inpv(v,n) vl v; for(ll i=0; i<n; ++i){ ll t; cin>>t; v.push_back(t); }
#define inpvp(v,n) vp v; for(ll i=0; i<n; ++i){ ll t1, t2; cin>>t1>>t2; v.push_back({t1,t2}); }
#define showArray(v,n) for(ll i=0; i<n; ++i) cout<<v[i]<<" "; cout<<"\n";
#define showMatrix(v,m,n) for(ll i=0; i<m; ++i){ for(ll j=0; j<n; ++j){ cout<<v[i][j]<<"\t"; } cout<<"\n";}
#define showMinheap(minheap) pq_mn mnhp = minheap; while(!mnhp.empty()){cout<<mnhp.top()<<" ";mnhp.pop();}
#define showMaxheap(maxheap) pq_mx mxhp = maxheap; while(!mxhp.empty()){cout<<mxhp.top()<<" ";mxhp.pop();}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const ll inf = 1e18;
const double pi = 3.141592653;
//const int mod = 998244353;

void fio() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//getline(cin,a);
//cin.getline(s,101,'\n');

void buildSegmentTree(vector<int> &input, int* &st, int i, int s, int e){
    if(s==e){
        st[i] = input[s];
        return;
    }
    int mid = (s+e)/2;
    buildSegmentTree(input,st,2*i,s,mid);
    buildSegmentTree(input,st,2*i+1,mid+1,e);
    st[i] = min(st[2*i],st[2*i+1]);
}

int query(int* &st, int s, int e, int qs, int qe, int i){
    if(qs == s && qe == e || qs <= s && qe >= e) return st[i];
    if(qs > e || qe < s) return INT_MAX;
    int mid = (s+e)/2;
    int left = query(st,s,mid,qs,qe,2*i);
    int right = query(st,mid+1,e,qs,qe,2*i+1);
    return min(left,right);
}

void updatePoint(int* &st, int s, int e, int q, int v, int i){
    if(q > e || q < s) return;
    if(s==e){
        st[i] = v;
        return;
    }
    int mid = (s+e)/2;
    updatePoint(st,s,mid,q,v,2*i);
    updatePoint(st,mid+1,e,q,v,2*i+1);
    st[i] = min(st[2*i],st[2*i+1]);
}

void updateRange(int* &st, int s, int e, int l, int r, int inc, int i){
    //order of cases - important O(n)
    if(l > e || r < s) return;
    if(s==e){
        st[i] += inc;
        return;
    }
    int mid = (s+e)/2;
    updateRange(st,s,mid,l,r,inc,2*i);
    updateRange(st,mid+1,e,l,r,inc,2*i+1);
    st[i] = min(st[2*i],st[2*i+1]);
}

int main() {
    fio();
    vector<int> input(10);
    iota(input.begin(),input.begin()+10,-2);
    int n = input.size();
    int* st = new int [4*n+1];
    buildSegmentTree(input,st,1,0,n-1);
//    for(ll i=1; i<(4*n+1); ++i){
//        if(st[i] >= -2 && st[i] <= 7) cout<<st[i]<<" ";
//        else cout<<"null ";
//    }
    showArray(input,n);
    inp(q);

    while(q--){
        inp(l);
        inp(r);
        cout<<query(st,0,n-1,l,r,1);
        endline;
    }
    updatePoint(st,0,n-1,5,-6,1);
    cout<<query(st,0,n-1,3,8,1)<<"\n";



    return 0;
}