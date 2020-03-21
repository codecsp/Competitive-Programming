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

	Set bfs(T src, std::map<ll, bool>&visited)
	{

		//map<T,bool> visited;
		queue<T>q;
		q.push(src);
		visited[src]=true;

		while(!q.empty())
		{
			T node = q.front();
			//cout<<node<<" ";
			q.pop();
			for(auto neighbor : gp[node])
			{
				if(!visited[neighbor])
				{
					q.push(neighbor);
					visited[neighbor] = true;
				}

			}


		}

	}



};

int main()
{

	ll n;
	cin>>n;

	ll edges = n-1;
	Graph <ll>g;

	while(edges--)
	{
		ll a,b;
		cin>>a>>b;
		g.addEdge(a,b);

	}
	ll q;
	cin>>q;
	while(q--)
	{
		ll s,d;
		cin>>s>>d;
		g.bfs(s,d);
	}


	g.bfs(0);


}  
