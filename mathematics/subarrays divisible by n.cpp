/*
	Pigeon hole principle: ig there are n+1 pigeons and n holes
	then there is at least 1 hole will have 2 pigeons

Brute force : O(N^2) --> finding all subarrays and then takung
						 sum to determine.

Efficient appproach :

	Given an array of n elemets find no of subaarays where sum 
	of array elements is divisible by n


Basically we eneed to find: (a-b)%n = 0  =>a%n = b%n

step1 : find commulative sum array where each element mod 5.
step2 : find the frequency of commulatve sum array.
step3 : for each freq >=2 Find fC2 and add to determine
		no of subarrays.
*/

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
		cin>>n;

		ll arr[n];
		for (ll i = 0; i < n; ++i)
			cin>>arr[i];

		ll prefix[n] ; // our prefix array will be frequency array
		// we are creating frequency array directly without prefix array
		
		memset(prefix,0,sizeof(prefix));
		prefix[0] = 1 ;
		ll sum = 0 ;
		for(ll i=0 ; i<n ; i++)
		{
			sum+=arr[i];
			sum = sum%n;
			sum =(sum+n)%n;  // elemenrs can be negative as well so this step

			prefix[sum]++;
		}
		ll ans = 0;
		for (ll i = 0; i < n; ++i)
		{
			ll val = prefix[i];

			 ans+=(val*(val-1))/ 2;
		}

		cout<<ans<<endl;

	}
	return 0;
}
		