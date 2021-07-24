#include<bits/stdc++.h>
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
#define pb                  push_back
#define mp                  make_pair
#define F 					first
#define S					second
#define o.yes				cout<<"YES\n";
#define o.no				cout<<"NO\n";
#define eb                  emplace_back


const int N = 2e5 + 5;
const int mod = 1e9 + 7;
//const int mod = 998244353;
const ll infi = 1e18;

//cin.ignore(numeric_limits<streamsize>::max(), '\n');
//cin.getline(s,101,'\n');		

void fio() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
}

int main(){
	int t;
	while(t--){
		hcf = n1;
		temp = n2;
    
    while(hcf != temp)
    {
        if(hcf > temp)
            hcf -= temp;
        else
            temp -= hcf;
    }

    lcm = (n1 * n2) / hcf;
	}
		
	
	return 0;
}
