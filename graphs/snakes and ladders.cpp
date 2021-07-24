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
		
 	int ssspBFSshortestDistance(T src, T dest){
 	
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
 	
 	Graph<int> g;
 	int board[50] = {0}; //jumps and downs array
 	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;
 	
 	for(int u=0; u<=36; ++u){
 		for(int dice=1; dice<=6; ++dice){
 			int v = u + dice + board[u+dice];
 				g.addEdge(u,v,false);
		}
	}
	 
	cout<<g.ssspBFSshortestDistance(0,36); 
 	
	return 0;
 }
 
 
 

