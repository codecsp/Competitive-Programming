#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;


ll nextPowerOf2(ll n) 
{ 
	ll count = 0; 
	
	if (n && !(n & (n - 1))) 
		return n; 
	
	while( n != 0) 
	{ 
		n >>= 1; 
		count += 1; 
	} 
	//cout<<"dede" ;
	return 1 << count; 
} 

int main() 
{ 

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;

		ll P;
		ll sss = log2(n);
		//unsigned int n = 16; 
		if( pow(2,sss) == n )
	      P = pow(2,1+sss);
	  	else
	      P = nextPowerOf2(n) ;//<<"\n";
	  	
	  //	cout<<"P = "<<P<<endl ;
	  	
	  	ll M = (P-1)-n ;
	  	//M = M*2;

	  	ll ans = (P-1)-(M*2); 
	  	cout<<ans<<"\n";
	}


	return 0; 
} 
