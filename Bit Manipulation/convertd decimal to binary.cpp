/*
given a integer find the binary representation of the same
*/

// Solution logic : 

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


ll convertToBinary(ll n)
{
	ll ans = 0 ;
	ll p = 1;
	while(n > 0)
	{
		ans +=   (n &1 ) * p;
		n = n>>1;
		p = p*10 ;
	}

	return ans ;

}

int main()
{
	ll n ;
	cout<<"Enter a number : ";
	cin>>n;


	cout<<"Binary representation of "<<n<<"  is  "<<convertToBinary(n)<<endl;
	
	return 0;
}
