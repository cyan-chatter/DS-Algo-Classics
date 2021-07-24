#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
	
	public:
		map<T, list<T> > adjList;
	
		Graph(){}
		
		void addEdge(T u, T v, bool bidir = true){
			adjList[u].push_back(v);
			if(bidir){
				adjList[v].push_back(u); 
			}
		}
		
		void printAdjList(){
			for(auto i: adjList){
				cout<<i.first<<"-> ";
				for(auto entry: i.second){
					cout<<entry<<"->";
				}
				cout<<"\n";
			}
		}
		
		void dfsHelper(T node, map<T,bool> &visited){
			visited[node] = true;
			cout<<node<<" ";
			for(T neighbour: adjList[node]){
				if(!visited[neighbour]){
					dfsHelper(neighbour,visited);
				}
			}
		}
		
 		void DFS(T src){
 			map<T,bool> visited;
			dfsHelper(src,visited); 			
		}
		
		void ccDFS(T src){
			map<T,bool> visited;
			int component = 1;
			dfsHelper(src,visited);
			cout<<"\n";
			for(auto io:adjList){
				T node = io.first;
				if(!visited[node]){
					dfsHelper(node,visited);
					++component;
				}
			}
			cout<<"\nconnected components: "<<component;
		}
 	
};

int main(){
 	
 	Graph<int> g2;
 	g2.addEdge(1,0);
 	g2.addEdge(1,2);
 	g2.addEdge(0,4);
	g2.addEdge(2,4);
	g2.addEdge(4,1);
	g2.addEdge(6,10);
	g2.addEdge(6,7);
	g2.addEdge(7,9);
 	g2.ccDFS(0);
 	
 	cout<<"\n";
 	
 	Graph<int> g;
 	g.addEdge(0,1);
 	g.addEdge(0,2);
 	g.addEdge(1,4);
 	g.addEdge(1,5);
 	g.addEdge(2,6);
 	g.addEdge(6,7);
 	g.addEdge(7,8);
 	g.addEdge(8,9);
	g.addEdge(8,10);
 	g.DFS(0);
	
	return 0;
 }
