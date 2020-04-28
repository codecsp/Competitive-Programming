/*
given two integers and the value of i and j. fit the number m from i to j

Ex: n = 10000000000;
	m = 10101;
	i=2, j= 6 ;

	o/p : 10001010100

*/

 // Solution logic : firstly remove all the bits and then just take Or with m 

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll clearRangeItoJ(ll n, ll i, ll j)
{
	ll ones = ~0;
	ll a = ones <<(j+1) ;
	ll b = (1<<i) - 1;
	ll mask  = a | b;
	ll ans = n & mask;

	return ans;

}

int main()
{
	int n,m;
	n = 15;
	m = 2 ;

	int i = 1;
	int j = 3;

	m= m<<i;
	n = clearRangeItoJ(n,i,j);
	n = n| m ;

	cout<<"value of n after replacing is : "<<n<<endl;

	//cout<<(3|5)<<endl;

	return 0;
}
