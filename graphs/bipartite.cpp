#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	
	public:
	
	Graph(int v){
		V = v;
		l = new list<int>[V];
	}
	void addEdge(int u, int v){
		l[u].push_back(v);
		l[v].push_back(u);
	}
	
	bool isBipartiteBFS(int src){
		int *colors = new int [V];
		for(int i=0; i<V; ++i){
			colors[i] = -1;
		}
		queue<int> q;
		q.push(src);
		colors[src] = 0;
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(auto v: l[u]){
				if(colors[v] == -1){
					q.push(v);
					colors[v] = 1 - colors[u];
				}else if(colors[v] == colors[u]){
					return false;
				}
			}
		}
		return true;
	}
};

int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(2,0);
	g.addEdge(1,3);
	g.addEdge(2,3);
	g.addEdge(0,3);
	cout<<g.isBipartiteBFS(0);
	return 0;
}
