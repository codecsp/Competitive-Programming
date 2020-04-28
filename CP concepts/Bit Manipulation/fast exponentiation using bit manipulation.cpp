/*
given two integers a and n find pow(a,n) fast exponentiation using bitmasking
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll fastPower(ll a, ll n)
{
	ll ans = 1;
	while(n>0)
	{
		if( (n&1) == 1)
		{
			ans *= a;    //ans: a,a*a, a*a*a*a, & so on 
		}
		a = a * a;
		n = n>>1;

	}

	return ans ;
}


int main()
{
	ll a,n;
	cout<<"enter two nos (a and n) : ";
	cin>>a>>n;

	cout<<"value of power is : "<<fastPower(a,n)<<endl;

	return 0;
}
