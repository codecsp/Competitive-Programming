/*
problem from codechef:

https://www.codechef.com/problems/GRAYSC#

solution : n is 64 bt integer so if n = 130 and there will be 65 pairs of consective numbers,
there will be at least
2 numbers whose set bit will clash with each other.  --- > due to pigeonhole principle.



*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	ll n;
	cin>>n;
	std::vector<ll> arr(n,0);
	
	for (ll i = 0; i < n; ++i)
		cin>>arr[i];
	if(n>130)
		cout<<"Yes\n";
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = i+1; j < n; ++j)
			{
				for (int k = j=1; k < n; ++k)
				{
					for (int l = k+1; l < n; ++l)
					{
						if(arr[i]^arr[j]^arr[k]^arr[l] == 0)
						{
							cout<<"Yes\n";
							return 0 ;
						}
					}
				}
			}
		}

	}
	return 0;
}