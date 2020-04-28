#include<bits/stdc++.h>
using namespace std;
template<typename T>

class Graph
{

map<T,list<T> > adjList;
public:
Graph(){}
	
	void addEdge(T u, T v,bool bidir=true)
	{
	
		adjList[u].push_back(v);
		if(bidir)
		{
			adjList[v].push_back(u);
		}
	}

	void print()
	{
	//Iterate over the map
		for(auto i:adjList)
		{
			cout<<i.first<<"->";
			//i.second is LL
			for(T entry:i.second)
			{
				cout<<entry<<",";
			}

			cout<<endl;
		}
	}

	void bfs(T src)
	{
		queue<T> q;
		map<T,int>dist;
		map<T,T> parent;
		
		for(auto i:adjList)
		{
			dist[i.first] = INT_MAX;
		}

		q.push(src);

		
		dist[src] = 0;
		parent[src] = src;
		
		while(!q.empty())
		{
			T node = q.front();
			cout<<node<<" ";
			q.pop();
			
			for(int neigbour : adjList[node])
			{
				if(dist[neigbour]==INT_MAX)
				{
					q.push(neigbour);
					dist[neigbour] = dist[node] + 1;
					parent[neigbour] = node;
				}
			}
			
		}

		for(auto i:adjList)
		{
			T node = i.first;
			cout<<"Dist of "<<node<< "from "<<src<<" is "<<dist[node]<<endl;
		}
 	}
 	int snake(T src, T dest)
	{
		queue<T> q;
		map<T,int>dist;
		map<T,T> parent;
		
		for(auto i:adjList)
		{
			dist[i.first] = INT_MAX;
		}

		q.push(src);

		
		dist[src] = 0;
		parent[src] = src;
		
		while(!q.empty())
		{
			T node = q.front();
			//cout<<node<<" ";
			q.pop();
			
			for(int neigbour : adjList[node])
			{
				if(dist[neigbour]==INT_MAX)
				{
					q.push(neigbour);
					dist[neigbour] = dist[node] + 1;
					parent[neigbour] = node;
				}
			}
			
		}
		// print the path

		T tempor = dest;
		cout<<endl;
		while(tempor!=src)
		{
			cout<<parent[tempor]<<"--> ";
			tempor=parent[tempor];
		}
		cout<<src<<endl;
		/*for(auto i:adjList)
		{
			T node = i.first;
			cout<<"Dist of "<<node<< "from "<<src<<" is "<<dist[node]<<endl;
		}*/
 		cout<<"=";
 		return dist[dest];
 	}

 	void dfsHelper(T curr,map<T,bool>&visited)
 	{
 		visited[curr]=true;
 		cout<<curr<<" ";
 		for(T i : adjList[curr])
 		{
 			if(!visited[i])
 				dfsHelper(i,visited);

 		}
 	}

 	void dfs(T src)
 	{
 		std::map<T, bool> visited;
 		dfsHelper(src,visited);
 		cout<<endl;
 		int connected=1;

 		for(auto i : adjList)
 		{
 			if(visited[i.first]==false)
 			{
 				dfsHelper(i.first,visited);
 				cout<<endl;
 				connected++;
 			}

 		}

 		cout<<"\nThe number of connected components is : "<<connected<<endl;
 	}



 };


 int main()
 {
	
	Graph<string> g;
	
	g.addEdge("amritsar","jaipur");
	g.addEdge("amritsar","delhi");
	g.addEdge("delhi","jaipur");
	g.addEdge("mumbai","jaipur");
	g.addEdge("mumbai","bhopal");
	g.addEdge("delhi","bhopal");
	g.addEdge("mumbai","banglore");
	g.addEdge("agra","delhi");
	g.addEdge("anadaman","nicobar");

	g.dfs("amritsar");

 	return 0;	
 }
