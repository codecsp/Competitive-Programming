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

 	// void dfs()
 	// {

 		
 	// }




 };


 int main()
 {
	/*
	Graph<int> g;
	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);
	//g.bfs(0);
*  */
 	int board[50]={0};
 	board[2]=13;
 	board[5]=5;
 	board[9]=18;
 	board[18]=11;
 	board[17]=-13;
 	board[20]=-14;
 	board[24]=-8;
 	board[25]=-10;
 	board[32]=-2;
 	board[34]=-22;

	Graph <int> sn;

	for(int u=0;u<=36;u++)
	{
		for(int i=1;i<=6;i++)
		{
			int v=u+i+board[u+i];
			sn.addEdge(u,v,false);
		}
	}

	cout<<"minimum distance to reach is : "<<sn.snake(1,36)<<endl;


}