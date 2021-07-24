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
#define endline             cout<<"\n";

#define iter(x, v) for(auto &x: v)
#define w(t) ll t; cin>>t; while(t--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define inp(n) ll n; cin>>n;
#define fillInput(v,n) ll t; for(ll i=0; i<n; ++i){ cin>>t; v.push_back(t); }


const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const ll inf = 1e18;
//const int mod = 998244353;
//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//cin.getline(s,101,'\n');


void fio() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

ll binarySearchIter(vl &v, ll &n, ll &key){
    ll s=0, e=n-1;
    while(s<=e){
        ll mid = (s+e)/2;
        if(key == v[mid]){
            return mid;
        }
        if(key < v[mid]){
            e = mid-1;
        }
        else s = mid+1;
    }
    return -1;
}

ll binarySearchRec(vl &v, ll s, ll e, ll &key){
    if(s>e){
        return -1;
    }
    ll mid = (s+e)/2;
    if(key == v[mid]){
        return mid;
    }
    if(key < v[mid]){
        return binarySearchRec(v,s,mid-1,key);
    }
    else return binarySearchRec(v,mid+1,e,key);
}

void firstOccurence(vl &v, ll s, ll e,ll &key, ll &hold){
    if(s>e){
        return;
    }
    ll mid = (s+e)/2;
    if(key == v[mid]){
        hold = mid;
    }
    if(key <= v[mid] && s!=e){
        firstOccurence(v,s,mid-1,key,hold);
    }
    else firstOccurence(v,mid+1,e,key,hold);
}

void lastOccurence(vl &v, ll s, ll e,ll &key, ll &hold){
    if(s>e){
        return;
    }
    ll mid = (s+e)/2;
    if(key == v[mid]){
        hold = mid;
    }
    if(key < v[mid]){
        lastOccurence(v,s,mid-1,key,hold);
    }
    else if(key >= v[mid] && s!=e) lastOccurence(v,mid+1,e,key,hold);
}

ll pivotIndexSortedRotatedArray(vl &v, ll &n){
    if(v[0] < v[n-1]){
        return 0;
    }
    ll s = 0;
    ll e = n-1;
    while(s<=e){
        ll mid = (s+e)/2;
        ll next = (mid+1)%N;
        ll prev = (mid+N-1)%N;
        if(v[mid] <= v[next] && v[mid] <= v[prev]){
            return mid;
        }
        if(v[mid] <= v[e]){
            e = mid - 1;
        }
        if(v[mid] >= v[s]){
            s = mid + 1;
        }
    }
    return -1;
    //invalid scenario
}

ll searchSortedRotated(vl &v, ll &n, ll &key){
    ll s = 0;
    ll e = n-1;
    while(s<=e){
        ll mid = (s+e)/2;
        if(v[mid] == key){
            return mid;
        }
        if(v[mid] <= v[e]){
            if(key > v[mid] && key <= v[e]){
                s = mid + 1;
            }
            else e = mid - 1;
        }
        if(v[mid] >= v[s]){
            if(key < v[mid] && key >= v[s]){
                e = mid - 1;
            }
            else s = mid + 1;
        }
    }
    return -1;
}

int main(){
    fio();
    inp(n)
    vl v;
    fillInput(v,n)
    inp(key)
//    cout<<binarySearchIter(v,n,key);
//    endline;
//    cout<<binarySearchRec(v,0,n-1,key);
//    endline;
//    ll holdFO = -1;
//    firstOccurence(v,0,n-1,key, holdFO);
//    cout<<holdFO;
//    endline;
//    ll holdLO = -1;
//    lastOccurence(v,0,n-1,key, holdLO);
//    cout<<holdLO;
//    endline;
//    ll count = holdLO - holdFO + 1;
//    if(holdLO == -1){
//        count = 0;
//    }
//    cout<<count;
//    endline;
    cout<<pivotIndexSortedRotatedArray(v,n);
    endline
    //index of pivot element of sorted rotated array = no. of rotations of the sorted array
    //pivot array od ascending sorted rotated array is the minimum element of the array
    cout<<searchSortedRotated(v,n,key);
    return 0;
}
