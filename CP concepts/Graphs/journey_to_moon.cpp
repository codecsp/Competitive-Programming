#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{

	map<T, list<T>> adjList;

public:
	Graph(){}
	void addEdge(T u,T v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}


	void moonHelper(T element, int &count,map<T, bool>&visited)
	{
			visited[element] = true;
			count ++;
			for(T neighbor : adjList[element])
			{
				if(!visited[neighbor])
				{
					moonHelper(neighbor,count,visited);
				}
			}
	}

	void moon(int &total_count)
	{
		map<T, bool> visited;

		for(auto element : adjList)
		{
			//cout<<"here-- ";
			T node  = element.first;
			if(visited[node] == false)
			{
				int count = 0;
				moonHelper(node,count,visited) ;
				total_count -= count*(count-1)/2 ;
				//cout<<"total elements:  " <<count<<endl;
			}
		}

	}
};



int main()
{
	int n,p;
	cin>>n>>p;

	Graph<int>g;

	int total_count =  n*(n-1)/2;

	for(int i=0;i<p;i++)
	{
		int a,b;
		cin>>a>>b;
		g.addEdge(a,b);

	}
	g.moon(total_count);
	cout<<total_count;


}