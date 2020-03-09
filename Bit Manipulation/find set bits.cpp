/*
given a integer find the number of set bits in it


*/

// Solution logic : 

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Method 1 : O(log(N))

ll CountSetBits(int n)
{
	ll ans=0;
	while(n>0)
	{
		ans += n&1 ;
		n = n>>1;
	}
	return ans ;
}

// Method 2 : O(no of set  bits)

ll countbitsFaster(int n)
{
	ll ans=0;
	while(n>0)
	{
		n = n & (n-1);    // n & (n -1) actually remove the last set bit
		ans+=1;
	}
	return ans;
}

// Method 3 : Library function


int main()
{
	int n ;
	cout<<"Enter a number : ";
	cin>>n;


	cout<<"TOtal set bits in n =  "<<n<<"   are  "<<CountSetBits(n)<<endl;
	cout<<"TOtal set bits in n  using faster method =  "<<n<<"   are  "<<countbitsFaster(n)<<endl;
	cout<<"TOtal set bits in n using library method=  "<<n<<"   are  "<<__builtin_popcount(n)<<endl;

	//cout<<(3|5)<<endl;

	return 0;
}
