#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll nextPerfectCube(ll N) 
{ 
    ll nextN = floor(cbrt(N)) + 1; 
  
    return nextN * nextN * nextN; 
} 

ll lastPerfectCube(ll n)
{
	ll nextN = floor(cbrt(n)); 
  
    return nextN * nextN * nextN; 

}


int main()
{

	   ios_base::sync_with_stdio(false);
	   cin.tie(NULL);

	long long int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll aa = nextPerfectCube(n) ;
		ll bb = lastPerfectCube(n) ;

		if(abs(aa-n) < abs(bb-n))
		    cout<<aa<<endl;
		else
		    cout<<bb<<endl;
	}	
	return 0;
}


// 2
// 3 6
// 1 2 2 3 1 3
// 3 6
// 1 2 2 3 1 3