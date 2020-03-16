/* 
	similar to counting number of nodes in a tree
*/

#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

const int NN = 1e5 + 2;

vector<int> adj[NN];
vector<int> w[NN];

//Count the number of nodes rechable from i-th node
//Initially all count is 1
int cnt[100000+10];
//Specifies whether the node has been visited or not in dfs
bool vis[100000+10];

int n;

//Dfs is used to calculate the count of
//number of nodes rechable from each node.

void dfs(int v)
{
//Mark the node visited
vis[v] = 1;
//Iterate for all the adjacent nodes of the
//current node 'v'
	for(int i = 0 ; i < adj[v].size() ;  i++)
	{
		//find the i-th adjacent node 'u'
		int u = adj[v][i];
		//If the node is already visited
		//do not visit again
		if(vis[u])
			continue;
		//If the node has not neen visited
		//visit this node
		dfs(u);
		//calculate the count of current node v
		//by adding count of all its adjacent nodes
		cnt[v] += cnt[u];
	}
	return ; 
 }

//this function calculates the final answer
long long sol(int v)
{
	vis[v] = 1;
	long long res = 0;
	for(int i = 0;i<adj[v].size();i++)
	{
		int u = adj[v][i];
		if(vis[u])
			continue;
	//find the minimum number of person that can be shifted
	//through ith edge of 'v' i.e. v--u with weight w[v][i]
		res += min(cnt[u],n - cnt[u]) * 2ll * w[v][i] + sol(u);
	}
	return res;
}

int main()
{
	int t,a,x,y,in = 1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 0;i<=n;i++)
		{
			adj[i].clear();
			w[i].clear();
			cnt[i] = 1;
			vis[i] = 0;
		}
		for(int i = 0;i<n-1;i++)
		{
			scanf("%d %d %d",&x,&y,&a);
			--x;
			--y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			w[x].push_back(a);
			w[y].push_back(a);
		}

		dfs(0) ;
		memset(vis,0,sizeof vis);
		printf("Case #%d: %lld\n",in,sol(0));
		++in;
	}
	return 0;
}