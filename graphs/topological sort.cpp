#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<string.h>
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
			for(auto io: adjList){
				cout<<io.first<<"-> ";
				for(auto entry: io.second){
					cout<<entry<<"->";
				}
				cout<<"\n";
			}
		}
		
		void dfsHelper(T node, map<T,bool> &visited, list<T> &ordering){
			visited[node] = true;
			for(T neighbour: adjList[node]){
				if(!visited[neighbour]){
					dfsHelper(neighbour,visited,ordering);
				}
			}
			ordering.push_front(node); //topological sort
		}
		
 		void dfsTopologicalSort(){
 			map<T,bool> visited;
 			list<T> ordering;
			for(auto io:adjList){
				T node = io.first;
				if(!visited[node]){
					dfsHelper(node,visited,ordering);
				}
			}
			for(T io:ordering){
				cout<<io<<" ";
			}		
		}
		
		void bfsTopologicalSort(){
			
			queue<T> q;
			map<T,bool> visited;
			map<T,int> indegree;
			for(auto io:adjList){
				T node = io.first;
				visited[node] = false;
				indegree[node] = 0;
			}
			for(auto io:adjList){
				T u = io.first;
				for(T v : adjList[u]){
					++indegree[v];
				}
			}
			for(auto io:adjList){
				T node = io.first;
				if(indegree[node] == 0){
					q.push(node);
				}
			}
			//algorithm:
			while(!q.empty()){
				T node = q.front();
				cout<<node<<" ";
				q.pop();
				for(auto neighbour:adjList[node]){
					--indegree[neighbour];
					if(indegree[neighbour] == 0){
						q.push(neighbour);
					}
				}	
			}
			
		}
		
};

int main(){
	
	Graph<string> g;
 	g.addEdge("e","pl",false);
 	g.addEdge("m","pl",false);
 	g.addEdge("pl","h",false);
 	g.addEdge("pl","p",false);
 	g.addEdge("pl","j",false);
 	g.addEdge("pl","js",false);
 	g.addEdge("p","wd",false);
 	g.addEdge("h","c",false);
 	g.addEdge("c","js",false);
 	g.addEdge("js","wd",false);
 	g.addEdge("j","wd",false);
 	g.addEdge("p","wd",false);
 	
 	g.bfsTopologicalSort();
 	
	return 0;
}
