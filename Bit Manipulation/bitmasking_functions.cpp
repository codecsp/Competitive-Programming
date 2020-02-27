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

int main()
{

	ll n;
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

		

	return 0;
}