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
		
	void BFS(T src){
 	
		queue<T> q;
	 	map<T,bool> visited;
	 	
	 	q.push(src);
	 	visited[src] = true;
	 	
		while(!q.empty()){
			
	 		T node = q.front();
	 		cout<<node<<" ";
	 		q.pop();
	 		
	 		for(int neighbour : adjList[node]){
	 			if(!visited[neighbour]){
	 				q.push(neighbour);
	 				visited[neighbour] = true;
				 }
			 }
		}		
 	}
 	
 	void ssspBFS(T src){
 	
		queue<T> q;
	 	map<T,int> dist;
	 	map<T,T> parent;
	 	
	 	for(auto io:adjList){
	 		dist[io.first] = INT_MAX;	
		}
	 	
	 	q.push(src);
	 	dist[src] = 0;
	 	parent[src] = src;
	 	
		while(!q.empty()){
			
	 		T node = q.front();
	 		q.pop();
	 		
	 		for(int neighbour : adjList[node]){
	 			if(dist[neighbour] == INT_MAX){
	 				q.push(neighbour);
	 				dist[neighbour] = dist[node] + 1;
	 				parent[neighbour] = node;
				}
			}
		}
		for(auto io:adjList){
	 		cout<<" "<<dist[io.first]<<" ";
		}
 	}
 	
 	
 	int ssspShortestPathBFS(T src, T dest){
 	
		queue<T> q;
	 	map<T,int> dist;
	 	map<T,T> parent;
	 	
	 	for(auto io:adjList){
	 		dist[io.first] = INT_MAX;	
		}
	 	
	 	q.push(src);
	 	dist[src] = 0;
	 	parent[src] = src;
	 	
		while(!q.empty()){
			
	 		T node = q.front();
	 		q.pop();
	 		
	 		for(int neighbour : adjList[node]){
	 			if(dist[neighbour] == INT_MAX){
	 				q.push(neighbour);
	 				dist[neighbour] = dist[node] + 1;
	 				parent[neighbour] = node;
				}
			}
		}
		
		//to print the shortest path the bfs found:
		
		int temp = dest;
		while(temp!=src){
			cout<<temp<<" <- ";
			temp = parent[temp];
		}
		cout<<"START\n";
		
		return dist[dest]; 
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
	
 	g2.ssspBFS(0);
 	
	 return 0;
 }
 
 
 

