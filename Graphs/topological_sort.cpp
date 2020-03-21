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

 	void dfsHelper(T curr,map<T, bool> &visited,list<T>&ordering)
 	{
 		//cout<<curr<<" ";
 		visited[curr] = true;

 		for(T neigbour : adjList[curr])
 		{
 			if(!visited[neigbour])
 				dfsHelper(neigbour,visited,ordering);
 		}

 		ordering.push_front(curr);
 	}

 	void dfs_topological_sort()
 	{
 		map<T, bool> visited;
 		list<T>ordering;
 		
 		for(auto i : adjList)
 		{
 			T node = i.first ;
 			if(!visited[node])
 			{
		 		dfsHelper(node,visited,ordering);
 			}
 		}

 		for(T element : ordering)
 			cout<<element<<" ";
 		cout<<endl;


 	}
 };


 int main()
 {
	
	Graph<int> g;
	
	g.addEdge(1,2,false);
	g.addEdge(1,3,false);
	g.addEdge(2,4,false);
	g.addEdge(3,4,false);

	g.dfs_topological_sort();

 	return 0;
}

