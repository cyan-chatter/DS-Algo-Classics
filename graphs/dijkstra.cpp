#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<set>
#include<queue>
using namespace std;

template<typename T>
class Graph{
	
	public:
		map<T, list< pair<T,int> > > adjList;
	
		Graph(){}
		
		void addEdge(T u, T v, int weight, bool bidir = true){
			adjList[u].push_back(make_pair(v,weight));
			if(bidir){
				adjList[v].push_back(make_pair(u,weight)); 
			}
		}
		
		void dijkstraSSSP(T src, T destination){
			 unordered_map<T,int> dist;
			 unordered_map<T,T> parent;
			 for(auto io:adjList){
			 	dist[io.first] = INT_MAX;
			 }
			 set< pair<int,T> > s;
			 dist[src] = 0;
			 s.insert(make_pair(0,src));
			 while(!s.empty()){
			 	auto p = *(s.begin());
			 	T node = p.second;
			 	int nodeDist = p.first;
			 	s.erase(s.begin());
			 	for(auto neighbour:adjList[node]){
			 		if( (nodeDist + neighbour.second) < dist[neighbour.first] ){
			 			T dest = neighbour.first;
						auto f = s.find(make_pair(dist[dest], dest));
						if(f!=s.end()){
							s.erase(f);
						}
						parent[dest] = node;
						dist[dest] = nodeDist + neighbour.second;
						s.insert(make_pair(dist[dest],dest)); 		
					}	
				}
			 }
			 for(auto io:dist){
			 	cout<<"Node: "<<io.first<<" Distance: "<<io.second<<"\n";	
			 }
			 cout<<"Shortest Path: ";
			 T temp = destination;
			 while(temp!=src){
			 	cout<<temp<<"<-";
			 	temp = parent[temp];
			 }
			 cout<<src; 
		}
};

 
 
 int main(){
 	
 	Graph<int> g2;
 	g2.addEdge(1,2,1);
 	g2.addEdge(1,3,4);
 	g2.addEdge(2,3,1);
	g2.addEdge(3,4,2);
	g2.addEdge(1,4,7);
 	g2.dijkstraSSSP(1,4);	
	return 0;
 }
 
 

