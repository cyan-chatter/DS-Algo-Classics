#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <numeric>
#include <vector>
#include <set>
#include <map>
#include <math.h>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define pb push_back
#define F(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FR(x, v) for(auto &x: v)
#define w(t) ll t; cin>>t; while(t--)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int speed_up =  []{ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); return 0; }();


int main(){
    int m, s;
    cin >> m >> s;
    if(m != 1 && s == 0){
        cout << "-1 -1";
        return 0;
    }
    int s1 = s - 1;
    vector<int> n1(m);
    F(i, m, 0){
        if(s1 >= 9){
            s1-=9;
            n1[i]=9;
        } else {
            n1[i]=s1;
            s1=0;
        }
    }
    n1[0]+=1;
    s1 += (n1[0]>9)? 1:0;
    int s2 = s;
    vector<int> n2(m);
    F(i, m, 0){
        if(s2 >= 9){
            s2-=9;
            n2[i]=9;
        } else {
            n2[i]=s2;
            s2=0;
        }
    }
    if(!s1){
        FR(x, n1){
            cout << x;
        }
    } else{
        cout << "-1";
    }
    cout << " ";
    if(!s2){
        for_each(n2.rbegin(),n2.rend(),[](int el){cout << el;});
    } else{
        cout << "-1";
    }
}
