/*
	Find the number of numbers less than n, that are divisible by all primes less than 20 

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{

	ll n;
	cin>>n;
	ll primes[]  = {2,3,5,7,11,13,17,19};

	ll primeCount = 8;

	ll ans = 0;
	
	for(ll i=1;i<= (1<<primeCount)-1 ;i++)
	{
		ll denom = 1;			//cout<<"inf loop\n";

		ll bitcount = __builtin_popcount(i);
		ll iter = 0;
		ll tmp = i;
		while(tmp>0)
		{
			ll lastbit = tmp&1;

			if(lastbit == 1)
				denom*=primes[iter];

			tmp= tmp>>1;
			iter++;
		}

		if(bitcount & 1)
		{
			ans += n/denom;
		}
		else
			ans -= n/denom;

	}

	cout<<ans<<endl;

	return 0;
}
