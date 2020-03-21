//100% working
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

typedef long long int ll;

int main()
{
		ll t;
		cin>>t;
		while(t--)
		{
			ll n,b,a;
			cin>>n>>a>>b;
			vector<ll> arr(n,0);
			for(ll i=0;i<n;i++)
				cin>>arr[n];
			std::vector<ll> alice;
			std::vector<ll> bob;
			for(ll i=0;i<n;i++)
			{
				if(arr[i]%b==0)
					alice.push_back(arr[i])   ;
				if(arr[i]%a==0)
					bob.push_back(arr[i]) ;
			}

			for(ll i=0;i<alice.size();i++)
				cout<<alice[i]<<" ";
			cout<<"\n";
			for(ll i=0;i<bob.size();i++)
				cout<<bob[i]<<" ";
			cout<<"\n";
			


		}
}