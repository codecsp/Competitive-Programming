//large a  and b value like a = 10^10 , b = 10^10 + 10000
//used when diff is small in array range

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a,b;
ll squ;

void primeSieve(ll *p)
{

	//base cases
	p[0] = p[1]= 0;
	p[2] = 1;
	// mark all odd prime 
	for (ll i = 3; i<squ; i+=2)
	{
		p[i] = 1;
	}

	for (ll i = 3; i <squ; i+=2)
	{
		if(p[i]==1)
		{
			for (ll j = i*i; j <squ; j+=i)
			{
				p[j] = 0 ;
			}
		}
	}
	//p[2] = 1;
	//p[1] = p[0] = 0 ;
	return;
}

int segmented_sieve(long long a,long long b, ll *p)
{
	//sieve();
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
	return res;
}

int main()
{
	
	ll a, b;
	cin>>a>>b;
	squ = sqrt(b);
	squ++;
	squ++;
	ll array1[squ];
	primeSieve(array1);

	int ans =  segmented_sieve(a,b,array1);
	cout<<"ans is : "<<ans<<endl;

	return 0;
}


