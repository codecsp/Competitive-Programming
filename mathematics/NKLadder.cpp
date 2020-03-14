/*

	Given n numnber of steps and maximum steps of height k steps is given, you have to find total number of 
	ways possible to climb the n steps.


This can be done in 3 methods
1. Recursion : O(k^n)
2. DP : O(n*k)  --> this can be further reduced
3. Exponentiation : O(K^3* n)

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{

	ll steps, maxstep;
	cin>>steps>>maxstep;

	ll dp[steps]={0};
	dp[0] = 1 ;
	dp[1] = 1 ;
	dp[2] = 2 ;

	for(ll i=3;i<=steps;i++)
	{
		ll ans2, ans1;
		ll ind = (i-(maxstep+1));
		if(i-1 >=0)
			ans1=2*dp[i-1];   // we have to delete  the start and ad the last elementof k elements
		else
			ans1 = 0;
		if( i-(maxstep+1) >=0 )
			ans2=dp[ind];
		else
			ans2 = 0;

		dp[i] = ans1-ans2 ;  // to reduce O(N*K) to O(N)
	}

	cout<<dp[steps]<<endl;
	return 0;
}