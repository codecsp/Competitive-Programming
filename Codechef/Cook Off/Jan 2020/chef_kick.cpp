#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin >> n;
		std::vector<ll> arr(n,0);
		ll i;
		for (i = 0; i < n; i++)
			cin>>arr[i];
		sort(arr.begin(), arr.end());
		cout<<arr[0]<<endl;
	
	}	


	return 0;
}
