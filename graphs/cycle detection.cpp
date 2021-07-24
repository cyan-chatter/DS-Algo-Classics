//O(v+e)
#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

template<typename T>
class Graph{
	
	public:
		map<T, list<T> > adjList;
	
		Graph(){
		}
		
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
		
	
 	bool cycleDetectionUndirectedBfs(T src){
 	
		queue<T> q;
	 	map<T,bool> visited;
	 	map<T,T> parent;
	 	
	 	q.push(src);
	 	visited[src] = true;
	 	parent[src] = src;
	 	
		while(!q.empty()){
			
	 		T node = q.front();
	 		q.pop();
	 		
	 		for(int neighbour : adjList[node]){
	 			if(!visited[neighbour]){
	 				q.push(neighbour);
	 				visited[neighbour] = true;
	 				parent[neighbour] = node;
				}else{
					if(parent[node] != neighbour){
						return true;
					}
				}
			}
		}
		return false;
 	}
 	
 	bool isCyclicHelper(T node, map<T,bool> visited, map<T,bool> instack){
 		visited[node] = true;
		instack[node] = true;
		
		for(T neighbour:adjList[node]){
			if((!visited[neighbour] && isCyclicHelper(neighbour,visited,instack)) || instack[neighbour]){
				return true;
			}	
		}
		instack[node] = false;
		return false; 	
	}
 	
 	bool cycleDetectionDirectedDfs(T src){
 		map<T,bool> visited;
 		map<T,bool> instack;
 		
 		for(auto io:adjList){
 			T node = io.first;
 			if(!visited[node]){
 				bool cyclePresent = isCyclicHelper(node,visited,instack);			
 				if(cyclePresent){
 					return true;
				}
			}
		}
		return false;
	}
	
	
 		bool isCyclicHelperUndirected(T node, map<T,bool> visited, T parent){
 			visited[node] = true;
			for(T neighbour:adjList[node]){
				if(!visited[neighbour]){
					bool cd = isCyclicHelperUndirected(neighbour,visited,node);
					if(cd){
						return true;	
					} 	
				}	
				else if(neighbour != parent){
					return true;
				}
			}
			
			return false; 	
 			
		}
 		
 		
 	bool cycleDetectionUndirectedDfs(T src){
 		map<T,bool> visited;
 		
 		for(auto io:adjList){
 			T node = io.first;
 			if(!visited[node]){
 				bool cyclePresent = isCyclicHelperUndirected(node,visited,node);			
 				if(cyclePresent){
 					return true;
				}
			}
		}
		return false;
	}
};

 
 int main(){
 	
 	Graph<int> g2;
 	g2.addEdge(1,2);
 	g2.addEdge(0,3);
 	g2.addEdge(2,25);
	g2.addEdge(4,25);
	g2.addEdge(4,1);
	g2.addEdge(3,2);
	g2.addEdge(25,1);
	
 	cout<<g2.cycleDetectionUndirectedDfs(0);
 	
	return 0;
 }
 
 
 

