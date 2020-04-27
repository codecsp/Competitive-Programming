// we cant store big factorials in integer range even in long long int

#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long int ll;

void multiply(ll * a, ll &n, ll num)
{
	ll carry = 0;
	for (ll i = 0; i < n; i++)
	{
		ll mult  = a[i] * num + carry;
		ll lastdig = mult % 10;
		a[i] = lastdig;
		carry = mult /= 10;
	}

	while (carry)
	{
		ll last = carry % 10;
		a[n] = last;
		carry /= 10;
		n++;
	}


}


void bigFact(ll num)
{
	ll *a = new ll[1000] ;

	for (ll i = 0; i < 1000; i++) // keeping default value 0 in a array
	{
		a[i] = 0;
	}

	a[0] = 1;

	ll n = 1;
	for (ll i = 2; i <= num; i++)
	{
		multiply(a, n, i);
	}

	for (ll i = n - 1; i >= 0; i--)
		cout << a[i] ;

}

int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	cin >> t;
	while (t--)
	{

		ll n;
		cin >> n; //taking input

		bigFact(n);
		cout << endl;

	}



	return 0 ;
}
