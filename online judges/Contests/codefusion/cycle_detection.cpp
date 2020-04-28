
#include <bits/stdc++.h> 
using namespace std; 
const int N = 1005; 
typedef long long int ll;


void dfs_cycle(ll u, ll p, ll color[], ll mark[], ll par[], ll& cyclenumber, vector<ll> &cycles, vector<ll> &graph) 
{ 

	if (color[u] == 2) { 
		return; 
	} 

	if (color[u] == 1) 
	{ 

		cyclenumber++; 
		ll cur = p; 
		mark[cur] = cyclenumber; 

		while (cur != u) 
		{ 
			cur = par[cur]; 
			mark[cur] = cyclenumber; 
		} 
		return; 
	} 
	par[u] = p; 

	color[u] = 1; 

	for (ll v : graph[u]) 
	{ 

		if (v == par[u]) 
		{ 
			continue; 
		} 
		
		dfs_cycle(v, u, color, mark, par, cyclenumber, vector<ll> &cycles, vector<ll> &graph); 
	}

	color[u] = 2; 
} 

void addEdge(ll u, ll v, vector<ll> &cycles[N], vector<ll> &graph[N]) 
{ 
	graph[u].push_back(v); 
	graph[v].push_back(u); 
} 

void printCycles(ll edges, ll mark[], ll& cyclenumber, vector<ll>&cycles, vector<ll>&graph ) 
{ 

	
	for (int i = 1; i <= edges; i++) { 
		if (mark[i] != 0) 
			cycles[mark[i]].push_back(i); 
	} 

	bool pp;

	for (int i = 1; i <= cyclenumber; i++) 
	{ 
		//cout << "Cycle Number " << i << ": "; 
		if ( cycles[i].size() %2 ==1 )
			pp = true; 
	
	}

	if(pp)
		cout<<"party pooper\n";
	else
		cout<<"no party pooper\n";



} 

int main() 
{ 



	long long int t;
	cin>>t;
	while(t--)
	{
		vector<ll> graph[N]; 
		vector<ll> cycles[N]; 

		long long int n,m;
		cin>>n>>m;
		for (long long int i = 0; i < m/2; i++)
		{
			long long int a,b;
			cin>>a>>b;
			addEdge(a,b,cycles,graph);
		}
		int color[N]; 
		int par[N]; 

		int mark[N]; 

		int cyclenumber = 0; 
		int edges = 13; 

		dfs_cycle(1, 0, color, mark, par, cyclenumber,cycles,graph); 

		printCycles(edges, mark, cyclenumber,cycles,graph); 
		
		for(ll i = 0; i < N ;i++)
		{
			cycles[i].clear();
			graph[i].clear();	

		}	
		
		
	

	}
	// add edges 
	

	// arrays required to color the 

} 


// 2
// 3 6
// 1 2
// 2 3
// 1 3
// 3 6
// 1 2
// 2 3
// 1 3