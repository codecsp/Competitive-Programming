#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
	map<T, list<T>> gp;

public:
	Graph()
	{

	}
	void addEdge(T u, T v, bool bidir=true)
	{
			if(bidir==true)
			{
				gp[u].push_back(v);
				gp[v].push_back(u);
			}
			else
				gp[u].push_back(v);
	}

	void print()
	{
			for(auto row : gp)
			{
				cout<<row.first<<"-->";
				for(auto vertex : row.second)
						cout<<vertex<<",";

				cout<<"\n";
			}
	}

	void bfs(T src)
	{

		map<T,int> distance;
		map<T,T> parent;
		queue<T> q;
		for(auto i : gp)
		{
			distance[i.first]  = INT_MAX;
		}

		q.push(src);		
		distance[src]=0;
		parent[src]=src;

		while(!q.empty())
		{
			T node = q.front();
			//cout<<node<<" ";
			q.pop();
			for(auto neighbor : gp[node])
			{
				if(distance[neighbor]==INT_MAX)
				{
					q.push(neighbor);
					distance[neighbor]=distance[node]+1;
					parent[neighbor]=node;
				}

			}
		}

		for(auto i:gp)
		{
			T node= i.first;
			cout<<"distance of "<<node<<" from"<<src<<" is "
			<<distance[node]<<endl;
		}

	}



};

int main()
{
	Graph <int> g;	
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(0,4);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(3,5);
	g.addEdge(3,4);
	

	//g.print();

	//cout<<"---------------->\n";
	g.bfs(0);


}  
