// Got AC

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;



int main()
{

	   ios_base::sync_with_stdio(false);
	   cin.tie(NULL);
	   ll t;
	   cin>>t;
	   int it = 1;
	   while(t--)
	   {
	   	ll n,b;
	   	cin>>n>>b;

	   	ll arr[n];
	   	for (ll i = 0; i < n; ++i)
	   	{
	   		cin>>arr[i];
	   	}
	   	sort(arr,arr+n);

	   	ll sum = 0;
	   	ll ans = 0;
	   	for (ll i = 0; i < n; ++i)
	   	{
	   		/* code */
	   		if(sum+arr[i] <=b)
	   		{
	   			sum +=arr[i];
	   			ans++;
	   		}
	   	}
	   	cout<<"Case #"<< it<<": "<<ans<<endl;
        it++;

	   }
	   

	return 0;
}


// 2
// 3 6
// 1 2 2 3 1 3
// 3 6
// 1 2 2 3 1 3