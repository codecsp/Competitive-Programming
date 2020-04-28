// Given a array of integers all elements occur twice except 1 element, find that element

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	std::vector<ll> arr {3, 2 ,2,4,5,7,7,4,5};

	ll ans=0;
	for(ll element : arr)
		ans^=element;

	cout<<"Single occured element is : "<<ans<<endl;


	return 0;
}