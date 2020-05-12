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
		ll n;
		cin >> n;

		ll arr[n];
		for (ll i = 0; i < n; i++)
			cin >> arr[i];

		// if no pair with distance <3 then 1 1

		ll local = 1;
		ll maxi = INT_MIN ;



		for (ll i = 1; i < n; i++)
		{
			if ( (arr[i] - arr[i - 1]) < 3)
				local++;
			else
			{
				maxi = max(maxi, local);
				local = 1;
			}
		}


		maxi = max(maxi, local);


		local = 1;
		ll mini = INT_MAX ;

		for (ll i = 1; i < n; i++)
		{
			if ( (arr[i] - arr[i - 1]) < 3)
				local++;
			else
			{
				mini = min(mini, local);
				local = 1;
			}
		}

		mini = min(mini, local);


		cout << mini << " " << maxi << endl;




	}

	return 0 ;
}
