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

	void bfsTopologicalSort()
	{
		queue<T> q;
		map<T, bool>visited;
		std::map<T, int> indegree;

		for(auto i:adjList)
		{
			T node = i.first;
			indegree[node] = 0;
			visited[node] = false;			
		}
		// calaculating indegrees of all nodes

		for(auto i:adjList)
		{
			T node = i.first;
			for(T neighbor : adjList[node])
			{
				indegree[neighbor]++;
			} 
		}

		//for indegree 0
		for(auto i: adjList)
		{
			T node = i.first;
			
			if(indegree[node] == 0)
			{
				q.push(node);
			}
		}
//strat of the algorithm
		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			cout<<node<<" ";
			for(T element : adjList[node])
			{
				indegree[element]--;

				if(indegree[element] == 0)
					q.push(element);
			}
		}

	}
 };


 int main()
 {
	
	Graph<string> g;
	
	g.addEdge("english","program",false);
	g.addEdge("maths","program",false);
	g.addEdge("program","html",false);
	g.addEdge("program","python",false);
	g.addEdge("program","java",false);
	g.addEdge("program","js",false);
	g.addEdge("python","web",false);
	g.addEdge("html","css",false);
	g.addEdge("css","js",false);
	g.addEdge("js","web",false);
	g.addEdge("java","web",false);
	g.addEdge("python","web",false);

	g.bfsTopologicalSort();

 	return 0;
}

