/*
multiplication of 2 matices: [][] of k order each takes O(k^3) time

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define MOD 1000000000
ll k;
std::vector<ll> b;
std::vector<ll> c;


vector<vector<ll>> mult(vector<vector<ll>> A,vector<vector<ll>> B)
{
	vector<vector<ll>> C(k+1, vector<ll>(k+1));

	for (ll i = 1; i <= k; ++i)
	{
		for (ll  j = 1; j <= k; ++j)
		{
			for(ll x=1;x<=k;x++)
			{
				C[i][j] = (C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;


			}
		}
	}
return C;
}


vector<vector<ll>> power(vector<vector<ll>> A, ll p)
{
	//base 
	if(p == 1)
		return A;
	//recursion step
	if(p&1)
	{
		return mult(A,power(A,p-1));
	}
	else
	{
		vector<vector<ll>> X = power(A,p/2); //Log(N)
		return mult(X,X);
	}


}


ll compute(ll n)
{
	 if(n<=k)   //easy task
	 	return b[n-1];
	 //it mean n>k

	 vector<ll> F1(k+1);
	 for (ll i = 1; i <= k; ++i)
	 	F1[i] = b[i-1];

	 // tansformation matrix T
	 vector<vector<ll>> T(k+1,std::vector<ll>(k+1));
	 // it is a 2d matrix where each row is a vector
	  for(ll i=1;i<=k;i++)
	  	for (ll j = 1; j <= k; ++j)
	  	{
	  		if(i<k)
	  		{
	  			if(j == i+1)
	  				T[i][j] = 1;
	  			else
	  				T[i][j] = 0;
	  			//continue;
	  		}
	  		else //last row
	  		{
	  			T[i][j] = c[k-j];
	  		}

	  	}
	  	
	  	// third step : computing T^n-1
	  	T = power(T,n-1);

	  	//MULTIPLY BY F1
	  	ll ans = 0;
	  	for (ll i = 1; i <= k; ++i)
	  	{
	  		ans=(ans+(T[1][i]* F1[i])%MOD )%MOD;
	  	}
		
		return ans;
}

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		
		cin>>k;
		for (ll i = 0; i < k; ++i)
		{
			ll tmp;
			cin>>tmp;
			b.push_back(tmp);
		}
			
		for (ll i = 0; i < k; ++i)
		{
			ll tmp;
			cin>>tmp;
			c.push_back(tmp);
		}

		ll n;
		cin>>n;
		cout<<compute(n)<<"\n";
		b.clear();
		c.clear();

	}
	return 0;

}