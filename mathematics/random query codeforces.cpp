/*
Codeforces problem : Random query https://codeforces.com/problemset/problem/846/F

Solution : Expected number concept


*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	
	ll n;
	cin>>n;

	std::vector<ll> arr(n+1,0);
	std::vector<ll> lastOccur(1000006,0);
	std::vector<ll> ansArray(n+1,0);
	ll sum = 0;


	
	for (ll i = 1; i <= n; ++i)
	{
		cin>>arr[i];
		ansArray[i] = ansArray[i-1]+ (i- lastOccur[arr[i]]) ;

		lastOccur[arr[i]] = i;

		sum += ansArray[i];
	}


	//cout<<"sum : "<<sum<<endl;

	long double ans =  ((2*(sum-n))+n)/(n*n*1.0) ;

//	cout<<"ans : "<<ans<<endl;

	cout<<fixed<<setprecision(6)<<ans<<endl;

	return 0;

}

