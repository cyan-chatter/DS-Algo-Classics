#include<iostream>
#include<map>
#include<list>
#include<vector>
using namespace std;

template<typename T>
class Graph{
	
	public:
		map<T, list< pair<T,int> > > adjList;
		
		Graph(){}
		
		void addEdge(T u, T v, int w, bool bidir = true){
			adjList[u].push_back(make_pair(v,w));
			if(bidir){
				adjList[v].push_back(make_pair(u,w)); 
			}
		}
		
		int dfsNodeCounter(T node, map<T,bool> &visited, map<T,int> &count){
			visited[node] = true;
			int nodes=0;
			for(auto neighbour: adjList[node]){
				if(!visited[neighbour.first]){
					nodes += dfsNodeCounter(neighbour.first,visited,count);
				}
			}
			count[node] = 1 + nodes;
			return count[node];
		}
		
		int dfsCostCounter(T node, map<T,bool> &visited, map<T,int> &count, int n){
			visited[node] = true;
			int ans=0;
			for(auto neighbour: adjList[node]){
				if(!visited[neighbour.first]){
					ans += 2 * min(count[node],n-count[node]) * neighbour.second;
					ans += dfsCostCounter(neighbour.first,visited,count,n);
				}
			}
			return ans;
		}
		
		
		int holi(int src){
			map<T,int> count;
			map<T,bool> visited;
			int nodes = dfsNodeCounter(src,visited,count);
			for(auto it = visited.begin(); it != visited.end(); ++it){
				(*it).second = false;
			}
			int ans = dfsCostCounter(src,visited,count,src);
			return ans;
		}
};


int main(){
	int test_cases;
	cin>>test_cases;
	int fa[test_cases] = { };
	for(int tc=0; tc<test_cases; ++tc){
		int n;
		Graph<int> g;
		cin>>n;
		for(int i=0; i<(n-1); ++i){
			int x,y,z;
			cin>>x>>y>>z;
			g.addEdge(x,y,z);
		}
		fa[tc] = g.holi(n);
	}
	for(int tc=0; tc<test_cases; ++tc){
		cout<<"Case #"<<tc+1<<": "<<fa[tc]<<"\n";
	}
	return 0;
}
