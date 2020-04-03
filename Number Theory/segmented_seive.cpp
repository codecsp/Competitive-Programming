//large a  and b value

//used when diff is small in array range

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b;

void sieve()  //fidning (b)^0.5
{
	p[0] = p[1]= 0;
	p[2] = 1;
	// mark all odd prime 
	for (ll i = 3; i<100000; i+=2)
	{
		p[i] = 1;
	}

	for (ll i = 3; i < 100000; i+=2)
	{
		if(p[i]==1)
		{
			for (ll j = i*i; j < 100000; j+=i)
			{
				p[j] = 0 ;
			}
		}
	}
}

int segmented_sieve(long long a,long long b)
{
	sieve();
	bool pp[b-a+1];
	memset(pp,1,sizeof(pp));

	for (ll i = 2; i*i <= b; ++i)
	{
			for (ll j = a; j <= b; ++j)
			{
				if(p[i])
				{
					if(j == i)
						continue;
					if(j%i == 0)
						pp[j-a] = 0;
				}
			}
	}

	int res = 1;
	for(ll i = a;i<b;i++)
	{
		res+= pp[i-a];
	}
	return ;
}

int main()
{
	

	return 0;
}


