#include<iostream>
#include<map>
#include<list>
using namespace std;

template<typename T>
class Graph{
	map<T, list<T> > adjList;
	// hash maps are dynamic (no need to store the size)
	//maps store in sorted order automatically
	public:
		Graph(){}
		
		void addEdge(T u, T v, bool bidir = true){
			adjList[u].push_back(v);
			if(bidir){
				adjList[v].push_back(u); 
			}
		}
		
		void printAdjList(){
			//iterate the map (dynamic)
			//auto- automatically detects data type
			for(auto io: adjList){
				cout<<io.first<<":  ";
				for(auto entry: io.second){
					cout<<entry<<", ";
				}
				cout<<"\n";
			}
		}
};

int main(){
	Graph<string> g;
	g.addEdge("Putin", "Trump", false);
	g.addEdge("Putin", "Modi", false);
	g.addEdge("Yogi", "Modi");
	g.printAdjList();
	
	Graph<int> g2;
	g2.addEdge(1,2);
	g2.addEdge(10,25);
	g2.addEdge(51,20);
	g2.addEdge(7,20);
	g2.addEdge(20,8);
	g2.addEdge(8,18);
	cout<<"\n";
	g2.printAdjList();
}
