
// incomplete solution
// coudnt come with solution

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

	   ios_base::sync_with_stdio(false);
	   cin.tie(NULL);
	   ll t;
	   cin>>t;
	   
	   while(t--)
	   {
	   		ll n,k,p;
	   		cin >> n >> k >>p ;

	   		ll ans = INT_MIN ;

	   		std::vector<ll> arr[n];

	   		for (ll i = 0; i < n; ++i)
	   		{
	   			for (ll j = 0; j < k; ++j)
	   			{
	   				ll tmp;
	   				cin>>tmp;
	   				arr[i].push_back(tmp);
	   			}
	   		

	   		}

	   }


	return 0;
}

