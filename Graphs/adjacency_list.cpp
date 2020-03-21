#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int v;
	list<int> *lt;

public:
	Graph(int v)
	{
		this->v = v ;
		lt = new list<int>[v] ;
	}
	void addEdge(int u,int v,bool bidir=true)
	{
		if(bidir==true)
		{
			lt[u].push_back(v);
			lt[v].push_back(u);
		}
		else
			lt[u].push_back(v);
	}

	void print()
	{
		for(int i=0;i<v;i++)
		{
			cout<<i<<"->";
			for(int vertex : lt[i])
			{
				cout<<vertex<<",";
			}
			cout<<endl;
		}


	}

};

int main()
{

	Graph g(5);

	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(4,3);
	g.addEdge(1,4);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(1,3);

	g.print();

}