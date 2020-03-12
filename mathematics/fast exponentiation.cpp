/*

Given a and n you have to compute pow(a,n) in efficient manner
Time complexity : O(log2(n))

Solution : power(2,6) = power(2^2, 3) = power(16,1)* 4 .. likewise

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll power(ll a, ll n)
{
	if(n == 0)
			return 1;

	ll smallValue = power(a,n/2);
	smallValue =  smallValue* smallValue ;

	if(n&1)
		smallValue = smallValue*a;

	return smallValue;
}

int main()
{
	int a, n;
	cout<<"Enter value of a and n : " ;
	cin>>a>>n;

	ll ans = power(a,n);
	cout<<"using fast exponentiation , pow(a,n)= "<<ans<<endl;

	return 0;
}