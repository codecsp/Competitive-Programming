#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{

	map<T, list<T>> mp;

  public:
	Graph()
	{

	}
	void addEdge(T u, T v, bool bidir=true)
	{
			if(bidir==true)
			{
				mp[u].push_back(v);
				mp[v].push_back(u);
			}
			else
			{
				mp[u].push_back(v);
			}
	}
	void print()
	{

		for(auto row:mp)
		{
			cout<<row.first<<"-->";

			for(auto vertex:row.second)
			{

				cout<<vertex<<",";
			}
			cout<<endl;
		}
	}
	
	
};

int main()
{

	Graph <string> g;
	g.addEdge("putin","trump",false);
	g.addEdge("putin","modi",false);
	g.addEdge("putin","pope" ,false);
	g.addEdge("modi","yogi",true);
	g.addEdge("modi","trump",true);
	g.addEdge("yogi","prabhu",false);
	g.addEdge("prabhu","modi",false);
	

	g.print();

cout<<"\n---------------------------------\n";
	Graph <int>g1; //for integers

	g1.addEdge(0,1);
	g1.addEdge(0,4);
	g1.addEdge(4,3);
	g1.addEdge(1,4);
	g1.addEdge(1,2);
	g1.addEdge(2,3);
	g1.addEdge(1,3);
	g1.print();
	
	
}

