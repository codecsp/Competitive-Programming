#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1000000007;
//ll dp[1000005];

int main()
{
	ll t;
	cin>>t;
	

	while(t--)
	{
		ll n;
		cin>>n;

		ll arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n,greater<int>());
		//cout<<arr[n-1]<<endl;

		ll ans = 0;
		for(ll i=0;i<n;i++)
		{
			ll tmp =  arr[i]-i;
			if(tmp>0)
				ans = (ans%mod+tmp%mod)%mod ;
			else
				continue;
		}
		cout<<ans<<endl;

	}
	return 0;
}