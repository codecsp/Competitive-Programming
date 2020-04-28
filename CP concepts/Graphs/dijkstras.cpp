#include <bits/stdc++.h>
using namespace std;

template <typename T>
class graph
{

	map<T, list<pair<T,double>>> adjList;

public:
	graph(){}

	void addEdge(T u, T v, double weight, bool bidir=true )
	{
		if(bidir=true)
		{
				adjList[u].push_back(make_pair(v,weight) );
				adjList[v].push_back(make_pair(u,weight) );
		}
			else
				adjList[u].push_back(make_pair(v,weight) );
	}

	void dijkstras(T src, T desss)
	{
		map<T, double> dist;

		for(auto j : adjList)
		{
			dist[j.first] = INT_MAX;
		}
		dist[src] = 0;

		set<pair<double,T>>st;
		st.insert(make_pair(0,src));

		while(!st.empty())
		{
			auto p = *(st.begin()) ;
			auto node = p.second   ;
			double node_dist = p.first ;
			st.erase(st.begin())    ;

			for(auto neighbor : adjList[node])
			{
				if(node_dist + neighbor.second < dist[neighbor.first])
				{

					auto fin = st.find(make_pair(dist[neighbor.first],neighbor.first));

					if(fin != st.end())
					{
						st.erase(fin);
					}

					dist[neighbor.first] = node_dist + neighbor.second ; 
					st.insert(make_pair(dist[neighbor.first], neighbor.first));

				}
			}



		}

		// for(auto i : dist)
		// {
		// 	cout<<"ditance of node "<<i.first<<" from 1 is "<<i.second<<endl;

		// }

		if(dist[desss] == INT_MAX)
			cout<<"-1"<<endl;
		else
			cout<<fixed<<setprecision(8)<<dist[desss]<<endl;
	}
	
};

int main()
{


	long long int t;
	cin>>t;
	while(t--)
	{
		double U,V;
        long long int n,m;
		cin>>n>>m>>U>>V;
		graph<long long int>g;
		for(long long int i=0;i<m;i++)
		{	
			double x,y;
			long long int u,v ;
			cin>>u>>v>>x>>y;
			double dd = ( x/(y*1.0 ));
			g.addEdge(u,v,dd);

		}

		g.dijkstras(U,V);

	}


    

}
