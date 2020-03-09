// Given a integer find whether the integer is odd or even using bitwise operator 

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool isOdd(ll n)
{
	return n&1;
}

bool getBit(ll n, ll i) // get ith bit from end ( 0 based indexing)
{

	ll mask  = 1<<i;
	if( (n&mask) > 1)
		return true;
	else
		return false;
}

ll setBit(ll n, ll i) // set ith bit from end(0 based indexing )
{
	ll mask  = 1<<i ;
	ll ans = n|mask ;

	return ans;
}

ll clearBit(ll n, ll i)
{
	ll mask = ~(1<<i);
	ll ans = n & mask;
	return ans ;
}

ll clearlastiBits(ll n, ll i)
{

	ll mask = (-1<<i);
	return n& mask;

}

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

	ll n;
	cout<<"enter a number : "<<endl;
	cin >> n;
	
	if(isOdd(n))  // last bit only decides whether a number is od or even
		cout<<n<<" is odd number.\n";
	else
		cout<<n<<" is even number.\n";

// --------------------------------------------
	cout<<"zeroth bit is "<<(n&1)<<endl; //last bit

	if (getBit(n,1))
		cout<<"first bit is "<<1<<endl;
	else
		cout<<"first bit is "<<0<<endl;


// --------------------------------------------	

	ll newNum = setBit(n,4);
	cout<<"new number after setting is : "<<newNum<<endl;

//-----------------------------------------------

	ll clearednum  = clearBit(n,1);
	cout<<"clearednum is  : "<<clearednum<<endl;


	// -----------------------------------------

  // -1= 11111111111111111 (in binary)

	ll clearedibits = clearlastiBits(n,2);
	cout<<"clearedLastIBits  is : " <<clearedibits <<endl  ;

//--------------------------------------------------------
	
// clear bits in range i to j

// 0111 in binary can be represented as (2^3)-1 ;

	ll i,j; // 0 based indexing from right	
	i = 1;
	j = 3 ;
	ll value=0;
	value = clearRangeItoJ(n,i,j);
	cout<<"after clearing from i= "<<i <<" to j = "<<j<<"  value is : "<<value<<endl;

//-----------------------------------------------------------------


	
	return 0;
}