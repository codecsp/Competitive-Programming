#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{

		ll n,q;
		cin>>n>>q;
		ll ans = 0;
		ll curr = 0;
		while(q--)
		{
			ll a, b;
			cin>>a>>b;

			ans += abs(a-curr);
			curr = a;
			ans += abs(b-a);
			curr  = b ;

		}
		cout<<ans<<endl;

	}

	return 0;
}