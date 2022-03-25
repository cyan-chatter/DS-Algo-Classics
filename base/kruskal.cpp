//kruskal's algorithm for minimum spanning tree using union find operations along with path compression.
#include <bits/stdc++.h>
#define ll long long
#define inpv(x)       \
	for (auto &i : x) \
	cin >> i
#define outv(x)      \
	for (auto i : x) \
	cout << i << " "
#define all(x) x.begin(), x.end()
#define ld long double
#define ll long long
#define ull unsigned long long

using namespace std;
const ll N = 1e9;

int find(int v, unordered_map<int, int> &par)
{
	//p will store root of subset in which v is present
	int p = v;
	while (par[p] != p)
	{
		p = par[p];
	}

	// loop for path compression of all element from v to p
	while (v != p)
	{
		int temp = par[v];
		par[v] = p;
		v = temp;
	}
	//returns root of subset
	return p;
}

//unions does union of subsets in which v1 and v2 are present 
// and returns true if v1 and v2 are in different set and false if they are already in same set
bool unions(int v1,int v2,unordered_map<int,int>&par){
	int par1 = find(v1, par);
	int par2 = find(v2, par);
	if(par1==par2)return false;
	//for union of two subsets
	par[par1] = par2;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	// edges[i][0] = cost , edges[i][1]= v1 , edges[i][2] = v2
	vector<vector<int>> edges(m, vector<int>(3));
	for (int i = 0; i < m; i++)
	{
		cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
	}
	sort(all(edges));
	// map stores parent of every node in subset
	unordered_map<int, int> par;
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
	}
	ll mincost = 0;
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		if (count == n - 1)
			break;
		int v1 = edges[i][1];
		int v2 = edges[i][2];
		if(!unions(v1,v2,par))continue;
		
		mincost += edges[i][0];
		count++;
	}
	// for(auto k:par)cout<<k.first<<" "<<k.second<<endl;
	// 	cout<<endl;
	cout << mincost;

	return 0;
}