#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;


int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t ;
	while (t--)
	{
		ll n, q;
		cin >> n >> q;

		string s;
		cin >> s;
		std::map<char, ll> freq;
		for (char c : s)
		{
			freq[c] += 1 ;
		}
		while (q--)
		{
			ll query;
			cin >> query;
			ll ans = 0;
			for (ll i = 97; i <= 122; i++)
			{
				char ch = i ;
				if (freq[ch] > query)
				{
					ans += freq[ch] - query;
				}
			}
			cout << ans << endl;
		}
	}

	return 0 ;
}
