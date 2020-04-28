/*
Given a array of integers containing one 
unique no occuring only once and the rest ocuureing twice.
thrice , find in constant space.
*/
 
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
	int n;
	cout<<"enter size : ";
	cin>>n;
	std::vector<int> arr(n,0);
	std::vector<int> cntarray(64,0);
	cout<<"Enter elements : ";
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		int j=0;
		while(arr[i] > 0 )
		{
			int lastbit = arr[i]&1 ;
			cntarray[j] += lastbit;
			j++;
			arr[i] = arr[i]>>1 ;
		}
	}

	ll ans = 0 ;
	for (int i = 0; i < 64; ++i)
	{
		if(cntarray[i] % 3 == 1)
			ans+=pow(2,i);
	}

	cout<<"\nTwo unique number is  : "<<ans<<endl;

	return 0;
}
