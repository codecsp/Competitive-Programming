#include<bits/stdc++.h>
using namespace std;

class Edge
{
public:
	
	int src;
	int dest;
	int weight;


};
bool comp(Edge a, Edge b)
{
	return a.weight < b.weight ;
}
 // union rank and compression algorithm
class Set{

	public:

		int rank;
		int parent;
};

int find(Set *set, int i)
{
	if(set[i].parent != i)
	{
		 set[i].parent = find(set,set[i].parent);
	}
	return set[i].parent;

}

void Union(Set *set,int v1, int v2)
{
	int v1_root  = find(set,v1);
	int v2_root  = find(set,v2);

	if(set[v1_root].rank < set[v2_root].rank)
	{
		set[v1_root].parent = v2_root ;
	}
	else if(set[v1_root].rank > set[v2_root].rank)
	{
		set[v2_root].parent = v1_root;
	} 
	else
	{
		set[v2_root].parent = v1_root;		
		set[v1_root].rank++;
	}

}


void kruskals(Edge *input,int n,int e)
{
	sort(input,input+e,comp);
	Edge *output = new Edge[n-1];
	
	Set *set = new Set[n];

	for(int i = 0 ; i < n ; i++)
	{
		set[i].parent = i ;
		set[i].rank  = 0  ;
	}

 	int i=0;int counter=0;
	while(counter<n-1)
	{
		int src  = input[i].src  ;
		int dest = input[i].dest ;
		int root_src = find(set,src);
		int root_dest = find(set,dest);

		if(root_src != root_dest)
		{
			output[counter] = input[i];
			Union(set,root_src,root_dest);
			counter++;
		}

		i++;

	}
	int ans = 0;
	for(int i=0;i<n-1; i++)
	{
		ans+=output[i].weight;
		//cout<<output[i].src<<"-->"<<output[i].dest<<"-->"<<output[i].weight<<endl;
	}
	cout<<ans<<endl;
}	

int main()
{
	int n,e;
	cin>>n>>e;

	Edge *input = new Edge[e];

	for(int i=0;i<e;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		input[i].src = s;
		input[i].dest = d;
		input[i].weight = w;
	}

	kruskals(input,n,e);

	//cout<<"HELLO SOHAM";
}